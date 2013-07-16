#include "groupmanager.h"
#include <algorithm>

void GroupManager::updateRegistry(GameObject *object)
{
    GroupManager::iterator i;
    for (i = this->begin(); i != this->end(); ++i) {
        i->second->updateRegistry(object);
    }
}

GroupManager::~GroupManager()
{
    GroupManager::iterator i;
    for (i = this->begin(); i != this->end(); ++i) {
        delete i->second;
    }
}
