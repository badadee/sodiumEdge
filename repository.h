/*******************************************************************************

    Facade interface to components;
    acts as an interface for systems to read and write from the set
    of game objects, attributes and groups.

*******************************************************************************/

#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <vector>
#include <string>
#include "gameobjectfactory.h"
#include "groupmanager.h"

typedef std::vector<GameObject*> GameObjectManager;
typedef std::vector<GameObject*> ObjectList;

class Repository
{
public:
    Repository();
	GameObject* newSwordObject(int x, int y, int width, int height, int playerNum, System *system);
	GameObject* newPlayerObject(int x, int y, int width, int height, int playerNum, System *system);
	GameObject* newPlatformObject(int x, int y, int width, int height, System *system);
    GameObject* attach(GameObject* object, AttributeType attributeType);
    GameObject* detach(GameObject* object, AttributeType attributeType);
    ObjectList::iterator beginGroup(GroupType groupType);
    ObjectList::iterator endGroup(GroupType groupType);
    void erase(GameObject* object);
    void newGroup(GroupType group, AttributeType type);
    void newGroup(GroupType group, AttributeType type1, AttributeType type2);
    void newGroup(GroupType group, AttributeType type1, AttributeType type2, AttributeType type3);
    void newGroup(GroupType group, AttributeType type1, AttributeType type2, AttributeType type3, AttributeType type4);
private:
    GroupManager *_groupManager;
    GameObjectManager *_gameObjectManager;
};

#endif // REPOSITORY_H
