#include "collisionsystem.h"
#include <list>
#include <iostream>
using namespace std;
using namespace sf;

CollisionSystem::CollisionSystem(Repository * repo)
{
	_repo = repo;
}

void CollisionSystem::update()
{
	ObjectList::iterator i;
	list<GameObject*>::iterator pi;
	list<GameObject*> platforms;
	RectangleShape *rect;
	RectangleShape *platformRect;

	IntRect *r;
	IntRect *p;
	IntRect result;
	static int counter = 0;

	//populating list of platforms
	for (i = _repo->beginGroup(GRP_PLATFORM); i != _repo->endGroup(GRP_PLATFORM); ++i) {
		platforms.push_back(*i);
	}

	//This loop is for every object interacting with physics
	for (i = _repo->beginGroup(GRP_PHYSICS); i != _repo->endGroup(GRP_PHYSICS); ++i) {
		GameObject *o = *i;
		//for playa rect
		if (o->contains(ATTR_PLAYERSTATE)){
			rect = o->get(ATTR_SPRITE,"sprite").toSprite();

			int x = o->get(ATTR_POSITION, "x").toInt();
			int y = o->get(ATTR_POSITION, "y").toInt();

			r = new IntRect(x,y,rect->getSize().x,rect->getSize().y);

			//check rectangle object against all platform rectangules for collision
			for(pi = platforms.begin(); pi != platforms.end(); ++pi){
				GameObject *pl = *pi;
				platformRect = pl->get(ATTR_SPRITE,"sprite").toSprite();
				p = new IntRect (pl->get(ATTR_POSITION, "x").toInt(),pl->get(ATTR_POSITION, "y").toInt(),
					platformRect->getSize().x,platformRect->getSize().y);

				//check for intersection
				if(r->intersects(*p,result))
				{
					o->set(ATTR_POSITION, "y", y-result.height, this);
					if(o->get(ATTR_PLAYERSTATE,"jumping").toBool()){
						o->set(ATTR_PLAYERSTATE,"jumping",false,this);
					}
				}
				if((r->left >= (p->left+p->width))||(r->left+r->width <= p->left)){
					o->set(ATTR_PLAYERSTATE,"onPlatform", false, this);
					o->set(ATTR_PLAYERSTATE,"jumping",true,this);
					GameObject *swordObject = this->getSword(o->get(ATTR_PLAYERSTATE,"playerNum").toInt());
					swordObject->set(ATTR_SWORDSTATE,"held",false,this);
					int w = 0;
				}else{
					o->set(ATTR_PLAYERSTATE,"onPlatform", true, this);
				}

			}

			//for sword rect
		}else if(o->contains(ATTR_SWORDSTATE)){
			rect = o->get(ATTR_SPRITE,"sprite").toSprite();

			int x = o->get(ATTR_POSITION, "x").toInt();
			int y = o->get(ATTR_POSITION, "y").toInt();
			GameObject *playerObject1 = this->getPlayer(1);
			RectangleShape *player1 = playerObject1->get(ATTR_SPRITE, "sprite").toSprite();
			GameObject *playerObject2 = this->getPlayer(2);
			RectangleShape *player2 = playerObject2->get(ATTR_SPRITE, "sprite").toSprite();
			int player1x = player1->getSize().x;
			int player2x = player2->getSize().x;

			if(o->get(ATTR_SWORDSTATE,"held").toBool()){
				if(o->get(ATTR_SWORDSTATE,"heldBy").toInt() == 1){
					

					if(o->get(ATTR_SWORDSTATE,"up").toBool()){
						r = new IntRect(x-player1x,y,rect->getSize().x+player1x,rect->getSize().y+70);
					}
					else if(o->get(ATTR_SWORDSTATE,"down").toBool()){
						r = new IntRect(x-player1x,y,rect->getSize().x+player1x,rect->getSize().y+50);
					}else{
						r = new IntRect(x-player1x,y,rect->getSize().x+player1x,rect->getSize().y+60);
					}
				}else {
					if(o->get(ATTR_SWORDSTATE,"up").toBool()){
						r = new IntRect(x,y,rect->getSize().x+player2x,rect->getSize().y+70);
					}
					else if(o->get(ATTR_SWORDSTATE,"down").toBool()){
						r = new IntRect(x,y,rect->getSize().x+player2x,rect->getSize().y+50);
					}else{
						r = new IntRect(x,y,rect->getSize().x+player2x,rect->getSize().y+60);
					}
				}
			}else{
				r = new IntRect(x,y,rect->getSize().x,rect->getSize().y);
			}
			//check rectangle object against all platform rectangules for collision
			for(pi = platforms.begin(); pi != platforms.end(); ++pi){
				GameObject *pl = *pi;
				platformRect = pl->get(ATTR_SPRITE,"sprite").toSprite();
				p = new IntRect (pl->get(ATTR_POSITION, "x").toInt(),pl->get(ATTR_POSITION, "y").toInt(),
					platformRect->getSize().x,platformRect->getSize().y);

				//check for intersection
				if(r->intersects(*p,result))
				{
					o->set(ATTR_POSITION, "y", y-result.height, this);
				}
			}
		}
	}

}

GameObject* CollisionSystem::getSword(int playerNum)
{
	ObjectList::iterator i;
	for (i = _repo->beginGroup(GRP_SWORDS); i != _repo->endGroup(GRP_SWORDS); ++i) {
		GameObject *o = *i;

		if (o->get(ATTR_SWORDSTATE, "heldBy").toInt() == playerNum) {
			return o;
		}
	}

	return 0;
}
GameObject* CollisionSystem::getPlayer(int playerNum)
{
	ObjectList::iterator i;
	for (i = _repo->beginGroup(GRP_PLAYERS); i != _repo->endGroup(GRP_PLAYERS); ++i) {
		GameObject *o = *i;

		if (o->get(ATTR_PLAYERSTATE, "playerNum").toInt() == playerNum) {
			return o;
		}
	}

	return 0;
}