/*******************************************************************************

    enums for component types;

*******************************************************************************/

#ifndef ENUMS_H
#define ENUMS_H

enum AttributeType {
    ATTR_POSITION,
    ATTR_RECTANGLE,
	ATTR_VELOCITY,
	ATTR_ROUNDSTATE,
	ATTR_GAMESTATE,
	ATTR_PLAYERSTATE,
	ATTR_KEYMAP,
	ATTR_SPRITE,
	ATTR_TEXT,
	ATTR_STATIC,
	ATTR_SWORDSTATE,
	ATTR_GRAVITY
};

enum DirectionType{
	RIGHT,
	LEFT
};

enum WinnerType {
	NOBODY,
	PLAYER1,
	PLAYER2
};
enum GroupType {
	GRP_GAMESTATE,
	GRP_PLAYERS,
	GRP_SWORDS,
	GRP_PHYSICS,
	GRP_RENDERSPRITE,
	GRP_RENDERTEXT,
	GRP_PLATFORM,
	GRP_GAMEUTIL
};

enum SystemType {
    SYS_TEST,
	USER_INPUT
};

#endif // ENUMS_H
