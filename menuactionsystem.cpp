#include <iostream>
#include "menuactionsystem.h"
#include "statisticsio.h"

MenuActionSystem::MenuActionSystem(Repository *repo)
{
    _repo = repo;
}

void MenuActionSystem::update()
{
	ObjectList::iterator i;
	ObjectList::iterator j;

	//Drawing Sprites
    for (i = _repo->beginGroup(GRP_MENUACTION); i != _repo->endGroup(GRP_MENUACTION); ++i) {
        GameObject *menuAction = *i;
		bool gameStart = menuAction->get(ATTR_MENUACTION, "startGame").toBool();
		bool clearWins = menuAction->get(ATTR_MENUACTION, "clearWins").toBool();

		if (gameStart) {
			for (j = _repo->beginGroup(GRP_GAMESTATE); j != _repo->endGroup(GRP_GAMESTATE); ++j) {
				GameObject *gameState = *j;

				gameState->set(ATTR_GAMESTATE, "inGame", true, this);
				gameState->set(ATTR_GAMESTATE, "load", true, this);
			}				
		}

		if (clearWins) {
			for (j = _repo->beginGroup(GRP_MENUSCORE); j != _repo->endGroup(GRP_MENUSCORE); ++j) {
				GameObject *menuScore = *j;
				StatisticsIO *file = new StatisticsIO("scores.txt");
				file->setPlayerOneScore(0);
				file->setPlayerTwoScore(0);

				menuScore->set(ATTR_MENUSCORE, "score", 0, this);
			}			
		}
    }
}