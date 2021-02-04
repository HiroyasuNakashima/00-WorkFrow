#include"input.h"
#include"CONTAINER.h"
#include"CHARACTER.h"
#include"PLAYER.h"
#include"MURABITO1.h"
#include"MURABITO2.h"
#include"MONSTER1.h"
#include"MONSTER2.h"
#include"MONSTER3.h"
#include"ALTAR.h"
#include"TEXT_READ.h"
#include"CHARACTER_MANAGER.h"
CONTAINER* CHARACTER_MANAGER::C = 0;

CHARACTER_MANAGER::CHARACTER_MANAGER() {
	PlayerChipSize = C->playerChipSize;
	Total += C->numPlayers;
	Total += C->numMurabito1;
	Total += C->numMurabito2;
	Total += C->numMonster1;
	Total += C->numMonster2;
	Total += C->numMonster3;
	Total += C->numAltar;
	Charas = new CHARACTER*[Total];
	int i, j = 0;
	for (i = 0; i < C->numPlayers; i++) { Charas[j++] = new PLAYER; }
	for (i = 0; i < C->numMurabito1; i++) { Charas[j++] = new MURABITO1; }
	for (i = 0; i < C->numMurabito2; i++) { Charas[j++] = new MURABITO2; }
	for (i = 0; i < C->numMonster1; i++) { Charas[j++] = new MONSTER1; }
	for (i = 0; i < C->numMonster2; i++) { Charas[j++] = new MONSTER2; }
	for (i = 0; i < C->numMonster3; i++) { Charas[j++] = new MONSTER3; }
	for (i = 0; i < C->numAltar; i++) { Charas[j++] = new ALTAR; }
	CHARAMAP::setCharacterManager(this);
	Conv = new TEXT_READ;
}
CHARACTER_MANAGER::~CHARACTER_MANAGER() {
	delete Conv;
	for (int i = 0; i < Total; i++) {
		delete Charas[i];
	}
	delete[] Charas;
}
void CHARACTER_MANAGER::init() {
	for (int i = 0; i < Total; i++) {
		Charas[i]->init();
	}
}
void CHARACTER_MANAGER::appear( char charaId, float px, float py, float dx, float dy) {
	for (int i = 0; i < Total; i++) {
		if (Charas[i]->charaId() == charaId) {
			if (Charas[i]->alpha() <= 0.0f) {
				Charas[i]->appear(px, py, dx, dy);
				break;
			}
		}
	}
}
void CHARACTER_MANAGER::update() {
	for (int i = 0; i < Total; i++) {
		if (Charas[i]->alpha() > 0.0f) {
			Charas[i]->update();
		}
	}
	//Zキーを押してPLAYERと他キャラが一定距離内に居たら向かい合わせる
	if (isTrigger(KEY_Z)) {
		playerAction(Charas[0]->animId());
		Conv->init();
		Flag = 1;
	}
}
void CHARACTER_MANAGER::draw() {
	for (int i = 0; i < Total; i++) {
		if (Charas[i]->alpha() > 0.0f) {
			Charas[i]->draw();
		}
	}
	if (Flag == 1) {
		Conv->draw();
		if (isTrigger(KEY_X)) {
			Flag = 0;
		}
	}
}
void CHARACTER_MANAGER::playerAction(int animId) {//受け取ったanimIdと他キャラを向かい合わせる
	int nextPx = Charas[0]->px();
	int nextPy = Charas[0]->py();
	for (int i = 1; i < Total; i++) {
		//PLAYERと他キャラの距離を測る
		int dx = Charas[i]->px() - Charas[0]->px();
		int dy = Charas[i]->py() - Charas[0]->py();
		int len = sqrt(dx * dx + dy * dy);
		if (len < PlayerChipSize + 1) {//一定距離内に居たら
			//画像の向きからPLAYERの方向を得る
			if (animId == 0) {
				nextPy += PlayerChipSize;
			}
			if (animId == 1) {
				nextPy -= PlayerChipSize;
			}
			if (animId == 2) {
				nextPx += PlayerChipSize;
			}
			if (animId == 3) {
				nextPx -= PlayerChipSize;
			}
			//PLAYERが向いている方向に他キャラが居たら他キャラを向かせる
			if (nextPx == Charas[i]->px() || nextPy == Charas[i]->py()) {
				if (Charas[0]->animId() == 0) {
					Charas[i]->setAnimId(1);
					TextCharaId = Charas[i]->charaId();//charaIdを取得し、会話内容を確定させる。
					break;
				}
				if (Charas[0]->animId() == 1) {
					Charas[i]->setAnimId(0);
					TextCharaId = Charas[i]->charaId();
					break;
				}
				if (Charas[0]->animId() == 2) {
					Charas[i]->setAnimId(3);
					TextCharaId = Charas[i]->charaId();
					break;
				}
				if (Charas[0]->animId() == 3) {
					Charas[i]->setAnimId(2);
					TextCharaId = Charas[i]->charaId();
					break;
				}
			}
		}
	}
}

char CHARACTER_MANAGER::textCharaId() { return TextCharaId; }
//char CHARACTER_MANAGER::setTextCharaId(char textCharaId) { TextCharaId = textCharaId; }
