
/*  © Copyright CERN, 2015. All rights not expressly granted are reserved.
    Authors(from Quasar team): Piotr Nikiel

    This file is part of Quasar.

    Quasar is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public Licence as published by
    the Free Software Foundation, either version 3 of the Licence.
    Quasar is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public Licence for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with Quasar.  If not, see <http://www.gnu.org/licenses/>.

    This file was completely generated by Quasar (additional info: using transform designToDeviceBaseHeader.xslt)
    on 2018-11-09T17:06:12.851+01:00
 */



#ifndef __Base_DBuildInformation__H__
#define __Base_DBuildInformation__H__

#include <vector>
#include <string>
#include <list>


#include <DRoot.h>
#include <Configuration.hxx>

#include <opcua_platformdefs.h>

/* forward decl for AddressSpace */
namespace AddressSpace {
class
    ASBuildInformation
    ;
}
/* forward decl for Parent */


namespace Device
{


typedef struct {
    /*No exact Parent of the class*/
} Parent_DBuildInformation ;



class DBuildInformation;
/* forward declarations (comes from design.class.hasObjects) */


class
    Base_DBuildInformation
{

public:
    /* Constructor */
    explicit Base_DBuildInformation () ;

private:
    /* No copy constructors or assignment operators */
    Base_DBuildInformation (const Base_DBuildInformation & other);
    Base_DBuildInformation & operator=(const Base_DBuildInformation & other);

public:

    /* sample dtr */
    virtual ~Base_DBuildInformation ();

    Parent_DBuildInformation * getParent () const {
        return m_parent;
    }

    /* add/remove for handling device structure */


    /* to safely quit */
    unsigned int unlinkAllChildren ();


    void linkAddressSpace (AddressSpace::ASBuildInformation * as);
    AddressSpace::ASBuildInformation * getAddressSpaceLink () const {
        return m_addressSpaceLink;
    }


    /* find methods for children */


    /* getters for values which are keys */



    /* mutex operations */


    /* variable-wise locks */


    /* query address-space for full name (mostly for debug purposes) */
    std::string getFullName() const {
        return m_stringAddress;
    };

    static std::list < DBuildInformation * > s_orphanedObjects;
    static void registerOrphanedObject( DBuildInformation * object ) {
        s_orphanedObjects.push_back( object );
    }
    static std::list < DBuildInformation* > & orphanedObjects() {
        return  s_orphanedObjects;
    }

private:

    Parent_DBuildInformation * m_parent;

public:	  // TODO: reconsider this! shoudln't be public!
    AddressSpace::
    ASBuildInformation
    *m_addressSpaceLink;



private:
    std::string m_stringAddress;

    /* if any of our cachevariables has isKey=true then we shall keep its copy here for find functions  (it is const, either way) */


    /* if any of our config entries has isKey=true then we shall keep its copy here for find functions  (it is const, either way) */


    /* object-wise lock */


    /* variable-wise locks */





};





}

#endif // include guard
