#include"CONTAINER.h"
#include"TEXT.h"
#include"GAMEOVER.h"
#include"GAMECLEAR.h"
#include"TITLE.h"
#include"MAP.h"
#include"PLAYER.h"
#include"MURABITO1.h"
#include"MURABITO2.h"
#include"MONSTER1.h"
#include"MONSTER2.h"
#include"MONSTER3.h"
#include"BUTTLE1.h"
#include"BUTTLE2.h"
#include"BUTTLE3.h"
#include"SAIDAN.h"
#include"AITEM_WINDOW.h"
#include"GAME.h"

GAME::GAME() {
	//インスタンス化
	C = new CONTAINER;
	T = new TEXT;
	Gameover = new GAMEOVER;
	Gameclear = new GAMECLEAR;
	Title = new TITLE;
	Player = new PLAYER;
	Murabito1 = new MURABITO1;
	Murabito2 = new MURABITO2;
	Monster1 = new MONSTER1;
	Monster2 = new MONSTER2;
	Monster3 = new MONSTER3;
	Buttle1 = new BUTTLE1;
	Buttle2 = new BUTTLE2;
	Buttle3 = new BUTTLE3;
	S = new SAIDAN;
	Aitem = new AITEM_WINDOW;
	Map = new MAP;
	Title->init(C);
}
GAME::~GAME() {
	delete T;
	delete Gameover;
	delete Title;
	delete Player;
	delete Murabito1;
	delete Murabito2;
	delete Monster1;
	delete Monster2;
	delete Monster3;
	delete S;
	delete Buttle1;
	delete Buttle2;
	delete Buttle3;
	delete Aitem;
	delete Map;
	delete Gameclear;
	delete C;
}
void GAME::proc() {
	//更新
	clear();
	switch (GameState) {
	case GAME_TITLE:
		Title->draw();
		T->init(C);
		S->init(C);
		Player->init(C);
		Gameover->init(C);
		Gameclear->init(C);
		Murabito1->init(C);
		Murabito2->init(C);
		Monster1->init(C);
		Monster2->init(C);
		Monster3->init(C);
		Aitem->init(C);
		Map->init(C);
		if (isTrigger(KEY_ENTER)) {
			GameState = GAME_PLAY;
		}
		break;
	case GAME_PLAY:
		if (Player->day() != 0 && Player->okFlag() != 5) {
			Map->draw();
			Aitem->draw();
			Player->update(Murabito1, Murabito2, Monster1, Monster2, Monster3, Aitem,S);
			Murabito1->update();
			Murabito2->update();
			Monster1->update();
			Monster2->update();
			Monster3->update();
			S->draw();
			T->update(Player, Aitem);
			Player->draw();
			Murabito1->draw();
			Murabito2->draw();
			Monster1->draw();
			Monster2->draw();
			Monster3->draw();
			T->draw(Player);
			if (Player->actionFlag() == 3) {
				Buttle1->init(C, Aitem);
				GameState = GAME_BUTTLE1;
			}
			if (Player->actionFlag() == 4) {
				Buttle2->init(C, Aitem);
				GameState = GAME_BUTTLE2;
			}
			if (Player->actionFlag() == 5) {
				Buttle3->init(C, Aitem);
				GameState = GAME_BUTTLE3;
			}
		}
		if (Player->day() == 0) {
			GameState = GAME_GAMEOVER;
		}
		if (Player->okFlag() == 5) {
			GameState = GAME_GAMECLEAR;
		}
		break;
	case GAME_BUTTLE1:
		Buttle1->update(Aitem);
		Buttle1->draw();
		if (Buttle1->playerWin() == 1) {
			Monster1->setImgLife(0);
			Aitem->setKaihukuImgLife(1);
			Player->setOkFlag(2);
			Player->setActionFlag(0);
			GameState = GAME_PLAY;
		}
		else if (Buttle1->playerLose() == 1) {
			GameState = GAME_GAMEOVER;
		}
		else if (Buttle1->playerEscape() == 1) {
			Player->setActionFlag(0);
			GameState = GAME_PLAY;
		}
		break;
	case GAME_BUTTLE2:
		Buttle2->update(Aitem);
		Buttle2->draw();
		if (Buttle2->playerWin() == 1) {
			Monster2->setImgLife(0);
			Aitem->setKaihukuImgLife(1);
			Player->setActionFlag(0);
			GameState = GAME_PLAY;
		}
		else if (Buttle2->playerLose() == 1) {
			GameState = GAME_GAMEOVER;
		}
		else if (Buttle2->playerEscape() == 1) {
			Player->setActionFlag(0);
			GameState = GAME_PLAY;
		}
		break;
	case GAME_BUTTLE3:
		Buttle3->update(Aitem);
		Buttle3->draw();
		if (Buttle3->playerWin() == 1) {
			Monster3->setImgLife(0);
			Aitem->setKaihukuImgLife(1);
			Player->setActionFlag(0);
			GameState = GAME_PLAY;
		}
		else if (Buttle3->playerLose() == 1) {
			GameState = GAME_GAMEOVER;
		}
		else if (Buttle3->playerEscape() == 1) {
			Player->setActionFlag(0);
			GameState = GAME_PLAY;
		}
		break;
	case GAME_GAMEOVER:
		Gameover->draw();
		if (isTrigger(KEY_ENTER)) {
			GameState = GAME_TITLE;
		}
		break;
	case GAME_GAMECLEAR:
		Gameclear->draw();
		if (isTrigger(KEY_ENTER)) {
			GameState = GAME_TITLE;
		}
	}
}