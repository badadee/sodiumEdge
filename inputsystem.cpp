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
		bool up = swordObject->get(ATTR_SWORDSTATE, "up").toBool();
		bool down = swordObject->get(ATTR_SWORDSTATE, "down").toBool();
		
		switch(playerNum) {
			//Player1 Controls
			case 1:
				playerObject->set(ATTR_VELOCITY, "xVelocity", 0, this);
				swordObject->set(ATTR_VELOCITY, "xVelocity", 0, this);

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
					playerObject->set(ATTR_VELOCITY, "xVelocity", -5, this);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
					playerObject->set(ATTR_VELOCITY, "xVelocity", 5, this);
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
					bool jumping = playerObject->get(ATTR_PLAYERSTATE, "jumping").toBool();
					if (!jumping) {
						playerObject->set(ATTR_PLAYERSTATE, "jumping", true, this);
						playerObject->set(ATTR_VELOCITY, "yVelocity", -20, this);
					}
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !up) {
					swordObject->set(ATTR_VELOCITY, "yVelocity", -10, this);
					swordObject->set(ATTR_SWORDSTATE, "up", true, this);
					break;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !down) {
					swordObject->set(ATTR_VELOCITY, "yVelocity", 10, this);
					swordObject->set(ATTR_SWORDSTATE, "down", true, this);
					break;
				}

				swordObject->set(ATTR_VELOCITY, "yVelocity", 0, this);				
				if (!sf::Keyboard::isKeyPressed(sf::Keyboard::W) && up) {
					swordObject->set(ATTR_VELOCITY, "yVelocity", 10, this);
					swordObject->set(ATTR_SWORDSTATE, "up", false, this);
				}

				if (!sf::Keyboard::isKeyPressed(sf::Keyboard::S) && down) {
					swordObject->set(ATTR_VELOCITY, "yVelocity", -10, this);
					swordObject->set(ATTR_SWORDSTATE, "down", false, this);
				}
				break;

			//Player2 Controls
			case 2:
				playerObject->set(ATTR_VELOCITY, "xVelocity", 0, this);
				swordObject->set(ATTR_VELOCITY, "xVelocity", 0, this);

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
					playerObject->set(ATTR_VELOCITY, "xVelocity", -5, this);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
					playerObject->set(ATTR_VELOCITY, "xVelocity", 5, this);
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)) {
					bool jumping = playerObject->get(ATTR_PLAYERSTATE, "jumping").toBool();
					if (!jumping) {
						playerObject->set(ATTR_PLAYERSTATE, "jumping", true, this);
						playerObject->set(ATTR_VELOCITY, "yVelocity", -20, this);
					}
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !up) {
					swordObject->set(ATTR_VELOCITY, "yVelocity", -10, this);
					swordObject->set(ATTR_SWORDSTATE, "up", true, this);
					break;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !down) {
					swordObject->set(ATTR_VELOCITY, "yVelocity", 10, this);
					swordObject->set(ATTR_SWORDSTATE, "down", true, this);
					break;
				}

				swordObject->set(ATTR_VELOCITY, "yVelocity", 0, this);				
				if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && up) {
					swordObject->set(ATTR_VELOCITY, "yVelocity", 10, this);
					swordObject->set(ATTR_SWORDSTATE, "up", false, this);
				}

				if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && down) {
					swordObject->set(ATTR_VELOCITY, "yVelocity", -10, this);
					swordObject->set(ATTR_SWORDSTATE, "down", false, this);
				}
				break;
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