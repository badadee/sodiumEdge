#include "group.h"
#include <algorithm>

/************************************************* CONSTRUCTOR AND DESTRUCTOR */

Group::Group(std::vector<AttributeType> requiredAttributes)
{
    _objects = new std::vector<GameObject*>;
    _requiredAttributes = requiredAttributes;
}

Group::~Group()
{
    delete _objects;
}

/*************************************************************** REGISTRATION */

// registers an object if it contains the required attributes
// unregisters an object if it does not contain the required attributes
void Group::updateRegistry(GameObject *object)
{
    // register object if valid and not already registered
    if (this->canRegister(object) && !this->contains(object)) {
        _objects->push_back(object);

    // unregister object if invalid but already registered
    } else if (!this->canRegister(object) && this->contains(object)) {
        std::vector<GameObject*>::iterator pos;
        pos = std::find(_objects->begin(), _objects->end(), object);
        _objects->erase(pos);
    }
    // otherwise, the object is already properly registered/unregistered
}

// returns whether or not an object contains the required attributes
bool Group::canRegister(GameObject *object)
{
    std::vector<AttributeType>::iterator i;
    for (i = _requiredAttributes.begin(); i != _requiredAttributes.end(); ++i) {
        if (!object->contains(*i)) {
            return false;
        }
    }
    return true;
}

// returns whether or not the object already exists in the group
bool Group::contains(GameObject *object)
{
    std::vector<GameObject*>::iterator pos;
    pos = std::find(_objects->begin(), _objects->end(), object);
    if (pos == _objects->end()) {
        return false;
    } else {
        return true;
    }
}

/******************************************************************** GETTERS */

std::vector<AttributeType> Group::requiredAttributes()
{
    return _requiredAttributes;
}

std::vector<GameObject*>::iterator Group::begin()
{
    return _objects->begin();
}

std::vector<GameObject*>::iterator Group::end()
{
    return _objects->end();
}

std::vector<GameObject*>::reverse_iterator Group::rbegin()
{
	return _objects->rbegin();
}

std::vector<GameObject*>::reverse_iterator Group::rend()
{
	return _objects->rend();
}