/*******************************************************************************

    enums for component types;

*******************************************************************************/

#ifndef ENUMS_H
#define ENUMS_H

enum AttributeType {
    ATTR_POSITION,
    ATTR_RECTANGLE,
	ATTR_VELOCITY,
	ATTR_PLAYERSTATE,
	ATTR_SPRITE,
	ATTR_STATIC,
	ATTR_SWORDSTATE,
	ATTR_GRAVITY
};

enum GroupType {
	GRP_PLAYERS,
	GRP_SWORDS,
	GRP_PHYSICS,
	GRP_RENDER,
	GRP_PLATFORM
};

enum SystemType {
    SYS_TEST,
	USER_INPUT
};

#endif // ENUMS_H
