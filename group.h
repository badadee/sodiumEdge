/*******************************************************************************

    Vector of GameObject pointers, categorized by a set of attributes;
    for any object to be registered with the group, it must contain
    the group's required attributes.

*******************************************************************************/

#ifndef GROUP_H
#define GROUP_H

#include <vector>
#include "gameobject.h"

class Group
{
public:
    Group(std::vector<AttributeType> requiredAttributes);
    void updateRegistry(GameObject* object);
    std::vector<AttributeType> requiredAttributes();
    std::vector<GameObject*>::iterator begin();
    std::vector<GameObject*>::iterator end();
	std::vector<GameObject*>::reverse_iterator rbegin();
	std::vector<GameObject*>::reverse_iterator rend();
    ~Group();
private:
    bool canRegister(GameObject *object);
    bool contains(GameObject *object);
    std::vector<GameObject*> *_objects;
    std::vector<AttributeType> _requiredAttributes;
};

#endif // GROUP_H
