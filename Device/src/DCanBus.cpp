
/*  © Copyright CERN, 2015. All rights not expressly granted are reserved.
        
    The stub of this file was generated by Quasar (additional info: using transform designToDeviceBody.xslt) 
    on 2020-05-05T13:20:51.284+02:00
    
    Quasar is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public Licence as published by
    the Free Software Foundation, either version 3 of the Licence.
    Quasar is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public Licence for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with Quasar.  If not, see <http://www.gnu.org/licenses/>.
    
    
    
 */




#include <Configuration.hxx>

#include <DCanBus.h>
#include <ASCanBus.h>

#include <DMOPS.h>
#include <string>
#include <iostream>
using namespace std;
#include "CanWrapper.h"
#include "CanWorkerThread.h"
#include <linux/can.h>

namespace Device
{




  // 1111111111111111111111111111111111111111111111111111111111111111111111111
  // 1     GENERATED CODE STARTS HERE AND FINISHES AT SECTION 2              1
  // 1     Users don't modify this code!!!!                                  1
  // 1     If you modify this code you may start a fire or a flood somewhere,1
  // 1     and some human being may possible cease to exist. You don't want  1
  // 1     to be charged with that!                                          1 
  // 1111111111111111111111111111111111111111111111111111111111111111111111111






  // 2222222222222222222222222222222222222222222222222222222222222222222222222
  // 2     SEMI CUSTOM CODE STARTS HERE AND FINISHES AT SECTION 3            2
  // 2     (code for which only stubs were generated automatically)          2
  // 2     You should add the implementation but dont alter the headers      2
  // 2     (apart from constructor, in which you should complete initializati2
  // 2     on list)                                                          2 
  // 2222222222222222222222222222222222222222222222222222222222222222222222222

  /* sample ctr */
  DCanBus::DCanBus (const Configuration::CanBus & config,
		    Parent_DCanBus * parent):Base_DCanBus (config, parent)
    /* fill up constructor initialization list here */
  {
    /* fill up constructor body here */
	  //LOG(Log::INF)<<"Bus ID="<< config.identifier();
	  LOG(Log::INF)<<"port number="<< config.port();
  }

  /* sample dtr */
  DCanBus::~DCanBus ()
  {
  }

  /* delegators for cachevariables and externalvariables */


  // 3333333333333333333333333333333333333333333333333333333333333333333333333
  // 3     FULLY CUSTOM CODE STARTS HERE                                     3
  // 3     Below you put bodies for custom methods defined for this class.   3
  // 3     You can do whatever you want, but please be decent.               3
  // 3333333333333333333333333333333333333333333333333333333333333333333333333
  void DCanBus::update(){
	 //open canport
	struct can_frame frame;
	int errorCode;
	bool extended ;
	extended = false;
	bool rtr;
	frame.can_dlc = 8; // Set data length
	frame.can_id = 0x601; // Set id
	// Set data elements
	frame.data[0] = 64;
	frame.data[1] = 0;
	frame.data[2] = 16;
	frame.data[3] = 0;
	frame.data[4] = 0;
	frame.data[5] = 0;
	CanLibrary::CanWrapper::openPort("can"+port(), errorCode);
	CanLibrary::CanWrapper::sendMsg(frame, extended, rtr, errorCode);
	 //LOG(Log::INF)<<"port number="<< port();
  	for (DMOPS* mops : mopss())

  		mops->update();
  }



}
