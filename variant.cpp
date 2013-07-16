#include <iostream>
#include "variant.h"

/*************************************************************** CONSTRUCTORS */

Variant::Variant()							{}
Variant::Variant(int val)					{ _type = "int";    _int = val; }
Variant::Variant(double val)				{ _type = "double"; _double = val; }
Variant::Variant(const char* val)			{ _type = "string"; _str = val; }
Variant::Variant(bool val)					{ _type = "bool"; _bool = val; }
Variant::Variant(sf::RectangleShape *val)	{ _type = "sprite"; _sprite = val; }
Variant::Variant(sf::Text *val)				{ _type = "text"; _text = val; }

/******************************************************************** GETTERS */

std::string Variant::toString()				{ return _str; }
int Variant::toInt()						{ return _int; }
double Variant::toDouble()					{ return _double; }
bool Variant::toBool()						{ return _bool; }
sf::RectangleShape* Variant::toSprite()		{ return _sprite; }
sf::Text* Variant::toText()					{ return _text; }
