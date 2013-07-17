/*******************************************************************************

    Physics System
    Handles movement of game objects

*******************************************************************************/

#ifndef SCORESYSTEM_H
#define SCORESYSTEM_H

#include "system.h"
#include "repository.h"

class ScoreSystem : public System
{
public:
	ScoreSystem(Repository *repo);
    virtual void update();
private:
	Repository *_repo;
};

#endif // PHYSICSSYSTEM_H