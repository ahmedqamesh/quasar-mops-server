/*
 * CanWrapper.h
 *
 *  Created on: Jun 8, 2020
 *      Author: dcs
 */

#ifndef CANLIBRARY_CANWRAPPER_H_
#define CANLIBRARY_CANWRAPPER_H_
#include <string>

namespace CanLibrary {

class CanWrapper {
public:
	CanWrapper();
	static std::string getLibraryVersion();
	 static bool openPort(const char *interfaceName, int &errorCode);

	 static void closePort();

	 static bool sendMsg(struct can_frame msg, bool extended, bool rtr, int &errorCode);

	 static bool getMsg(struct can_frame &frame, bool &extended, bool &rtr, bool &error, int &errorCode, struct timeval timeout);

	 static bool setRecvBufferSize(int size);

	 static void enableErrorMessages();

public:
    static bool m_initialized; // indicates if socket is initialized
    static int m_socket ;     // Socket

}; /*Class */

} /* namespace CanLibrary */

#endif /* CANLIBRARY_CANWRAPPER_H_ */
