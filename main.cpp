#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "repository.h"
#include "inputsystem.h"
#include "rendersystem.h"
#include "physicssystem.h"
#include "collisionsystem.h"

using namespace std;
using namespace sf;

int main()
{
	//Initialize Window
	RenderWindow *window = new RenderWindow(VideoMode(800, 600), "Bist Gaim evrr");
	Vector2u windowSize = window->getSize();
    window->setVerticalSyncEnabled(true);

    // initialize the repository and add a group
    Repository *repo = new Repository();

	repo->newGroup(GRP_PLAYERS, ATTR_POSITION, ATTR_VELOCITY, ATTR_PLAYERSTATE);
	repo->newGroup(GRP_SWORDS, ATTR_POSITION, ATTR_VELOCITY, ATTR_SWORDSTATE);
	repo->newGroup(GRP_PHYSICS, ATTR_POSITION, ATTR_VELOCITY, ATTR_GRAVITY);
	repo->newGroup(GRP_RENDER, ATTR_SPRITE, ATTR_POSITION, ATTR_RECTANGLE);
	repo->newGroup(GRP_PLATFORM, ATTR_POSITION,ATTR_RECTANGLE,ATTR_STATIC);
	repo->newGroup(GRP_GAMEUTIL, ATTR_POSITION,ATTR_GAMESTATE);

    // define some system or something
    InputSystem *inputSystem = new InputSystem(repo);
	PhysicsSystem *physicsSystem = new PhysicsSystem(repo);
	RenderSystem *renderSystem = new RenderSystem(repo, window);
	CollisionSystem *collisionSystem = new CollisionSystem(repo);
    // add some crap to the repository
	repo->newPlatformObject(100, 500, 600, 100, inputSystem);
	repo->newSwordObject(130, 440, 50, 9, 1, inputSystem);
	repo->newPlayerObject(100, 400, 30, 100, 1, inputSystem);
	repo->newSwordObject(620, 440, 50, 9, 2, inputSystem);
	repo->newPlayerObject(670, 400, 30, 100, 2, inputSystem);
	repo->newRefereeObject(collisionSystem);

    while (window->isOpen())
    {
        Event event;
        while (window->pollEvent(event))
        {
            if (event.type == Event::Closed)
                window->close();
        }

        window->clear();

		inputSystem->update();
		physicsSystem->update();
		collisionSystem->update();
		renderSystem->update();

        window->display();
    }


    /*
      If you want to create a new attribute:
        add it to AttributeFactory::create()

      if you want to create a new factory game object:
        add a new function to gameObjectFactory (ie - GameObjectFactory::newPlayer(...)
        add a new function to repository (ie - Repository::newPlayer(...)

      if you want to create a new group:
        Repository::newGroup(...)

      for all the system-related stuff, you can choose how to implement it
      exactly
    */

	return 0;
}
