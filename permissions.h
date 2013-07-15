/*******************************************************************************

    Permission Checker (NOT DONE YET);
    takes a system and an attribute and determines if that system has
    write access to said attribute.

*******************************************************************************/

#ifndef PERMISSIONS_H
#define PERMISSIONS_H

#include "enums.h"
#include "system.h"

class Permissions
{
public:
    static bool isAllowed(AttributeType, System*);
};

#endif // PERMISSIONS_H
