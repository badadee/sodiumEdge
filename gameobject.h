/*******************************************************************************

    Generic game object;
    contains a hashmap of attribute which can be added, removed, or modified

*******************************************************************************/

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <map>
#include <string>
#include "permissions.h"
#include "system.h"
#include "attributefactory.h"
#include "enums.h"

class GameObject
{
public:
    GameObject();
    void insert(AttributeType attributeType);
    void remove(AttributeType attributeType);
    void removeAll();
    void set(AttributeType attributeType, std::string valueName, int value, System *system);
    void set(AttributeType attributeType, std::string valueName, double value, System *system);
    void set(AttributeType attributeType, std::string valueName, const char *value, System *system);
	void set(AttributeType attributeType, std::string valueName, bool value, System *system);
	void set(AttributeType attributeType, std::string valueName, sf::RectangleShape *value, System *system);
	void set(AttributeType attributeType, std::string valueName, sf::Text *value, System *system);
	void set(AttributeType attributeType, std::string valueName, sf::Keyboard::Key value, System *system);
    bool contains(AttributeType attributeType);
    Variant get(AttributeType attributeType, std::string valueName);
    ~GameObject();

private:
    std::map<AttributeType, Attribute*> *_attributes;
    Permissions *_permissions;
};

#endif // GAMEOBJECT_H
