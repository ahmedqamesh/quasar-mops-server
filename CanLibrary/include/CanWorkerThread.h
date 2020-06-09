/*
 * CanWorkerThread.h
 *
 *  Created on: Jun 9, 2020
 *      Author: dcs
 */

#ifndef CANLIBRARY_CANWORKERTHREAD_H_
#define CANLIBRARY_CANWORKERTHREAD_H_
#include "CanWrapper.h"
namespace CanLibrary {

class CanWorkerThread {
public:

	void init(CanWrapper *wrapper); // Initialize

	void run(int n, bool extended, bool rtr, int errorCode);         // start thread

    void shutDown();    // Make thread shut down



private:
    CanWrapper *m_can;  // Pointer to can wrapper class
    bool m_running;     // Set to false to stop thread


};

} /* namespace CanLibrary */

#endif /* CANLIBRARY_CANWORKERTHREAD_H_ */
