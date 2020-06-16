
/*  © Copyright CERN, 2015. All rights not expressly granted are reserved.
        
    The stub of this file was generated by Quasar (additional info: using transform designToDeviceHeader.xslt) 
    on 2020-05-06T15:56:11.056+02:00
    
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





#ifndef __DMOPSConfiguration__H__
#define __DMOPSConfiguration__H__

#include <vector>
#include <boost/thread/mutex.hpp>

#include <statuscode.h>
#include <uadatetime.h>
#include <session.h>


#include <DRoot.h>
#include <Configuration.hxx>

#include <Base_DMOPSConfiguration.h>


namespace Device
{




  class DMOPSConfiguration:public Base_DMOPSConfiguration
  {

  public:
    /* sample constructor */
    explicit DMOPSConfiguration (const Configuration::
				 MOPSConfiguration & config,
				 Parent_DMOPSConfiguration * parent);
    /* sample dtr */
     ~DMOPSConfiguration ();




    /* delegators for
       cachevariables and sourcevariables */


    /* delegators for methods */


  private:
    /* Delete copy constructor and assignment operator */
      DMOPSConfiguration (const DMOPSConfiguration &);
      DMOPSConfiguration & operator= (const DMOPSConfiguration & other);

    // ----------------------------------------------------------------------- *
    // -     CUSTOM CODE STARTS BELOW THIS COMMENT.                            *
    // -     Don't change this comment, otherwise merge tool may be troubled.  *
    // ----------------------------------------------------------------------- *

  public:
      void updateMopsConfiguration(int nodeId,struct timeval timeout, int dlc);
  private:


  };





}

#endif // include guard
