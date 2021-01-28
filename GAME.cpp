#include"input.h"
#include"CONTAINER.h"
#include"TITLE.h"
#include"MAP.h"
#include"CHARAMAP.h"
#include"CHARACTER_MANAGER.h"
#include"GAME.h"

GAME::GAME() {
	C = new CONTAINER;
	Title = new TITLE;
	Map = new MAP;
	CharaMap = new CHARAMAP;
	Charas = new CHARACTER_MANAGER;
}
GAME::~GAME() {
	delete Map;
	delete Charas;
	delete CharaMap;
	delete Title;
	delete C;
}
void GAME::proc() {
	clear();
	switch (GameState) {
	case GAME_STATE_TITLE:
		Title->draw();
		if (isTrigger(KEY_Z)) {
			Map->init();
			CharaMap->init();
			GameState = GAME_STATE_PLAY;
		}
		break;
	case GAME_STATE_PLAY:
		Map->draw();
		CharaMap->draw();
		Charas->update();
		Charas->draw();
		break;
	}
}