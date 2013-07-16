#include <iostream>
#include <list>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "gameinitializer.h"
#include "repository.h"

int main()
{
	Repository *repo = GameInitializer::initializeRepository();
	sf::RenderWindow *window = GameInitializer::initializerWindow();
	std::list<System*> systemList = GameInitializer::initializeGameSystems(window, repo);
	std::list<System*>::iterator i;

	repo->newPlatformObject(100, 500, 600, 100, *systemList.begin());
    repo->newSwordObject(130, 440, 50, 9, 1, *systemList.begin());
    repo->newPlayerObject(100, 400, 30, 100, 1, *systemList.begin());
    repo->newSwordObject(620, 440, 50, 9, 2, *systemList.begin());
    repo->newPlayerObject(670, 400, 30, 100, 2, *systemList.begin());
    repo->newRefereeObject(*systemList.begin());

    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }

        window->clear();

		for (i=systemList.begin(); i!=systemList.end(); ++i)
		{
			System *s = *i;
			s->update();
		}

        window->display();
    }

	return 0;
}
