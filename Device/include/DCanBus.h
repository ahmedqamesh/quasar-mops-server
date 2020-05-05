
/*  © Copyright CERN, 2015. All rights not expressly granted are reserved.
        
    The stub of this file was generated by Quasar (additional info: using transform designToDeviceHeader.xslt) 
    on 2020-05-05T13:20:50.789+02:00
    
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





#ifndef __DCanBus__H__
#define __DCanBus__H__

#include <vector>
#include <boost/thread/mutex.hpp>

#include <statuscode.h>
#include <uadatetime.h>
#include <session.h>


#include <DRoot.h>
#include <Configuration.hxx>

#include <Base_DCanBus.h>


namespace Device
{




  class DCanBus:public Base_DCanBus
  {

  public:
    /* sample constructor */
    explicit DCanBus (const Configuration::CanBus & config,
		      Parent_DCanBus * parent);
    /* sample dtr */
     ~DCanBus ();




    /* delegators for
       cachevariables and sourcevariables */


    /* delegators for methods */


  private:
    /* Delete copy constructor and assignment operator */
      DCanBus (const DCanBus &);
      DCanBus & operator= (const DCanBus & other);

    // ----------------------------------------------------------------------- *
    // -     CUSTOM CODE STARTS BELOW THIS COMMENT.                            *
    // -     Don't change this comment, otherwise merge tool may be troubled.  *
    // ----------------------------------------------------------------------- *

  public:

  private:


  };





}

#endif // include guard