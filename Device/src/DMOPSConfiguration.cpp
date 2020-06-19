
/*  © Copyright CERN, 2015. All rights not expressly granted are reserved.
        
    The stub of this file was generated by Quasar (additional info: using transform designToDeviceBody.xslt) 
    on 2020-05-06T15:56:11.62+02:00
    
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

#include <DMOPSConfiguration.h>
#include <ASMOPSConfiguration.h>
#include "CanWrapper.h"




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
  DMOPSConfiguration::DMOPSConfiguration (const Configuration::
					  MOPSConfiguration & config,
					  Parent_DMOPSConfiguration *
					  parent):Base_DMOPSConfiguration
    (config, parent)
    /* fill up constructor initialization list here */
  {
    /* fill up constructor body here */
  }

  /* sample dtr */
  DMOPSConfiguration::~DMOPSConfiguration ()
  {
  }

  /* delegators for cachevariables and externalvariables */


  // 3333333333333333333333333333333333333333333333333333333333333333333333333
  // 3     FULLY CUSTOM CODE STARTS HERE                                     3
  // 3     Below you put bodies for custom methods defined for this class.   3
  // 3     You can do whatever you want, but please be decent.               3
  // 3333333333333333333333333333333333333333333333333333333333333333333333333
  void DMOPSConfiguration::updateMopsConfiguration(int nodeId, struct timeval timeout, int dlc){
		bool adcTrimmingBits = false;
		adcTrimmingBits = CanLibrary::CanWrapper::sdoRead(nodeId, 0x2001, 0, timeout, dlc);
		if (adcTrimmingBits) {
			int adcTrimmingBits_value = CanLibrary::CanWrapper::getSdoData();
			getAddressSpaceLink()->setADCTrimmingBits(adcTrimmingBits_value, OpcUa_Good);
		}
	  getAddressSpaceLink()->setReadFEMonitoringValues(rand(), OpcUa_Good);
  }

}
