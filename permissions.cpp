#include "permissions.h"
#include "enums.h"

bool Permissions::isAllowed(AttributeType attribute, System *system)
{
	if (system->type() == SYS_COLLISION) {
		if (attribute = ATTR_POSITION) return true;
		else if (attribute = ATTR_RECTANGLE) return true;
		else if (attribute = ATTR_ROUNDSTATE) return true;
	}else if (system->type() == SYS_SCORE){
		if (attribute = ATTR_POSITION) return true;
		else if (attribute = ATTR_ROUNDSTATE) return true;
		else if (attribute = ATTR_GAMESTATE) return true;
		else if (attribute = ATTR_PLAYERSTATE) return true;
		else if (attribute = ATTR_SWORDSTATE) return true;
	
	} else if (system->type() == SYS_INPUT) {
		if (attribute = ATTR_VELOCITY) return true;
		else if (attribute = ATTR_PLAYERSTATE) return true;
		else if (attribute = ATTR_SWORDSTATE) return true;
		else if (attribute = ATTR_SELECTION) return true;
		else if (attribute = ATTR_MENUACTION) return true;

	} else if (system->type() == SYS_LOADING) {
		return true; // loading system can create any object

	} else if (system->type() == SYS_MENU) {
		if (attribute = ATTR_GAMESTATE) return true;

	} else if (system->type() == SYS_PHYSICS) {
		if (attribute = ATTR_POSITION) return true;
		else if (attribute = ATTR_VELOCITY) return true;

	} else {
		return false;
	}
}
