#include"CONTAINER.h"
#include"TEXT.h"
#include"GAMEOVER.h"
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
#include"GAME.h"

GAME::GAME() {
	//インスタンス化
	C = new CONTAINER;
	T = new TEXT;
	Gameover = new GAMEOVER;
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
	delete Buttle1;
	delete Buttle2;
	delete Buttle3;
	delete Map;
	delete C;
}
void GAME::proc() {
	//更新
	clear();
	switch (GameState) {
	case GAME_TITLE:
		Title->draw();
		T->init(C);
		Player->init(C);
		Gameover->init(C);
		Murabito1->init(C);
		Murabito2->init(C);
		Monster1->init(C);
		Monster2->init(C);
		Monster3->init(C);
		Map->init(C);
		if (isTrigger(KEY_ENTER)) {
			GameState = GAME_PLAY;
		}
		break;
	case GAME_PLAY:
		Map->draw();
		Player->update(Murabito1, Murabito2, Monster1, Monster2, Monster3);
		Murabito1->update();
		Murabito2->update();
		Monster1->update();
		Monster2->update();
		Monster3->update();
		T->update(Player);
		Player->draw();
		Murabito1->draw();
		Murabito2->draw();
		Monster1->draw();
		Monster2->draw();
		Monster3->draw();
		T->draw(Player);
		if (Player->actionFlag() == 3) {
			Buttle1->init(C);
			GameState = GAME_BUTTLE1;
		}
		if (Player->actionFlag() == 4) {
			Buttle2->init(C);
			GameState = GAME_BUTTLE2;
		}
		if (Player->actionFlag() == 5) {
			Buttle3->init(C);
			GameState = GAME_BUTTLE3;
		}
		break;
	case GAME_BUTTLE1:
			Buttle1->update();
			Buttle1->draw();
		if (Buttle1->playerWin() == 1) {
			Monster1->setImgLife(0);
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
		Buttle2->update();
		Buttle2->draw();
		if (Buttle2->playerWin() == 1) {
			Monster2->setImgLife(0);
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
		Buttle3->update();
		Buttle3->draw();
		if (Buttle3->playerWin() == 1) {
			Monster3->setImgLife(0);
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
	}
}