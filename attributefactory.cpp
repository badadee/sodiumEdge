#include "attributefactory.h"

// Creates a new instance of an attribute based on the suppied attribute type
Attribute* AttributeFactory::create(AttributeType type)
{
    Attribute *newAttribute = new Attribute;
    switch (type) {

        case ATTR_POSITION:
            (*newAttribute)["x"] = 0;
            (*newAttribute)["y"] = 0;
			break;

        case ATTR_RECTANGLE:
            (*newAttribute)["width"] = 0;
            (*newAttribute)["height"] = 0;
            break;

		case ATTR_VELOCITY:
			(*newAttribute)["xVelocity"] = 0;
			(*newAttribute)["yVelocity"] = 0;
			break;

		case ATTR_PLAYERSTATE:
			(*newAttribute)["playerNum"] = 0;		//1 for player1, 2 for player2
			(*newAttribute)["jumping"] = 0;			//bool true for jumping in the air, default false for on the ground
			(*newAttribute)["onPlatform"] = 0;
			(*newAttribute)["facing"] = 0;	
			break;

		case ATTR_SPRITE:
			(*newAttribute)["sprite"] = 0;			//will contain sf::RectangleShape
			break;

		case ATTR_STATIC:
			(*newAttribute)["static"] = 0;			//bool true for static solid object
			break;

		case ATTR_SWORDSTATE:
			(*newAttribute)["heldBy"] = 0;			//1 for player1, 2 for player2
			(*newAttribute)["thrustFrame"] = 0;		//int frames left until thrust completes
			(*newAttribute)["up"] = 0;				//bool true for sword held up
			(*newAttribute)["down"] = 0;			//bool true for sword held down
			break;

		case ATTR_GRAVITY:
			(*newAttribute)["gravity"] = 0;			//bool true for affected by gravity
			break;

		case ATTR_ROUNDSTATE:
			(*newAttribute)["roundEnd"] = 0;
			(*newAttribute)["winner"] = 0;
			(*newAttribute)["paused"] = 0;
			(*newAttribute)["p1score"] = 0;
			(*newAttribute)["p2score"] = 0;
			(*newAttribute)["roundNum"] = 0;
			break;

		case ATTR_GAMESTATE:
			(*newAttribute)["inGame"] = 0;			//bool true for in game, default false for in menu
			(*newAttribute)["load"] = 0;			//bool true for loading needed on current frame, default false for no load required
			break;

		case ATTR_KEYMAP:
			(*newAttribute)["up"] = 0;				//sf::Keyboard::Key enum for mapping key to player attribute
			(*newAttribute)["down"] = 0;
			(*newAttribute)["left"] = 0;
			(*newAttribute)["right"] = 0;
			(*newAttribute)["jump"] = 0;
			(*newAttribute)["thrust"] = 0;
			(*newAttribute)["bMenu"] = 0;
			break;

		case ATTR_TEXT:
			(*newAttribute)["text"] = 0;			//sf::Text object for displaying menu and score
			break;

		case ATTR_SELECTION:
			(*newAttribute)["selected"] = 0;		//bool true for selected menu object, default false except for first menu object
			(*newAttribute)["menuNum"] = 0;			//int menu number
			break;

		case ATTR_MENUACTION:
			(*newAttribute)["startGame"] = 0;		//bool true for initiating game start from menu, default false
			(*newAttribute)["clearWins"] = 0;		//bool true for clearing player 1 and 2 wins from menu, default false
			break;

		case ATTR_MENUSCORE:
			(*newAttribute)["score"] = 0;
			break;
        // invalid AttributeType
        default:
            delete newAttribute;
            return 0;
    }

	return newAttribute;
}
