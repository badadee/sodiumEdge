#include "physicssystem.h"
#include <iostream>


PhysicsSystem::PhysicsSystem(Repository * repo)
{
	_repo = repo;
}

void PhysicsSystem::update()
{
	ObjectList::iterator i;

	//This loop is for every object interacting with physics
	for (i = _repo->beginGroup(GRP_PHYSICS); i != _repo->endGroup(GRP_PHYSICS); ++i) {
		GameObject *o = *i;
		int x = o->get(ATTR_POSITION, "x").toInt();
		int y = o->get(ATTR_POSITION, "y").toInt();
		int xVelocity = o->get(ATTR_VELOCITY, "xVelocity").toInt();
		int yVelocity = o->get(ATTR_VELOCITY, "yVelocity").toInt();

		//Uncomment this when the collision detection is working

		if (o->get(ATTR_GRAVITY, "gravity").toBool() == true) {
			if(yVelocity < 9){

					yVelocity += _gravity;
			}
			o->set(ATTR_VELOCITY, "yVelocity", yVelocity, this);
		}


		x += xVelocity;
		y += yVelocity;

		o->set(ATTR_POSITION, "x", x, this);
		o->set(ATTR_POSITION, "y", y, this);
	}

	//This loop is for moving the sword with the player
	for (i = _repo->beginGroup(GRP_PLAYERS); i != _repo->endGroup(GRP_PLAYERS); ++i) {
		GameObject *playerObject = *i;

		int playerNum = playerObject->get(ATTR_PLAYERSTATE, "playerNum").toInt();
		GameObject *swordObject = this->getSword(playerNum);
		int x = swordObject->get(ATTR_POSITION, "x").toInt();
		int y = swordObject->get(ATTR_POSITION, "y").toInt();
		int xVelocity = playerObject->get(ATTR_VELOCITY, "xVelocity").toInt();
		int yVelocity = playerObject->get(ATTR_VELOCITY, "yVelocity").toInt();

		if(swordObject->get(ATTR_SWORDSTATE,"held").toBool()){
		x += xVelocity;
		y += yVelocity;
		}
		else{
			y += yVelocity;
		}
		swordObject->set(ATTR_POSITION, "x", x, this);
		swordObject->set(ATTR_POSITION, "y", y, this);
	}
}

GameObject* PhysicsSystem::getSword(int playerNum)
{
	ObjectList::iterator i;
	for (i = _repo->beginGroup(GRP_SWORDS); i != _repo->endGroup(GRP_SWORDS); ++i) {
		GameObject *o = *i;

		if (o->get(ATTR_SWORDSTATE, "heldBy").toInt() == playerNum) {
			return o;
		}
	}

	return 0;
}