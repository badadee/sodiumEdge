#include "repository.h"
#include <algorithm>

Repository::Repository()
{
    _groupManager = new GroupManager();
    _gameObjectManager = new GameObjectManager;
}

GameObject* Repository::newSwordObject(int x, int y, int width, int height, int playerNum, System *system)
{
	GameObject *newObject = GameObjectFactory::newSwordObject(x,y,width,height,playerNum,system);
    _gameObjectManager->push_back(newObject);
    _groupManager->updateRegistry(newObject);
    return newObject;
}

GameObject* Repository::newPlayerObject(int x, int y, int width, int height, int playerNum, sf::Keyboard::Key up,
																							sf::Keyboard::Key down,
																							sf::Keyboard::Key left,
																							sf::Keyboard::Key right,
																							sf::Keyboard::Key jump,
																							System *system) {
	GameObject *newObject = GameObjectFactory::newPlayerObject(x,y,width,height,playerNum,up,
																						  down,
																						  left,
																						  right,
																						  jump,
																						  system);
    _gameObjectManager->push_back(newObject);
    _groupManager->updateRegistry(newObject);
    return newObject;
}

GameObject* Repository::newPlatformObject(int x, int y, int width, int height, System *system)
{
    GameObject *newObject = GameObjectFactory::newPlatformObject(x,y,width,height,system);
    _gameObjectManager->push_back(newObject);
    _groupManager->updateRegistry(newObject);
    return newObject;
}

GameObject* Repository::newRefereeObject(System *system)
{
    GameObject *newObject = GameObjectFactory::newRefereeObject(system);
    _gameObjectManager->push_back(newObject);
    _groupManager->updateRegistry(newObject);
    return newObject;
}

GameObject* Repository::newGameStateObject(System *system)
{
    GameObject *newObject = GameObjectFactory::newGameStateObject(system);
    _gameObjectManager->push_back(newObject);
    _groupManager->updateRegistry(newObject);
    return newObject;
}

GameObject* Repository::newMenuObject(int x, int y, int size, bool selectable, bool selected, sf::Font *font, std::string text, System *system)
{
    GameObject *newObject = GameObjectFactory::newMenuObject(x, y, size, selectable, selected, font, text, system);
    _gameObjectManager->push_back(newObject);
    _groupManager->updateRegistry(newObject);
    return newObject;
}

GameObject* Repository::newGameUIObject(int x, int y, int size, int player, bool visible, sf::Font *font, std::string text, System *system)
{
    GameObject *newObject = GameObjectFactory::newGameUIObject(x, y, size, player, visible, font, text, system);
    _gameObjectManager->push_back(newObject);
    _groupManager->updateRegistry(newObject);
    return newObject;
}

GameObject* Repository::attach(GameObject *object, AttributeType attributeType)
{
    object->insert(attributeType);
    _groupManager->updateRegistry(object);
    return object;
}

GameObject* Repository::detach(GameObject *object, AttributeType attributeType)
{
    object->remove(attributeType);
    _groupManager->updateRegistry(object);
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
    _groupManager->updateRegistry(object);
    delete object;
}

void Repository::clean()
{
	GameObjectManager::iterator i;

	for (i = _gameObjectManager->begin(); i != _gameObjectManager->end(); ++i)
	{
		GameObject *o = *i;
		erase(o);
	}
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

ObjectList::reverse_iterator Repository::rbeginGroup(GroupType groupType)
{
    Group* group = (*_groupManager)[groupType];
    return group->rbegin();
}

ObjectList::reverse_iterator Repository::rendGroup(GroupType groupType)
{
    Group* group = (*_groupManager)[groupType];
    return group->rend();
}

