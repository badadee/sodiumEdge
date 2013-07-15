#include "repository.h"
#include <algorithm>

Repository::Repository()
{
    _groupManager = new GroupManager();
    _gameObjectManager = new GameObjectManager;
}

GameObject* Repository::newSwordObject(int x, int y, int width, int height, int playerNum, System *system)
{    GameObject *newObject = GameObjectFactory::newSwordObject(x,y,width,height,playerNum,system);
    _gameObjectManager->push_back(newObject);
    _groupManager->registerObject(newObject);
    return newObject;
}

GameObject* Repository::newPlayerObject(int x, int y, int width, int height, int playerNum, System *system)
{    GameObject *newObject = GameObjectFactory::newPlayerObject(x,y,width,height,playerNum,system);
    _gameObjectManager->push_back(newObject);
    _groupManager->registerObject(newObject);
    return newObject;
}

GameObject* Repository::newPlatformObject(int x, int y, int width, int height, System *system)
{
    GameObject *newObject = GameObjectFactory::newPlatformObject(x,y,width,height,system);
    _gameObjectManager->push_back(newObject);
    _groupManager->registerObject(newObject);
    return newObject;
}

GameObject* Repository::attach(GameObject *object, AttributeType attributeType)
{
    object->insert(attributeType);
    _groupManager->registerObject(object);
    return object;
}

GameObject* Repository::detach(GameObject *object, AttributeType attributeType)
{
    object->remove(attributeType);
    _groupManager->registerObject(object);
    return object;
}

void Repository::newGroup(GroupType group, AttributeType type)
{
    std::vector<AttributeType> types;
    types.push_back(type);
    (*_groupManager)[group] = new Group(types);
}

void Repository::newGroup(GroupType group, AttributeType type1, AttributeType type2)
{
    std::vector<AttributeType> types;
    types.push_back(type1);
    types.push_back(type2);
    (*_groupManager)[group] = new Group(types);
}

void Repository::newGroup(GroupType group, AttributeType type1, AttributeType type2, AttributeType type3)
{
    std::vector<AttributeType> types;
    types.push_back(type1);
    types.push_back(type2);
	types.push_back(type3);
    (*_groupManager)[group] = new Group(types);
}

void Repository::newGroup(GroupType group, AttributeType type1, AttributeType type2, AttributeType type3, AttributeType type4)
{
    std::vector<AttributeType> types;
    types.push_back(type1);
    types.push_back(type2);
	types.push_back(type3);
	types.push_back(type4);
    (*_groupManager)[group] = new Group(types);
}


void Repository::erase(GameObject *object)
{
    object->removeAll();
    GameObjectManager::iterator pos = std::find(
                _gameObjectManager->begin(),
                _gameObjectManager->end(),
                object);
    _gameObjectManager->erase(pos);
    _groupManager->registerObject(object);
    delete object;
}

ObjectList::iterator Repository::beginGroup(GroupType groupType)
{
    Group* group = (*_groupManager)[groupType];
    return group->begin();
}

ObjectList::iterator Repository::endGroup(GroupType groupType)
{
    Group* group = (*_groupManager)[groupType];
    return group->end();
}

