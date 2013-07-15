#include "groupmanager.h"
#include <algorithm>

void GroupManager::registerObject(GameObject *object)
{
    GroupManager::iterator i;
    for (i = this->begin(); i != this->end(); ++i) {
        i->second->registerObject(object);
    }
}

GroupManager::~GroupManager()
{
    GroupManager::iterator i;
    for (i = this->begin(); i != this->end(); ++i) {
        delete i->second;
    }
}
