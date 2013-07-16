/*******************************************************************************

    Object that can store multiple types of data;
    mostly consists of a bunch of constructors and getters for each type

*******************************************************************************/

#ifndef VARIANT_H
#define VARIANT_H

#include <string>
#include <SFML/Graphics.hpp>

class Variant
{
public:
    Variant();
    Variant(int val);
    Variant(double val);
    Variant(const char *val);
	Variant(bool val);
	Variant(sf::RectangleShape *val);
	Variant(sf::Text *val);
    std::string toString();
    int toInt();
    double toDouble();
	bool toBool();
	sf::RectangleShape* toSprite();
	sf::Text* toText();

private:
    std::string _type;
    int _int;
    double _double;
    std::string _str;
	bool _bool;
	sf::RectangleShape *_sprite;
	sf::Text *_text;
};

#endif // VARIANT_H
