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
			(*newAttribute)["jumping"] = 0;			//bool true for jumping in the air
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
			break;
        // invalid AttributeType
        default:
            delete newAttribute;
            return 0;
    }

	return newAttribute;
}
