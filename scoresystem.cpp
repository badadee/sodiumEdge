#include "scoresystem.h"
#include <list>
#include <iostream>
using namespace std;
using namespace sf;

ScoreSystem::ScoreSystem(Repository * repo)
{
	_repo = repo;
	_name = SYS_SCORE;

}

void ScoreSystem::update()
{
	ObjectList::iterator i;
	ObjectList::iterator j;
	ObjectList::iterator k;
	ObjectList::iterator l;
	GameObject *p = new GameObject();
	int player1score = 0;
	int player2score = 0;
	for (i = _repo->beginGroup(GRP_GAMEUTIL); i != _repo->endGroup(GRP_GAMEUTIL); ++i) {
		GameObject *o = *i;
		for (j= _repo->beginGroup(GRP_GAMESTATE); j != _repo->endGroup(GRP_GAMESTATE); ++j) {
			p = *j;

		}
		if ( o->get(ATTR_ROUNDSTATE, "roundEnd").toBool() == true){
			int roundNum = o->get(ATTR_ROUNDSTATE,"roundNum").toInt();
			o->set(ATTR_ROUNDSTATE,"roundNum",roundNum++,this);


			int score = o->get(ATTR_ROUNDSTATE,"winner").toInt();
			player1score = o->get(ATTR_ROUNDSTATE,"p1score").toInt();
			player2score = o->get(ATTR_ROUNDSTATE,"p2score").toInt();
			if(score == PLAYER1){
				player1score++;
				this->returnPlayerPos();
				o->set(ATTR_ROUNDSTATE,"p1score",player1score,this);
				o->set(ATTR_ROUNDSTATE,"roundEnd",false,this);
			}else if(score == PLAYER2){
				player2score++;
				this->returnPlayerPos();
				o->set(ATTR_ROUNDSTATE,"p2score",player2score,this);
				o->set(ATTR_ROUNDSTATE,"roundEnd",false,this);
			}else if(score == DKO){
				player2score++;
				player1score++;
				this->returnPlayerPos();
				o->set(ATTR_ROUNDSTATE,"p2score",player2score,this);
				o->set(ATTR_ROUNDSTATE,"p1score",player1score,this);
				o->set(ATTR_ROUNDSTATE,"roundEnd",false,this);
				
			}
			if(player1score == 3){
			/*o->set(ATTR_ROUNDSTATE,"GrandWinner",PLAYER1,this);
			for (k = _repo->beginGroup(GRP_ROUNDDISP); k != _repo->endGroup(GRP_ROUNDDISP); ++k) {
			GameObject *o = *k;
			if(o->get(ATTR_ROUNDSTATE,"winner").toInt() == PLAYER1){
			o->set(ATTR_ROUNDSTATE,"visible",true,this);
			}
			}*/
				p->set(ATTR_GAMESTATE, "inGame", false, this);
				p->set(ATTR_GAMESTATE, "load", true, this);
			}else if (player2score == 3){
			/*o->set(ATTR_ROUNDSTATE,"GrandWinner",PLAYER2,this);
			for (l = _repo->beginGroup(GRP_ROUNDDISP); l != _repo->endGroup(GRP_ROUNDDISP); ++l) {
			GameObject *o = *l;
			if(o->get(ATTR_ROUNDSTATE,"winner").toInt() == PLAYER2){
			o->set(ATTR_ROUNDSTATE,"visible",true,this);
			}
			}*/
				p->set(ATTR_GAMESTATE, "inGame", false, this);
				p->set(ATTR_GAMESTATE, "load", true, this);

			}
		}
	}
}

void ScoreSystem::returnPlayerPos (){
	ObjectList::iterator j;
	ObjectList::iterator k;
	for (j= _repo->beginGroup(GRP_PLAYERS); j != _repo->endGroup(GRP_PLAYERS); ++j) {
		GameObject *p = *j;
		if(p->get(ATTR_PLAYERSTATE,"playerNum").toInt() == 1){
			p->set(ATTR_POSITION,"x",100, this);
			p->set(ATTR_POSITION,"y",400, this);
		}else{
			p->set(ATTR_POSITION,"x",670, this);
			p->set(ATTR_POSITION,"y",400, this);
		}
	}
	for (j= _repo->beginGroup(GRP_SWORDS); j != _repo->endGroup(GRP_SWORDS); ++j) {
		GameObject *p = *j;
		if(p->get(ATTR_SWORDSTATE,"heldBy").toInt() == 1){
			p->set(ATTR_POSITION,"x",130, this);
			p->set(ATTR_POSITION,"y",440, this);
		}else{
			p->set(ATTR_POSITION,"x",620, this);
			p->set(ATTR_POSITION,"y",440, this);
		}
	}
}