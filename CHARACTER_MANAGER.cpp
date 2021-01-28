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
}
CHARACTER_MANAGER::~CHARACTER_MANAGER() {
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
	//Z�L�[��������PLAYER�Ƒ��L��������苗�����ɋ�������������킹��
	if (isTrigger(KEY_Z)) {
		playerAction(Charas[0]->animId());

	}
}
void CHARACTER_MANAGER::draw() {
	for (int i = 0; i < Total; i++) {
		if (Charas[i]->alpha() > 0.0f) {
			Charas[i]->draw();
		}
	}
}
void CHARACTER_MANAGER::playerAction(int animId) {//�󂯎����animId�Ƒ��L���������������킹��
	int nextPx = Charas[0]->px();
	int nextPy = Charas[0]->py();
	for (int i = 1; i < Total; i++) {
		//PLAYER�Ƒ��L�����̋����𑪂�
		int dx = Charas[i]->px() - Charas[0]->px();
		int dy = Charas[i]->py() - Charas[0]->py();
		int len = sqrt(dx * dx + dy * dy);
		if (len < PlayerChipSize + 1) {//��苗�����ɋ�����
			//�摜�̌�������PLAYER�̕����𓾂�
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
			//PLAYER�������Ă�������ɑ��L�����������瑼�L��������������
			if (nextPx == Charas[i]->px() || nextPy == Charas[i]->py()) {
				if (Charas[0]->animId() == 0) {
					Charas[i]->setAnimId(1);
					break;
				}
				if (Charas[0]->animId() == 1) {
					Charas[i]->setAnimId(0);
					break;
				}
				if (Charas[0]->animId() == 2) {
					Charas[i]->setAnimId(3);
					break;
				}
				if (Charas[0]->animId() == 3) {
					Charas[i]->setAnimId(2);
					break;
				}
			}
		}
	}
}
