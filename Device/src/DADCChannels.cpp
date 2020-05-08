
/*  © Copyright CERN, 2015. All rights not expressly granted are reserved.
        
    The stub of this file was generated by Quasar (additional info: using transform designToDeviceBody.xslt) 
    on 2020-05-06T13:02:27.638+02:00
    
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

#include <DADCChannels.h>
#include <ASADCChannels.h>





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
  DADCChannels::DADCChannels (const Configuration::ADCChannels & config,
			      Parent_DADCChannels *
			      parent):Base_DADCChannels (config, parent)
    /* fill up constructor initialization list here */
  {
    /* fill up constructor body here */
  }

  /* sample dtr */
  DADCChannels::~DADCChannels ()
  {
  }

  /* delegators for cachevariables and externalvariables */


  // 3333333333333333333333333333333333333333333333333333333333333333333333333
  // 3     FULLY CUSTOM CODE STARTS HERE                                     3
  // 3     Below you put bodies for custom methods defined for this class.   3
  // 3     You can do whatever you want, but please be decent.               3
  // 3333333333333333333333333333333333333333333333333333333333333333333333333
  void DADCChannels::update(){
	  //send data from server to client
	getAddressSpaceLink()->setCh4(rand(), OpcUa_Good);
	getAddressSpaceLink()->setCh5(rand(), OpcUa_Good);
	getAddressSpaceLink()->setCh6(rand(), OpcUa_Good);
	getAddressSpaceLink()->setCh7(rand(), OpcUa_Good);
	getAddressSpaceLink()->setCh8(rand(), OpcUa_Good);
	getAddressSpaceLink()->setCh9(rand(), OpcUa_Good);
	getAddressSpaceLink()->setCh10(rand(), OpcUa_Good);
	getAddressSpaceLink()->setCh11(rand(), OpcUa_Good);
	getAddressSpaceLink()->setCh12(rand(), OpcUa_Good);
	getAddressSpaceLink()->setCh13(rand(), OpcUa_Good);
	getAddressSpaceLink()->setCh14(rand(), OpcUa_Good);
	getAddressSpaceLink()->setCh15(rand(), OpcUa_Good);
	getAddressSpaceLink()->setCh16(rand(), OpcUa_Good);
	getAddressSpaceLink()->setCh17(rand(), OpcUa_Good);
	getAddressSpaceLink()->setCh18(rand(), OpcUa_Good);
	getAddressSpaceLink()->setCh19(rand(), OpcUa_Good);
	getAddressSpaceLink()->setCh20(rand(), OpcUa_Good);
	getAddressSpaceLink()->setCh21(rand(), OpcUa_Good);
	getAddressSpaceLink()->setCh22(rand(), OpcUa_Good);
	getAddressSpaceLink()->setCh23(rand(), OpcUa_Good);
	getAddressSpaceLink()->setCh24(rand(), OpcUa_Good);
	getAddressSpaceLink()->setCh25(rand(), OpcUa_Good);
	getAddressSpaceLink()->setCh16(rand(), OpcUa_Good);
	getAddressSpaceLink()->setCh17(rand(), OpcUa_Good);
	getAddressSpaceLink()->setCh18(rand(), OpcUa_Good);
	getAddressSpaceLink()->setCh19(rand(), OpcUa_Good);
	getAddressSpaceLink()->setCh20(rand(), OpcUa_Good);
	getAddressSpaceLink()->setCh21(rand(), OpcUa_Good);
	getAddressSpaceLink()->setCh22(rand(), OpcUa_Good);
	getAddressSpaceLink()->setCh23(rand(), OpcUa_Good);
	getAddressSpaceLink()->setCh24(rand(), OpcUa_Good);


	// send data from client to server
	OpcUa_Double entries = getAddressSpaceLink()->getNumberOfEntries();
	LOG(Log::INF)<<"ADC channels, NumberOfEntries ="<< entries;
  }



}
