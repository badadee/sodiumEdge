/*******************************************************************************

    Static Class for creating instances of Attributes;
    Attributes are tables of related data for a game object
    (ie - position, sprite, velocity, state, etc)

    note: any attribute returned by the factory is stored on the heap
          and must be freed.

*******************************************************************************/

#ifndef ATTRIBUTEFACTORY_H
#define ATTRIBUTEFACTORY_H

#include <map>
#include <string>
#include "variant.h"
#include "enums.h"

typedef std::map<std::string, Variant> Attribute;

class AttributeFactory
{
public:
    static Attribute* create(AttributeType type);
};

#endif // ATTRIBUTEFACTORY_H
