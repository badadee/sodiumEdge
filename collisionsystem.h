/*******************************************************************************

    Physics System
    Handles movement of game objects

*******************************************************************************/

#ifndef COLLISIONSYSTEM_H
#define COLLISIONSYSTEM_H

#include "system.h"
#include "repository.h"

class CollisionSystem : public System
{
public:
	CollisionSystem(Repository *repo);
    virtual void update();
private:
	Repository *_repo;
	static const int _gravity = 2;
	GameObject* getSword(int playerNum);
	GameObject* getPlayer(int playerNum);
	GameObject* getReferee();
	void bounceBackPlayer();

};

#endif // COLLISIONSYSTEM_H