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
	GameObject* newPlayerObject(int x, int y, int width, int height, int playerNum, sf::Keyboard::Key up,
																				    sf::Keyboard::Key down,
																				    sf::Keyboard::Key left,
																				    sf::Keyboard::Key right,
																				    sf::Keyboard::Key jump,
																					System *system);
	GameObject* newPlatformObject(int x, int y, int width, int height, System *system);
	GameObject* newRefereeObject(System *system);
	GameObject* newGameStateObject(System *system);
	GameObject* newMenuObject(int x, int y, int size, bool selectable, bool selected, sf::Font *font, std::string text, System *system);
    GameObject* attach(GameObject* object, AttributeType attributeType);
    GameObject* detach(GameObject* object, AttributeType attributeType);
    ObjectList::iterator beginGroup(GroupType groupType);
    ObjectList::iterator endGroup(GroupType groupType);
	ObjectList::reverse_iterator rbeginGroup(GroupType groupType);
    ObjectList::reverse_iterator rendGroup(GroupType groupType);
    void erase(GameObject* object);
	void clean();
    void newGroup(GroupType group, AttributeType type);
    void newGroup(GroupType group, AttributeType type1, AttributeType type2);
    void newGroup(GroupType group, AttributeType type1, AttributeType type2, AttributeType type3);
    void newGroup(GroupType group, AttributeType type1, AttributeType type2, AttributeType type3, AttributeType type4);
private:
    GroupManager *_groupManager;
    GameObjectManager *_gameObjectManager;
};

#endif // REPOSITORY_H
