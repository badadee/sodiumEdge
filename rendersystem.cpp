#include <iostream>
#include "rendersystem.h"

using namespace sf;

RenderSystem::RenderSystem(Repository *repo, sf::RenderWindow *window)
{
    _repo = repo;
	_window = window;
}

void RenderSystem::update()
{
	ObjectList::iterator i;

	//Drawing Sprites
    for (i = _repo->beginGroup(GRP_RENDERSPRITE); i != _repo->endGroup(GRP_RENDERSPRITE); ++i) {
        GameObject *o = *i;
		sf::RectangleShape *sprite = o->get(ATTR_SPRITE, "sprite").toSprite();
		int x = o->get(ATTR_POSITION, "x").toInt();
		int y = o->get(ATTR_POSITION, "y").toInt();
		int width = o->get(ATTR_RECTANGLE, "width").toInt();
		int height = o->get(ATTR_RECTANGLE, "height").toInt();

		sprite->setSize(sf::Vector2f((float)width, (float)height));
		sprite->setPosition((float)x, (float)y);

		_window->draw(*sprite);
    }

	//Changing menu selection colors
	for (i = _repo->beginGroup(GRP_MENUTEXT); i != _repo->endGroup(GRP_MENUTEXT); ++i) {
        GameObject *o = *i;
		sf::Text *text = o->get(ATTR_TEXT, "text").toText();
		bool selected = o->get(ATTR_SELECTION, "selected").toBool();

		if (selected) {
			text->setColor(sf::Color::Cyan);
		} else {
			text->setColor(sf::Color::White);
		}

		_window->draw(*text);
    }

	//Updating score
	for (i = _repo->beginGroup(GRP_MENUSCORE); i != _repo->endGroup(GRP_MENUSCORE); ++i) {
		GameObject *menuScore = *i;

		int score = menuScore->get(ATTR_MENUSCORE, "score").toInt();
		sf::Text *text = menuScore->get(ATTR_TEXT, "text").toText();

		text->setString(std::to_string(score));
	}		

	//Drawing Text
	for (i = _repo->beginGroup(GRP_RENDERTEXT); i != _repo->endGroup(GRP_RENDERTEXT); ++i) {
        GameObject *o = *i;
		sf::Text *text = o->get(ATTR_TEXT, "text").toText();

		_window->draw(*text);
    }
}