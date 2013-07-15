/*******************************************************************************

    System (NOT DONE YET);
    does all kinds of crap

*******************************************************************************/

#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>
#include "enums.h"

class System
{
public:
	virtual ~System() {};
    virtual void update() = 0;

private:
    SystemType _name;
};

#endif // SYSTEM_H
