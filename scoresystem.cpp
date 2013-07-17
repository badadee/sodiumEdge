#include "scoresystem.h"
#include <list>
#include <iostream>
using namespace std;
using namespace sf;

ScoreSystem::ScoreSystem(Repository * repo)
{
	_repo = repo;
}

void ScoreSystem::update()
{
	ObjectList::iterator i;
	int player1score = 0;
	int player2score = 0;
	for (i = _repo->beginGroup(GRP_GAMEUTIL); i != _repo->endGroup(GRP_GAMEUTIL); ++i) {
		GameObject *o = *i;
		if ( o->get(ATTR_ROUNDSTATE, "roundend").toBool() == true){
			int roundNum = o->get(ATTR_ROUNDSTATE,"roundNum").toInt();
			o->set(ATTR_ROUNDSTATE,"roundNum",roundNum++,this);


			int score = o->get(ATTR_ROUNDSTATE,"winner").toInt();
			player1score = o->get(ATTR_ROUNDSTATE,"p1score").toInt();
			player2score = o->get(ATTR_ROUNDSTATE,"p2score").toInt();
			if(score == PLAYER1){
				player1score++;
				o->set(ATTR_ROUNDSTATE,"p1score",player1score,this);
			}else if(score == PLAYER2){
				player2score++;
				o->set(ATTR_ROUNDSTATE,"p2score",player2score,this);
			}else if(score == DKO){
				player2score++;
				player1score++;
				o->set(ATTR_ROUNDSTATE,"p2score",player2score,this);
				o->set(ATTR_ROUNDSTATE,"p1score",player1score,this);
			}
			if(player1score == 3){
				o->set(ATTR_ROUNDSTATE,"GrandWinner",PLAYER1,this);
				for (i = _repo->beginGroup(GRP_ROUNDDISP); i != _repo->endGroup(GRP_ROUNDDISP); ++i) {
					GameObject *o = *i;
					if(o->get(ATTR_ROUNDSTATE,"winner").toInt() == PLAYER1){
						o->set(ATTR_ROUNDSTATE,"visible",true,this);
					}
				}
			}else if (player2score == 3){
				o->set(ATTR_ROUNDSTATE,"GrandWinner",PLAYER2,this);
				for (i = _repo->beginGroup(GRP_ROUNDDISP); i != _repo->endGroup(GRP_ROUNDDISP); ++i) {
					GameObject *o = *i;
					if(o->get(ATTR_ROUNDSTATE,"winner").toInt() == PLAYER2){
						o->set(ATTR_ROUNDSTATE,"visible",true,this);
					}
				}
			}
		}
	}
}