/*******************************************************************************

    Static Class for creating instances of GameObjects;

    note: any gameObject returned by the factory is stored on the heap
          and must be freed.

*******************************************************************************/

#ifndef GAMEOBJECTFACTORY_H
#define GAMEOBJECTFACTORY_H

#include "gameobject.h"
#include "system.h"

class GameObjectFactory
{
public:
	static GameObject* newSwordObject(int x, int y, int width, int height, int playerNum, System *system);
	static GameObject* newPlayerObject(int x, int y, int width, int height, int playerNum, sf::Keyboard::Key up,
																						   sf::Keyboard::Key down,
																						   sf::Keyboard::Key left,
																						   sf::Keyboard::Key right,
																						   sf::Keyboard::Key jump,
																						   sf::Keyboard::Key thrust,
																						   sf::Keyboard::Key bMenu,
																						   System *system);
	static GameObject* newPlatformObject(int x, int y, int width, int height,  System *system);
	static GameObject* newRefereeObject(System *system);
	static GameObject* newGameStateObject(bool inGame, bool load, System *system);
	static GameObject* newMenuObject(int x, int y, int size, int menuNum, bool selectable, bool selected, bool score, sf::Font *font, std::string text, System *system);
	static GameObject* newMenuActionObject(System *system);
};

#endif // GAMEOBJECTFACTORY_H
