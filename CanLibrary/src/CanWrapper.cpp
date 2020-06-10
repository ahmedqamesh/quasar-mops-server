/*
 * CanWrapper.cpp
 *
 *  Created on: Jun 8, 2020
 *      Author: dcs
 */
#include <string.h>
#include <iostream>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>
#include <net/if.h>
#include <linux/can.h> // includes The basic CAN frame structure and the sockaddr structure
#include <linux/can/raw.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <assert.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <signal.h>
#include <linux/can/error.h>
#include <sys/time.h>
#include <sys/select.h>
#include "CanWrapper.h"
#define INVALID_SOCKET -1
namespace CanLibrary {
static bool m_initialized; // indicates if socket is initialized
static int m_socket ;     // Socket
CanWrapper::CanWrapper() {
	m_initialized = false;
	m_socket = INVALID_SOCKET;
}
// Initialize socket. Returns false if socket could not be opened.
// Parameters:
// interfaceName - the name of the CAN interface to open (can0, can1...)
// errorCode - error code indicating why init did fail
bool CanWrapper::openPort(const char *interfaceName, int &errorCode) {
	struct sockaddr_can addr;
	struct ifreq ifr;
	int ret;

	errorCode = 0;
	//printf("Opening an empty socket API socket with PF_CAN as the protocol family\n");
	m_socket = socket(PF_CAN, SOCK_RAW, CAN_RAW);

	// Get index for a certain name
	strcpy(ifr.ifr_name, interfaceName);
	ret = ioctl(m_socket, SIOCGIFINDEX, &ifr);
	if (ret) {
		errorCode = errno;
		return false;
	}
	//printf("Binding the socket %s to all CAN interfaces\n", interfaceName);
	addr.can_family = AF_CAN;
	addr.can_ifindex = ifr.ifr_ifindex;

	ret = bind(m_socket, (struct sockaddr *) &addr, sizeof(addr));
	if (ret) {
		errorCode = errno;

		close(m_socket);
		m_socket = INVALID_SOCKET;

		return false;
	}

	m_initialized = true;

	return true;
}

// Close an open connection. Use when changing can net.
void CanWrapper::closePort() {
	printf("Closing the connection \n");
	int m_socket = INVALID_SOCKET;
	//bool m_initialized = INITIALIZE_SOCKET;
	if (m_initialized) {
		// We don't want to read or write anything more
		shutdown(m_socket, SHUT_RDWR);

		close(m_socket);

		m_socket = INVALID_SOCKET;

		m_initialized = false;
	}
}

// Send a message on the CAN-bus. Returns true if ok, false if not. Additional error info can be found in errorCode.
// Parameters:
// msg - the can message to send
// extended - set to true to send an extended frame
// rtr - set to true to send a remot request (rtr)
// errorcode - will be set to an error code
// Common errors:
//#define ENETDOWN        100     /* Network is down - use ifconfig up to start */
//#define EAGAIN          11      /* Try again - buffer is full */
//#define EBADF            9      /* Bad file number - can net not opened */
bool CanWrapper::writeCanMessage(int cobid, int msg [], int dlc, bool extended, bool rtr_frame,
		int &errorCode) {
	//printf("Writing CAN frames.... \n");
	struct can_frame frame;
	frame.can_dlc = dlc; // Set data length
	frame.can_id = cobid; // Set id
	//struct ifreq ifr;
	// Set data elements
	frame.data[0] = msg[0];
	frame.data[1] = msg[1];
	frame.data[2] = msg[2];
	frame.data[3] = msg[3];
	frame.data[4] = msg[4];
	frame.data[5] = msg[5];
	int retval;
	errorCode = 0;

	if (!m_initialized)
		return false;

	if (extended) {
		frame.can_id |= CAN_EFF_FLAG;
	}

	if (rtr_frame) {
		frame.can_id |= CAN_RTR_FLAG;
	}
	//printf("Received a CAN frame from interface %s\n", ifr.ifr_name);
	retval = write(m_socket, &frame, sizeof(struct can_frame));

	if (retval < 0) {
		//perror("could not send");
		//printf("errno is %d\r\n", errno);
		errorCode = errno;

		return false;
	}

	return true;
}
// Get a CAN message. If socket is blocking (default) - this call will block until data is received or until timeout period has expired.
// If socket is non blocking, it will return false if there is no data or if there is any error.
// If socket is blocking, it will return false if there is an error or at timeout.
// Parameters:
// frame - the received can frame
// extended - will be set to true if the received frame was an extended frame
// rtr - will be set to true if the received frame was an rtr frame
// errorcode - error code
// Common errors:
//#define ENETDOWN        100     /* Network is down - use ifconfig up to start*/
//#define EAGAIN          11      /* Try again - no data available*/
//#define EBADF            9      /* Bad file number - can net not opened */
// timeout - GetMsg will return false after timeout period
bool CanWrapper::readCanMessages(bool &extended, bool &rtr_frame, bool &messageValid,
		int &errorCode, struct timeval timeout) {
	//printf("Reading CAN frames.... \n");
	struct can_frame frame;
	int bytesRead;
	int ret;
	fd_set rfds;
	errorCode = 0;

	if (!m_initialized) {
		return false;
	}

	// Set up a file descriptor set only containing one socket
	FD_ZERO(&rfds);
	FD_SET(m_socket, &rfds);

	// Use select to be able to use a timeout
	ret = select(m_socket + 1, &rfds, NULL, NULL, &timeout);
	if (ret < 0) {
		errorCode = errno;

		return false;
	}

	if (ret > 0) {
		bytesRead = read(m_socket, &frame, sizeof(frame));
		if (bytesRead < 0) {
			errorCode = errno;
			return false;
		}

		if (bytesRead == sizeof(frame)) {
			error = frame.can_id & CAN_ERR_FLAG;
			extended = frame.can_id & CAN_EFF_FLAG;
			rtr_frame = frame.can_id & CAN_RTR_FLAG;
			if (error) { // Error frame
				frame.can_id &= CAN_ERR_MASK;
				printf("Error frame received, class = %d\n", frame.can_id);
			} else if (extended) { // Extended frame
				frame.can_id &= CAN_EFF_MASK;
				printf("Extended Frame msg........\n");
				if (rtr_frame) {
					printf("RTR ID: %d LENGTH: %d\n", frame.can_id,
							frame.can_dlc);
				} else {
					printf("ID: %d LENGTH: %d  DATA:\n", frame.can_id,
							frame.can_dlc);
					for (int i = 0; i <= frame.can_dlc; i++) {
						printf(" DATA[%i]:%i\n", i, frame.data[i]);
					}
				}
			} else { // Standard frame
				frame.can_id &= CAN_SFF_MASK;
				printf("Standard Frame msg........\n");
				if (rtr_frame) {
					printf("RTR ID: %d LENGTH: %d\n", frame.can_id,
							frame.can_dlc);
				} else {
					printf("ID: %d LENGTH: %d  DATA:\n", frame.can_id,
							frame.can_dlc);
					for (int i = 0; i <= frame.can_dlc; i++) {
						printf(" DATA[%i]:%i\n", i, frame.data[i]);
					}
				}
			}
			return true;
		}
	}

	return false;
}
// Set size of receive buffer. The standard size is usually large enough.
// Note that getsockopt will return twice the size set
// If settings a larger size than the system supports, the size will set to a lower value than requested
// Parameters:
// size - the requested size of the receive buffer
bool CanWrapper::setRecvBufferSize(int size) {
	int ret;
	int rcvbuf_size = size;
	int m_socket = INVALID_SOCKET;
//    int rbuf;
//    int len = sizeof(int);

// Print receive buf size before change
//    ret = getsockopt(m_socket,SOL_SOCKET,SO_RCVBUF,&rbuf,(socklen_t*)&len);
//    printf("receive buf size is before change: %d\r\n", rbuf);

	ret = setsockopt(m_socket, SOL_SOCKET, SO_RCVBUF, &rcvbuf_size,
			sizeof(rcvbuf_size));
	if (ret < 0) {
		//      perror("set recv buffer size");
		//      printf("errno is %d\r\n", errno);

		return false;
	}

	// Print receive buf size after change
//    ret = getsockopt(m_socket,SOL_SOCKET,SO_RCVBUF,&rbuf,(socklen_t*)&len);
//    printf("receive buf size is after change: %d\r\n", rbuf);

	return true;
}

// Configure the socket can layer to report errors
// see /linux/can/error.h for more options regading error handling (not implemented in this class).

void CanWrapper::enableErrorMessages() {
	int ret;
	int m_socket = INVALID_SOCKET;
	can_err_mask_t err_mask = ( CAN_ERR_TX_TIMEOUT | CAN_ERR_BUSOFF);

	ret = setsockopt(m_socket, SOL_CAN_RAW, CAN_RAW_ERR_FILTER, &err_mask,
			sizeof(err_mask));
	if (ret > 0) printf("errno is %d\r\n", ret);

}
} /* namespace CanLibrary */
