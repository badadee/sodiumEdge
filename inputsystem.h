/*******************************************************************************

    Input System
    Accepts user input

*******************************************************************************/

#ifndef INPUTSYSTEM_H
#define INPUTSYSTEM_H

#include "system.h"
#include "repository.h"

class InputSystem : public System
{
public:
	InputSystem(Repository *repo);
    virtual void update();
private:
	Repository *_repo;
	GameObject* getSword(int playerNum);
};

#endif // INPUTSYSTEM_H
