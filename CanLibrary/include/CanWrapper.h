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
	static bool writeCanMessage(int cobid, int msg [], int dlc, bool extended, bool rtr_frame, int &errorCode);
	static bool readCanMessages(bool &extended, bool &rtr, bool &messageValid, int &errorCode, struct timeval timeout);
	static bool setRecvBufferSize(int size);
	static void enableErrorMessages();

//private:
//    static bool m_initialized; // indicates if socket is initialized
//   static int m_socket ;     // Socket

}; /*Class */

} /* namespace CanLibrary */

#endif /* CANLIBRARY_CANWRAPPER_H_ */
