#include "gameobjectfactory.h"
#include "enums.h"

GameObject* GameObjectFactory::newSwordObject(int x, int y, int width, int height, int playerNum, System *system)
{
    GameObject *obj = new GameObject();
    obj->insert(ATTR_POSITION);
    obj->insert(ATTR_RECTANGLE);
	obj->insert(ATTR_VELOCITY);
	obj->insert(ATTR_SPRITE);
	obj->insert(ATTR_SWORDSTATE);
	obj->insert(ATTR_GRAVITY);
	//obj->insert(ATTR_STATIC);
    obj->set(ATTR_POSITION, "x", x, system);
    obj->set(ATTR_POSITION, "y", y, system);
    obj->set(ATTR_RECTANGLE, "width", width, system);
    obj->set(ATTR_RECTANGLE, "height", height, system);
	obj->set(ATTR_VELOCITY, "xVelocity", 0, system);
	obj->set(ATTR_VELOCITY, "yVelocity", 0, system);
	obj->set(ATTR_SWORDSTATE, "heldBy", playerNum, system);
	obj->set(ATTR_SWORDSTATE, "up", false, system);
	obj->set(ATTR_SWORDSTATE, "down", false, system);
	obj->set(ATTR_SWORDSTATE, "held", true, system);
	obj->set(ATTR_GRAVITY, "gravity", false, system);
	//obj->set(ATTR_STATIC, "static", false, system); //non-static obj

	sf::RectangleShape *sprite = new sf::RectangleShape(sf::Vector2f((float)width, (float)height));
	sprite->setFillColor(sf::Color::Red);
	sprite->setPosition((float)x, (float)y);
	obj->set(ATTR_SPRITE, "sprite", sprite, system);

    return obj;
}

GameObject* GameObjectFactory::newPlayerObject(int x, int y, int width, int height, int playerNum, System *system)
{
    GameObject *obj = new GameObject();
    obj->insert(ATTR_POSITION);
    obj->insert(ATTR_RECTANGLE);
	obj->insert(ATTR_VELOCITY);
	obj->insert(ATTR_PLAYERSTATE);
	obj->insert(ATTR_SPRITE);
	obj->insert(ATTR_GRAVITY);
	//obj->insert(ATTR_STATIC);
    obj->set(ATTR_POSITION, "x", x, system);
    obj->set(ATTR_POSITION, "y", y, system);
    obj->set(ATTR_RECTANGLE, "width", width, system);
    obj->set(ATTR_RECTANGLE, "height", height, system);
	obj->set(ATTR_VELOCITY, "xVelocity", 0, system);
    obj->set(ATTR_VELOCITY, "yVelocity", 0, system);
	obj->set(ATTR_PLAYERSTATE, "playerNum", playerNum, system);
	obj->set(ATTR_PLAYERSTATE, "jumping", false, system);
	obj->set(ATTR_PLAYERSTATE, "onPlatform", true, system);
	obj->set(ATTR_GRAVITY, "gravity", true, system);
	//obj->set(ATTR_STATIC, "static", false, system); //non-static obj

	sf::RectangleShape *sprite = new sf::RectangleShape(sf::Vector2f((float)width, (float)height));
	sprite->setFillColor(sf::Color::Green);
	sprite->setPosition((float)x, (float)y);
	obj->set(ATTR_SPRITE, "sprite", sprite, system);

    return obj;
}

GameObject* GameObjectFactory::newPlatformObject(int x, int y, int width, int height,  System *system)
{
    GameObject *obj = new GameObject();
    obj->insert(ATTR_POSITION);
    obj->insert(ATTR_RECTANGLE);
	obj->insert(ATTR_SPRITE);
	obj->insert(ATTR_STATIC);
	obj->insert(ATTR_GRAVITY);
    obj->set(ATTR_POSITION, "x", x, system);
    obj->set(ATTR_POSITION, "y", y, system);
    obj->set(ATTR_RECTANGLE, "width", width, system);
    obj->set(ATTR_RECTANGLE, "height", height, system);
	obj->set(ATTR_GRAVITY, "gravity", false, system);

	sf::RectangleShape *sprite = new sf::RectangleShape(sf::Vector2f((float)width, (float)height));
	sprite->setFillColor(sf::Color::White);
	sprite->setPosition((float)x, (float)y);
	obj->set(ATTR_SPRITE, "sprite", sprite, system);

	obj->set(ATTR_STATIC, "static", true, system);

    return obj;
}