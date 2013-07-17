#include "inputsystem.h"

InputSystem::InputSystem(Repository * repo)
{
    _repo = repo;
}

void InputSystem::update()
{
	ObjectList::iterator i;
    for (i = _repo->beginGroup(GRP_PLAYERS); i != _repo->endGroup(GRP_PLAYERS); ++i) {
        GameObject *playerObject = *i;
		
		int playerNum = playerObject->get(ATTR_PLAYERSTATE, "playerNum").toInt();
		GameObject *swordObject = this->getSword(playerNum);
		sf::Keyboard::Key upKey = playerObject->get(ATTR_KEYMAP, "up").toKey();
		sf::Keyboard::Key downKey = playerObject->get(ATTR_KEYMAP, "down").toKey();
		sf::Keyboard::Key leftKey = playerObject->get(ATTR_KEYMAP, "left").toKey();
		sf::Keyboard::Key rightKey = playerObject->get(ATTR_KEYMAP, "right").toKey();
		sf::Keyboard::Key jumpKey = playerObject->get(ATTR_KEYMAP, "jump").toKey();

		bool up = swordObject->get(ATTR_SWORDSTATE, "up").toBool();
		bool down = swordObject->get(ATTR_SWORDSTATE, "down").toBool();
		

		playerObject->set(ATTR_VELOCITY, "xVelocity", 0, this);
		swordObject->set(ATTR_VELOCITY, "xVelocity", 0, this);

		if (sf::Keyboard::isKeyPressed(leftKey) && !sf::Keyboard::isKeyPressed(rightKey)) {
			playerObject->set(ATTR_VELOCITY, "xVelocity", -5, this);
		}
		if (sf::Keyboard::isKeyPressed(rightKey) && !sf::Keyboard::isKeyPressed(leftKey)) {
			playerObject->set(ATTR_VELOCITY, "xVelocity", 5, this);
		}

		if (sf::Keyboard::isKeyPressed(jumpKey)) {
			bool jumping = playerObject->get(ATTR_PLAYERSTATE, "jumping").toBool();
			if (!jumping) {
				playerObject->set(ATTR_PLAYERSTATE, "jumping", true, this);
				playerObject->set(ATTR_VELOCITY, "yVelocity", -20, this);
			}
		}

		if (sf::Keyboard::isKeyPressed(upKey) && !sf::Keyboard::isKeyPressed(downKey) && !up) {
			swordObject->set(ATTR_VELOCITY, "yVelocity", -10, this);
			swordObject->set(ATTR_SWORDSTATE, "up", true, this);
			break;
		}
		if (sf::Keyboard::isKeyPressed(downKey) && !sf::Keyboard::isKeyPressed(upKey) && !down) {
			swordObject->set(ATTR_VELOCITY, "yVelocity", 10, this);
			swordObject->set(ATTR_SWORDSTATE, "down", true, this);
			break;
		}

		swordObject->set(ATTR_VELOCITY, "yVelocity", 0, this);				
		if (!sf::Keyboard::isKeyPressed(upKey) && up) {
			swordObject->set(ATTR_VELOCITY, "yVelocity", 10, this);
			swordObject->set(ATTR_SWORDSTATE, "up", false, this);
		}

		if (!sf::Keyboard::isKeyPressed(downKey) && down) {
			swordObject->set(ATTR_VELOCITY, "yVelocity", -10, this);
			swordObject->set(ATTR_SWORDSTATE, "down", false, this);
		}
    }
}

GameObject* InputSystem::getSword(int playerNum)
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