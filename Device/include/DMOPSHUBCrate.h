
/*  © Copyright CERN, 2015. All rights not expressly granted are reserved.
        
    The stub of this file was generated by Quasar (additional info: using transform designToDeviceHeader.xslt) 
    on 2020-05-05T13:19:58.388+02:00
    
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





#ifndef __DMOPSHUBCrate__H__
#define __DMOPSHUBCrate__H__

#include <vector>
#include <boost/thread/mutex.hpp>

#include <statuscode.h>
#include <uadatetime.h>
#include <session.h>


#include <DRoot.h>
#include <Configuration.hxx>

#include <Base_DMOPSHUBCrate.h>


namespace Device
{




  class DMOPSHUBCrate:public Base_DMOPSHUBCrate
  {

  public:
    /* sample constructor */
    explicit DMOPSHUBCrate (const Configuration::MOPSHUBCrate & config,
			    Parent_DMOPSHUBCrate * parent);
    /* sample dtr */
     ~DMOPSHUBCrate ();




    /* delegators for
       cachevariables and sourcevariables */


    /* delegators for methods */


  private:
    /* Delete copy constructor and assignment operator */
      DMOPSHUBCrate (const DMOPSHUBCrate &);
      DMOPSHUBCrate & operator= (const DMOPSHUBCrate & other);

    // ----------------------------------------------------------------------- *
    // -     CUSTOM CODE STARTS BELOW THIS COMMENT.                            *
    // -     Don't change this comment, otherwise merge tool may be troubled.  *
    // ----------------------------------------------------------------------- *

  public:
      void update();
  private:


  };





}

#endif // include guard
