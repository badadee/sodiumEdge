#include <iostream>
#include <signal.h>
#include "loadingsystem.h"

LoadingSystem::LoadingSystem(Repository *repo)
{
	sf::Font *font = new sf::Font();

	if (!font->loadFromFile("visitor1.ttf"))
	{
		std::cout << "CANNOT OPEN FONT FILE" << std::endl;
		raise(SIGABRT);
	}

	_font = font;
    _repo = repo;
}

void LoadingSystem::update()
{
	ObjectList::iterator i = _repo->beginGroup(GRP_GAMESTATE);
	GameObject *o = *i;

	if (o->get(ATTR_GAMESTATE, "load").toBool()) {
		switch (o->get(ATTR_GAMESTATE, "inGame").toBool()) {
			case false:
				_repo->clean();
				_repo->newMenuObject(230, 20, 100, 0, false, false, _font, "SODIUM", this);
				_repo->newMenuObject(250, 90, 100, 0, false, false, _font, "EDGE", this);
				_repo->newMenuObject(300, 300, 30, 1, true, true, _font, "START GAME", this);
				_repo->newMenuObject(300, 330, 30, 2, true, false, _font, "CLEAR WINS", this);
				_repo->newMenuActionObject(this);
				_repo->newGameStateObject(false, false, this);

				break;

			case true:		
				_repo->clean();
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
				_repo->newGameStateObject(true, false, this);

				break;
		}
	}
}