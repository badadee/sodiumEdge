/*******************************************************************************

    MenuAction System
	Handles Actions at the Main Menu

*******************************************************************************/

#ifndef MENUACTIONSYSTEM_H
#define MENUACTIONSYSTEM_H

#include "system.h"
#include "repository.h"

class MenuActionSystem : public System
{
public:
	MenuActionSystem(Repository *repo);
    virtual void update();
private:
	Repository *_repo;
};

#endif // MENUACTIONSYSTEM_H
