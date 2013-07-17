/*******************************************************************************

    Loading System that loads game objects in both menu and game modes

*******************************************************************************/

#ifndef LOADINGSYSTEM_H
#define LOADINGSYSTEM_H

#include "system.h"
#include "repository.h"

class LoadingSystem : public System
{
public:
	LoadingSystem(Repository *repo);
    virtual void update();
private:
	Repository *_repo;
	sf::Font *_font;
};

#endif // LOADINGSYSTEM_H
