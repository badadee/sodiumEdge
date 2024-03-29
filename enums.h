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
	ATTR_SELECTION,
	ATTR_MENUACTION,
	ATTR_MENUSCORE,
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
	PLAYER2,
	DKO
};
enum GroupType {
	GRP_GAMESTATE,
	GRP_PLAYERS,
	GRP_SWORDS,
	GRP_MENU,
	GRP_MENUACTION,
	GRP_MENUSCORE,
	GRP_PHYSICS,
	GRP_RENDERSPRITE,
	GRP_RENDERTEXT,
	GRP_MENUTEXT,
	GRP_PLATFORM,
	GRP_GAMEUTIL
};

enum SystemType {
	SYS_COLLISION,
	SYS_INPUT,
	SYS_LOADING,
	SYS_MENU,
	SYS_PHYSICS,
	SYS_RENDER,
	SYS_SCORE
};

#endif // ENUMS_H
