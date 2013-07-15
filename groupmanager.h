/*******************************************************************************

    A list of groups;
    whenever an object is modified (ie - created, deleted or attribute
    removed or inserted), the group manager will re-register that object
    with each appropriate group.

*******************************************************************************/

#ifndef GROUPMANAGER_H
#define GROUPMANAGER_H

#include <map>
#include <string>
#include "group.h"

class GroupManager : public std::map<GroupType, Group*>
{
public:
    void registerObject(GameObject *object);
    ~GroupManager();
};

#endif // GROUPMANAGER_H
