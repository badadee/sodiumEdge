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

			//for sword rect to stay afloat
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
			int rectHeight = rect->getSize().y;
			int swordHeldBy = 0;
			int swordNum = 0;
			int otherSwordNum = 0;

			//positioning sword rectangle
			if(o->get(ATTR_SWORDSTATE,"held").toBool()){
				swordHeldBy = o->get(ATTR_SWORDSTATE,"heldBy").toInt();
				if(swordHeldBy == 1){
					otherSwordNum = 2;
					swordNum = 1;
					r = new IntRect(playerObject1->get(ATTR_POSITION, "x").toInt(),playerObject1->get(ATTR_POSITION, "y").toInt(),player1->getSize().x,player1->getSize().y);

				}else {
					swordNum = 2;
					otherSwordNum = 1;
					r = new IntRect(playerObject2->get(ATTR_POSITION, "x").toInt(),playerObject2->get(ATTR_POSITION, "y").toInt(),player2->getSize().x,player2->getSize().y);
				}
			}else{
				r = new IntRect(x,y,rect->getSize().x,rect->getSize().y+1);
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

			//now for checking sword versus sword cases
			//1. running versus sword
			//2. running versus running (first guy to stop running wins)
			//3. sword versus sword -different position(MIDDLE beats DOWN beats UP)
			//4. sword versus sword -same position (knock both back by a bit)
			//5. thrust ?
			GameObject *referee = this->getReferee();
			if(swordHeldBy ==0){
				//cout<<"sword on ground\n";
			}else if (swordHeldBy == swordNum){
				
				//gotta check if theres collision between sword vs otherPlaya
				r = new IntRect(rect->getPosition().x,rect->getPosition().y,rect->getSize().x,rect->getSize().y);
				GameObject *otherSword = this->getSword(otherSwordNum);
				RectangleShape *otherSwordRec = otherSword->get(ATTR_SPRITE,"sprite").toSprite();
				RectangleShape *otherPlayerRec = this->getPlayer(otherSwordNum)->get(ATTR_SPRITE,"sprite").toSprite();
				IntRect *otherPlayerRect = new IntRect(otherPlayerRec->getPosition().x,otherPlayerRec->getPosition().y, otherPlayerRec->getSize().x,otherPlayerRec->getSize().y);
				IntRect *otherSwordRect = new IntRect(otherSwordRec->getPosition().x,otherSwordRec->getPosition().y, otherSwordRec->getSize().x,otherSwordRec->getSize().y);
				if(r->intersects(*otherPlayerRect)){
					//code for 3
					//if other guy has up then GG for him
					if(otherSword->get(ATTR_SWORDSTATE,"up").toBool()){
						if(!o->get(ATTR_SWORDSTATE,"up").toBool()){
							referee->set(ATTR_GAMESTATE,"winner",swordNum,this);
							referee->set(ATTR_GAMESTATE,"inGame",false,this);
							cout<<"player "<<swordNum<<" wins!\n";
						}else{
							//both players have "UP" swords, so gotta bounce them back a lil

						}

						//if other guy has down 
					}else if(otherSword->get(ATTR_SWORDSTATE,"down").toBool()){
						if(!o->get(ATTR_SWORDSTATE,"down").toBool()&&!o->get(ATTR_SWORDSTATE,"up").toBool()){
							referee->set(ATTR_GAMESTATE,"winner",swordNum,this);
							referee->set(ATTR_GAMESTATE,"inGame",false,this);
							cout<<"player "<<swordNum<<" wins!\n";
						}else if(o->get(ATTR_SWORDSTATE,"up").toBool()){
							referee->set(ATTR_GAMESTATE,"winner",otherSwordNum,this);
							referee->set(ATTR_GAMESTATE,"inGame",false,this);
							cout<<"player "<<otherSwordNum<<" wins!\n";
						}else{
							//gotta bounce them back a lil
						}

						//if other guy has it straight
					}else{
						if(o->get(ATTR_SWORDSTATE,"down").toBool()||o->get(ATTR_SWORDSTATE,"up").toBool()){
							referee->set(ATTR_GAMESTATE,"winner",otherSwordNum,this);
							referee->set(ATTR_GAMESTATE,"inGame",false,this);
							cout<<"player "<<otherSwordNum<<" wins!\n";
						}else{
							//gotta bounce them back a lil
						}
					}
				}else if(r->intersects(*otherSwordRect)){
					this->bounceBackPlayer();
				}

			}



		}
	}

}
GameObject* CollisionSystem::getReferee()
{
	ObjectList::iterator i;
	for (i = _repo->beginGroup(GRP_GAMEUTIL); i != _repo->endGroup(GRP_GAMEUTIL); ++i) {
		GameObject *o = *i;

		if (o->contains(ATTR_GAMESTATE)) {
			return o;
		}
	}

	return 0;
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

void CollisionSystem::bounceBackPlayer()
{
	ObjectList::iterator i;
	int currentPosX = 0;
	int playerNum = 0;
	for (i = _repo->beginGroup(GRP_PLAYERS); i != _repo->endGroup(GRP_PLAYERS); ++i) {
		GameObject *o = *i;
		currentPosX = o->get(ATTR_POSITION, "x").toInt();
		playerNum = o->get(ATTR_PLAYERSTATE,"playerNum").toInt();
		GameObject *sword = getSword(playerNum);
		if (o->get(ATTR_PLAYERSTATE, "facing").toInt() == RIGHT) {
			o->set(ATTR_POSITION,"x", currentPosX-15, this);
			sword->set(ATTR_POSITION,"x", sword->get(ATTR_POSITION,"x").toInt()-15, this);

		}else{
			o->set(ATTR_POSITION,"x",currentPosX+ 15, this);
			sword->set(ATTR_POSITION,"x", sword->get(ATTR_POSITION,"x").toInt()+15, this);
		}
	}

	
}