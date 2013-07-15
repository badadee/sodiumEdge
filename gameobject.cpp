#include "gameobject.h"
#include <iostream>
#include <iterator>
#include <signal.h>

/************************************************* CONSTRUCTOR AND DESTRUCTOR */

// constructor
GameObject::GameObject()
{
    _attributes = new std::map<AttributeType, Attribute*>;
    _permissions = new Permissions();
}

// destructor
GameObject::~GameObject()
{
    std::map<AttributeType, Attribute*>::iterator i;
    for (i = _attributes->begin(); i != _attributes->end(); ++i) {
        delete i->second;
    }
}

/******************************************************* ATTRIBUTE MANAGEMENT */

// add an attribute and its default values to the object
void GameObject::insert(AttributeType attributeType)
{
    Attribute *newAttribute = AttributeFactory::create(attributeType);
    (*_attributes)[attributeType] = newAttribute;
}

// remove an attribute
void GameObject::remove(AttributeType attributeType)
{
    // TODO: make sure attribute exists
    delete _attributes->at(attributeType);
    _attributes->erase(attributeType);
}

// remove all attributes
void GameObject::removeAll()
{
    std::map<AttributeType, Attribute*>::iterator i;
    for (i = _attributes->begin(); i != _attributes->end(); ++i) {
        delete i->second;
    }
    _attributes->clear();
}

/******************************************************** GETTERS AND SETTERS */

// get an attribute value, crash the game if no attribute or value exists
Variant GameObject::get(AttributeType attributeType, std::string valueName)
{
    if (_attributes->find(attributeType) == _attributes->end()) {
        std::cout << "Invalid attribute ID: " << attributeType << '\n';
        raise(SIGABRT);
    }
    Attribute *attr = (*_attributes)[attributeType];
    if (attr->find(valueName) == attr->end()) {
        std::cout << "Invalid attribute ID: " << attributeType << "->" << valueName << '\n';
        raise(SIGABRT);
    }
    return (*attr)[valueName];
}

// set an attribute value to an int
void GameObject::set(AttributeType attributeType, std::string valueName, int value, System *system)
{
    if (Permissions::isAllowed(attributeType, system)) {
        (*(*_attributes)[attributeType])[valueName] = value;
    }
}

// set an attribute value to a double
void GameObject::set(AttributeType attributeType, std::string valueName, double value, System *system)
{
    if (Permissions::isAllowed(attributeType, system)) {
        (*(*_attributes)[attributeType])[valueName] = value;
    }
}

// set an attribute value to a string
void GameObject::set(AttributeType attributeType, std::string valueName, const char* value, System *system)
{
    if (Permissions::isAllowed(attributeType, system)) {
        (*(*_attributes)[attributeType])[valueName] = value;
    }
}

// set an attribute value to a boolean
void GameObject::set(AttributeType attributeType, std::string valueName, bool value, System *system)
{
    if (Permissions::isAllowed(attributeType, system)) {
        (*(*_attributes)[attributeType])[valueName] = value;
    }
}

// set an attribute value to a sprite
void GameObject::set(AttributeType attributeType, std::string valueName, sf::RectangleShape *value, System *system)
{
    if (Permissions::isAllowed(attributeType, system)) {
        (*(*_attributes)[attributeType])[valueName] = value;
    }
}

/*********************************************************************** MISC */

// whether or not the attribute is contained within the game object
bool GameObject::contains(AttributeType attributeType)
{
    if (_attributes->find(attributeType) == _attributes->end()) {
        return false;
    } else {
        return true;
    }
}
