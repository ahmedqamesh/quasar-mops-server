/*
 * CanWrapper.h
 *
 *  Created on: Jun 8, 2020
 *      Author: dcs
 */

#ifndef CANLIBRARY_CANWRAPPER_H_
#define CANLIBRARY_CANWRAPPER_H_
#include <string>
#include <string.h>
#include <tuple>
#include <vector>
namespace CanLibrary {

class CanWrapper {

public:
	static int  sdoData;

	CanWrapper();
	static std::string getLibraryVersion();
	static bool openPort(const char *interfaceName, int &errorCode);
	static void closePort();
	static bool writeCanMessage(int cobid, int msg [], int dlc, bool extended, bool rtr_frame, int &errorCode, struct timeval timeout);
	static std::tuple<int, std::vector<int>, int> canMsgQueue(int codid, std::vector<int> msg, int dlc);
	static bool readCanMessages(bool &extended, bool &rtr_frame, bool &error, int &errorCode, struct timeval timeout);
	static bool sdoRead( int nodeId, int index, int subindex,struct timeval timeout, int dlc);
	static bool setRecvBufferSize(int size);
	static void enableErrorMessages();
	static std::string intToHexString(int intValue);

    // Setter
	static void setSdoData(int d) { sdoData = d; }
    // Getter
	static int getSdoData() { return  sdoData;}



	//    static bool m_initialized; // indicates if socket is initialized
//   static int m_socket ;     // Socket

}; /*Class */

} /* namespace CanLibrary */

#endif /* CANLIBRARY_CANWRAPPER_H_ */
