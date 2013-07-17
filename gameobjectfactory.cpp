#include "gameobjectfactory.h"
#include "enums.h"

GameObject* GameObjectFactory::newSwordObject(int x, int y, int width, int height, int playerNum, System *system)
{
    GameObject *obj = new GameObject();
    obj->insert(ATTR_POSITION);
    obj->insert(ATTR_RECTANGLE);
	obj->insert(ATTR_VELOCITY);
	obj->insert(ATTR_SWORDSTATE);
	obj->insert(ATTR_GRAVITY);
	obj->insert(ATTR_SPRITE);

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

	sf::RectangleShape *sprite = new sf::RectangleShape(sf::Vector2f((float)width, (float)height));
	sprite->setFillColor(sf::Color::Red);
	sprite->setPosition((float)x, (float)y);
	obj->set(ATTR_SPRITE, "sprite", sprite, system);

    return obj;
}

GameObject* GameObjectFactory::newPlayerObject(int x, int y, int width, int height, int playerNum, sf::Keyboard::Key up,
																								   sf::Keyboard::Key down,
																								   sf::Keyboard::Key left,
																								   sf::Keyboard::Key right,
																								   sf::Keyboard::Key jump,
																								   System *system)
{
    GameObject *obj = new GameObject();
    obj->insert(ATTR_POSITION);
    obj->insert(ATTR_RECTANGLE);
	obj->insert(ATTR_VELOCITY);
	obj->insert(ATTR_PLAYERSTATE);
	obj->insert(ATTR_GRAVITY);
	obj->insert(ATTR_KEYMAP);
	obj->insert(ATTR_SPRITE);
	//obj->insert(ATTR_FACING);

	obj->set(ATTR_PLAYERSTATE, "facing", playerNum - 1, system);
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

	obj->set(ATTR_KEYMAP, "up", up, system);
	obj->set(ATTR_KEYMAP, "down", down, system);
	obj->set(ATTR_KEYMAP, "left", left, system);
	obj->set(ATTR_KEYMAP, "right", right, system);
	obj->set(ATTR_KEYMAP, "jump", jump, system);

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
	obj->insert(ATTR_STATIC);
	obj->insert(ATTR_GRAVITY);
	obj->insert(ATTR_SPRITE);

    obj->set(ATTR_POSITION, "x", x, system);
    obj->set(ATTR_POSITION, "y", y, system);
    obj->set(ATTR_RECTANGLE, "width", width, system);
    obj->set(ATTR_RECTANGLE, "height", height, system);
	obj->set(ATTR_STATIC, "static", true, system);
	obj->set(ATTR_GRAVITY, "gravity", false, system);

	sf::RectangleShape *sprite = new sf::RectangleShape(sf::Vector2f((float)width, (float)height));
	sprite->setFillColor(sf::Color::White);
	sprite->setPosition((float)x, (float)y);
	obj->set(ATTR_SPRITE, "sprite", sprite, system);

	return obj;
}

GameObject* GameObjectFactory::newRefereeObject(System *system)
{
    GameObject *obj = new GameObject();
	obj->insert(ATTR_ROUNDSTATE);
    obj->insert(ATTR_POSITION);
	//obj->insert(ATTR_STATIC);
	//obj->insert(ATTR_WINNER);

    obj->set(ATTR_POSITION, "x", 0, system);
    obj->set(ATTR_POSITION, "y", 0, system);
	obj->set(ATTR_ROUNDSTATE,"roundEnd",false,system);
	obj->set(ATTR_ROUNDSTATE,"paused",false,system);
	obj->set(ATTR_ROUNDSTATE,"winner",NOBODY,system); //nobody nobody but you~
	obj->set(ATTR_ROUNDSTATE,"p1score",0,system);
	obj->set(ATTR_ROUNDSTATE,"p2score",0,system);
	obj->set(ATTR_ROUNDSTATE,"GrandWinner",NOBODY,system);

	//obj->set(ATTR_STATIC, "static", true, system);

    return obj;
}

GameObject* GameObjectFactory::newGameStateObject(System *system)
{
    GameObject *obj = new GameObject();
	obj->insert(ATTR_GAMESTATE);

    obj->set(ATTR_GAMESTATE, "inGame", true, system);
	obj->set(ATTR_GAMESTATE, "load", true, system);

    return obj;
}

GameObject* GameObjectFactory::newMenuObject(int x, int y, int size, bool selectable, bool selected, sf::Font *font, std::string text, System *system)
{
	GameObject *obj = new GameObject();
	obj->insert(ATTR_TEXT);

	sf::Text *t = new sf::Text();

	t->setFont(*font);
	t->setString(text);
	t->setCharacterSize(size);
	t->setStyle(sf::Text::Regular);
	t->setPosition((float)x,(float) y);
	t->setColor(sf::Color::White);

	if (selectable) {
		obj->insert(ATTR_SELECTION);
		obj->set(ATTR_SELECTION, "selected", selected, system);
	}
	
	obj->set(ATTR_TEXT, "text", t, system);

	return obj;
}
GameObject* GameObjectFactory::newGameUIObject(int x, int y, int size, int player, bool visible, sf::Font *font, std::string text, System *system)
{
	GameObject *obj = new GameObject();
	obj->insert(ATTR_TEXT);
	obj->insert(ATTR_ROUNDSTATE);
	obj->set(ATTR_ROUNDSTATE,"winner",player,system);
	obj->set(ATTR_ROUNDSTATE,"visible",visible,system);
	sf::Text *t = new sf::Text();

	t->setFont(*font);
	t->setString(text);
	t->setCharacterSize(size);
	t->setStyle(sf::Text::Regular);
	t->setPosition((float)x,(float) y);
	t->setColor(sf::Color::White);


	
	obj->set(ATTR_TEXT, "text", t, system);

	return obj;
}