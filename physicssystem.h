/*******************************************************************************

    Physics System
    Handles movement of game objects

*******************************************************************************/

#ifndef PHYSICSSYSTEM_H
#define PHYSICSSYSTEM_H

#include "system.h"
#include "repository.h"

class PhysicsSystem : public System
{
public:
	PhysicsSystem(Repository *repo);
    virtual void update();
private:
	Repository *_repo;
	static const int _gravity = 2;
	GameObject* getSword(int playerNum);
};

#endif // PHYSICSSYSTEM_H