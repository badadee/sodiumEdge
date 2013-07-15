/*******************************************************************************

    Render System
    Draws sprites for each frame

*******************************************************************************/

#ifndef RENDERSYSTEM_H
#define RENDERSYSTEM_H

#include "system.h"
#include "repository.h"

class RenderSystem : public System
{
public:
	RenderSystem(Repository *repo, sf::RenderWindow *window);
    virtual void update();
private:
	Repository *_repo;
	sf::RenderWindow *_window;
};

#endif // RENDERSYSTEM_H
