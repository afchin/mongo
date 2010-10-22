// reci.h
/*
 *    Copyright (C) 2010 10gen Inc.
 *
 *    This program is free software: you can redistribute it and/or  modify
 *    it under the terms of the GNU Affero General Public License, version 3,
 *    as published by the Free Software Foundation.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU Affero General Public License for more details.
 *
 *    You should have received a copy of the GNU Affero General Public License
 *    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#pragma once

#include "diskloc.h"

namespace mongo { 

// #define VIRT virtual
#define VIRT 

/* Subclass this and implement your real storage interface.
*/
class RecStoreInterface {
public:
    //VIRT ~RecStoreInterface() {}

    /* Get a pointer to the data at diskloc d.  Pointer guaranteed to stay in
       scope through the current database operation's life.
    */
    //VIRT char* get(DiskLoc d, unsigned len) = 0;

    /* indicate that the diskloc specified has been updated. note that as-is today, the modification may come AFTER this 
       call -- we handle that currently -- until the dblock finishes.
    */
    //VIRT void modified(DiskLoc d) = 0;

    /* insert specified data as a record */
    //VIRT DiskLoc insert(const char *ns, const void *obuf, int len, bool god) = 0;

    //VIRT void deleteRecord(const char *ns, DiskLoc d) { massert( 10379 , "not implemented RecStoreInterface::deleteRecord", false); }

    /* drop the collection */
    //VIRT void drop(const char *ns) = 0;

    /* rename collection */
    //VIRT void rename(const char *fromNs, const char *toNs) = 0;

    /* close datafiles associated with the db specified. */
    //VIRT void closeFiles(string dbname, string path) = 0;

    /* todo add: 
       closeFiles(dbname)
       eraseFiles(dbname)
    */
};

}