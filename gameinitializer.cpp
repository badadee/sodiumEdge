#include "gameinitializer.h"
#include "inputsystem.h"
#include "rendersystem.h"
#include "physicssystem.h"
#include "collisionsystem.h"

Repository* GameInitializer::initializeRepository()
{
	Repository *repo = new Repository();
	return repo;
}

sf::RenderWindow* GameInitializer::initializerWindow()
{
	sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(800, 600), "Bist Gaim evrr");
	sf::Vector2u windowSize = window->getSize();
    window->setVerticalSyncEnabled(true);
	return window;
}

std::list<System*> GameInitializer::initializeGameSystems(sf::RenderWindow *window, Repository *repo)
{
	std::list<System*> systemList;

	InputSystem *inputSystem = new InputSystem(repo);
	systemList.push_back(inputSystem);

	PhysicsSystem *physicsSystem = new PhysicsSystem(repo);
	systemList.push_back(physicsSystem);

	RenderSystem *renderSystem = new RenderSystem(repo, window);
	systemList.push_back(renderSystem);

	CollisionSystem *collisionSystem = new CollisionSystem(repo);
	systemList.push_back(collisionSystem);

	repo->newGroup(GRP_PLAYERS, ATTR_POSITION, ATTR_VELOCITY, ATTR_PLAYERSTATE);
	repo->newGroup(GRP_SWORDS, ATTR_POSITION, ATTR_VELOCITY, ATTR_SWORDSTATE);
	repo->newGroup(GRP_PHYSICS, ATTR_POSITION, ATTR_VELOCITY, ATTR_GRAVITY);
	repo->newGroup(GRP_RENDER, ATTR_SPRITE, ATTR_POSITION, ATTR_RECTANGLE);
	repo->newGroup(GRP_PLATFORM, ATTR_POSITION,ATTR_RECTANGLE,ATTR_STATIC);
	repo->newGroup(GRP_GAMEUTIL, ATTR_POSITION,ATTR_GAMESTATE);

	return systemList;
}