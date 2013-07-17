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