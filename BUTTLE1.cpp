#include"input.h"
#include"BUTTLE1.h"

void BUTTLE1::init(CONTAINER* c) {
	BackImg = c->buttleBackImg;
	MonsterImg = c->buttleMonster1Img;
	AttckImg = c->playerAttckImg;
	BackPx = c->buttleBackPx;
	BackPy = c->buttleBackPy;
	PlayerLife = c->playerLife;
	PlayerAttckDamege = c->playerAttckDamege;
	PlayerAttckDamege2 = c->playerAttckDamege2;
	MonsterPx = c->buttleMonsterPx;
	MonsterPy = c->buttleMonsterPy;
	MonsterLife = c->monster1Life;
	MonsterAttckDamege = c->monster1AttckDamege;
	AttckPx = c->buttlePlayerAttckPx;
	AttckPy = c->buttlePlayerAttckPy;
	Rad = c->buttleRad;
	Radian = c->buttleRadian;
	ToRad = c->buttleRadian;
	DamegeCnt = c->buttleDamegeCnt;
	AttckImgLife = c->buttleAttckImgLife;
	PlayerAttckFlag = c->buttlePlayerAttckFlag;
	MonsterAttckFlag = c->buttleMonsterAttckFlag;
	TextWindowImg = c->buttleTextWindowImg;
	TextWindowPx = c->buttleTextWindowPx;
	TextWindowPy = c->buttleTextWindowPy;
	TextMenyuImg = c->buttleTextMenyuImg;
	TextMenyuPx = c->buttleTextMenyuPx;
	TextMenyuPy = c->buttleTextMenyuPy;
	CursorImg = c->buttleCursorImg;
	CursorPx = c->buttleCursorPx;
	CursorPy = c->buttleCursorPy;
	TextPx1 = c->buttleTextPx1;
	TextPy1 = c->buttleTextPy1;
	TextPx2 = c->buttleTextPx2;
	TextPy2 = c->buttleTextPy2;
	tatakauPx = c->buttletatakauPx;
	tatakauPy = c->buttletatakauPy;
	kaihukuPx = c->buttlekaihukuPx;
	kaihukuPy = c->buttlekaihukuPy;
	nigeruPx = c->buttlenigeruPx;
	nigeruPy = c->buttlenigeruPy;
	PlayerEscape = c->buttlePlayerEscape;
	Trun = PLAYER_TRUN;
}
void BUTTLE1::update() {
	if (PlayerLife >= 0 && MonsterLife >= 0 && TextFlag != 5) {
		switch (Trun) {
			//PLAYER�^�[��
		case PLAYER_TRUN:
			if (PlayerAttckFlag == 0) {//�U�����łȂ�
				TextFlag = 0;
				CursorLife = 1;
				if (isTrigger(KEY_Z)) {
					if (ActionFlag == 1) {//��������
						TextFlag = 1;
						PlayerAttckFlag = 1;
						AttckImgLife = 1;
						CursorLife = 0;
					}
					if (ActionFlag == 2) {//�����ӂ�
						TextFlag = 3;
						PlayerAttckFlag = 2;
						CursorLife = 0;
					}
					if (ActionFlag == 3) {//�ɂ���
						TextFlag = 5;
						CursorLife = 0;
					}
				}
			}
			if (PlayerAttckFlag == 1) {//�U����
				if (AttckImgLife <= 0) {
					MonsterLife -= PlayerAttckDamege;
					PlayerAttckFlag = 2;
				}
			}
			if (PlayerAttckFlag == 2) {//�s����
				Sleep(180);
				Trun = MONSTER_TRUN;
			}
			break;
		case MONSTER_TRUN:
			//�����X�^�[�U��]
			PlayerAttckFlag = 0;
			if (MonsterAttckFlag == 0) {
				Sleep(180);
				MonsterAttckFlag = 1;
				TextFlag = 2;
			}
			if (MonsterAttckFlag == 1) {
				BackPx += sin(Radian) * 2.0f; //�w�i�ƃ����X�^�[�摜��h�炷
				MonsterPx += sin(Radian) * 2.0f;
				Radian += 1.0f;
				if (Radian >= 10.0f) {//Radian�l���������炻�ꂼ��̒l�����Z�b�g����
					Radian = ToRad;
					BackPx = 0.0f;
					MonsterPx = 280.0f;
					MonsterAttckFlag = 0;
					PlayerLife -= MonsterAttckDamege;
					Trun = PLAYER_TRUN;
				}
			}
			break;
		}
	}
	//���s�����܂�����܂��́A�����o������
	else if (MonsterLife <= 0) {
		TextFlag = 4;
		MonsterImgLife = 0;
		if (isTrigger(KEY_Z)) {
			PlayerWin = 1;
		}
	}
	else if (PlayerLife <= 0) {
		PlayerLose = 1;
	}
	else if (TextFlag == 5) {
		if (isTrigger(KEY_Z)) {
			TextFlag = 0;
			PlayerEscape = 1;
		}
	}
	//�J�[�\���̈ړ�
	CursorWy = CursorPy;
	if (isTrigger(KEY_UP)) {
		CursorWy -= 50.0f;
		if (CursorWy >= 403.0f) {
			CursorPy -= 50.0f;
		}
	}
	if (isTrigger(KEY_DOWN)) {
		CursorWy += 50.0f;
		if (CursorWy <= 503.0f) {
			CursorPy += 50.0f;
		}
	}
	//�J�[�\���̈ʒu���
	if (CursorPy == 403.0f) {
		ActionFlag = 1;
	}
	if (CursorPy == 453.0f) {
		ActionFlag = 2;
	}
	if (CursorPy == 503.0f) {
		ActionFlag = 3;
	}
}
void BUTTLE1::draw() {
	image(BackImg, BackPx, BackPy, Rad);
	//�e�L�X�g�\��
	image(TextWindowImg, TextWindowPx, TextWindowPy, Rad);
	image(TextMenyuImg, TextMenyuPx, TextMenyuPy, Rad);

	text("��������", tatakauPx, tatakauPy);
	text("�����ӂ�", kaihukuPx, kaihukuPy);
	text("�ɂ���", nigeruPx, nigeruPy);

	if (TextFlag == 1) {
		text("�v���C���[�̍U���@22�̃_���[�W", TextPx1, TextPy1);
	}
	if (TextFlag == 2) {
		text("�����X�^�[�̍U���@38�̃_���[�W", TextPx1, TextPy1);
	}
	if (TextFlag == 3) {
		text("�����ӂ��A�C�e�����g����", TextPx1, TextPy1);
	}
	if (TextFlag == 4) {
		text("�����X�^�[�͓|���ꂽ", TextPx1, TextPy1);
	}
	if (TextFlag == 5) {
		text("�v���C���[�͓����o����", TextPx1, TextPy1);
	}
	//�摜�`��
	if (MonsterImgLife == 1) {
		if (DamegeCnt > 0) {//�_�Ńg���K�[
			if (--DamegeCnt / 10 % 2 == 1) {//�_�ŕ\��
				image(MonsterImg, MonsterPx, MonsterPy, Rad);
			}
		}
		else {
			image(MonsterImg, MonsterPx, MonsterPy, Rad);
		}
	}
	if (--AttckImgLife >= 0) {
		image(AttckImg, AttckPx, AttckPy, Rad);
	}
	//�J�[�\��
	if (CursorLife == 1) {//�퓬���͏�����
		if (++ImgCnt / 30 % 2 == 0) {//�_�ŕ\��
			image(CursorImg, CursorPx, CursorPy, Rad);
		}
	}
}
int BUTTLE1::playerWin() { return PlayerWin; }
int BUTTLE1::playerLose() { return PlayerLose; }
int BUTTLE1::playerEscape() { return PlayerEscape; }