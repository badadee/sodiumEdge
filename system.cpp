#include "system.h"

System::System(SystemType name)
{
    _name = name;
}

void System::update(double dt)
{

}

SystemType System::identifier()
{
    return _name;
}
