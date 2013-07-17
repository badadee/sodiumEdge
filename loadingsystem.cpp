#include <iostream>
#include "loadingsystem.h"

LoadingSystem::LoadingSystem(Repository *repo)
{
    _repo = repo;
}

void LoadingSystem::update()
{
	ObjectList::iterator i;
	for (i = _repo->beginGroup(GRP_GAMESTATE); i != _repo->endGroup(GRP_GAMESTATE); ++i) {
		GameObject *o = *i;

		if (o->get(ATTR_GAMESTATE, "load").toBool()) {
			switch (o->get(ATTR_GAMESTATE, "inGame").toBool()) {
				case false:
					break;

				case true:					
					_repo->newPlatformObject(100, 500, 600, 100, this);
					_repo->newSwordObject(130, 440, 50, 9, 1, this);
					_repo->newPlayerObject(100, 400, 30, 100, 1, sf::Keyboard::W,
																 sf::Keyboard::S,
																 sf::Keyboard::A,
																 sf::Keyboard::D,
																 sf::Keyboard::LShift,
																 this);
					_repo->newSwordObject(620, 440, 50, 9, 2, this);
					_repo->newPlayerObject(670, 400, 30, 100, 2, sf::Keyboard::Up,
																 sf::Keyboard::Down,
																 sf::Keyboard::Left,
																 sf::Keyboard::Right,
																 sf::Keyboard::RShift,
																 this);
					_repo->newRefereeObject(this);

					o->set(ATTR_GAMESTATE, "load", false, this);
					break;
				default:
					break;
			}
		}
	}
}