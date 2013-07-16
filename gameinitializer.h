/*******************************************************************************

    Initializes game systems and passes back a list of systems

*******************************************************************************/
#include <list>
#include <SFML/Graphics.hpp>
#include "system.h"
#include "repository.h"

#ifndef GAMEINITIALIZER_H
#define GAMEINITIALIZER_H

class GameInitializer
{
public:
	static Repository* initializeRepository();
	static sf::RenderWindow* initializerWindow();
	static std::list<System*> initializeGameSystems(sf::RenderWindow *window, Repository *repo);
};

#endif // GAMEINITIALIZER_H
