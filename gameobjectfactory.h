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
	static GameObject* newPlayerObject(int x, int y, int width, int height, int playerNum, System *system);
	static GameObject* newPlatformObject(int x, int y, int width, int height,  System *system);
	static GameObject* newRefereeObject(System *system);
};

#endif // GAMEOBJECTFACTORY_H
