#include"input.h"
#include"BUTTLE2.h"

void BUTTLE2::init(CONTAINER* c, AITEM_WINDOW* a) {
	BackImg = c->buttleBackImg;
	MonsterImg = c->buttleMonster2Img;
	AttckImg = c->playerAttckImg;
	PlayerAiconImg = c->playerAiconImg;
	PlayerAiconPx = c->buttlePlayerAiconPx;
	PlayerAiconPy = c->buttlePlayerAiconPy;
	BackPx = c->buttleBackPx;
	BackPy = c->buttleBackPy;
	PlayerLife = c->playerLife;
	MonsterPx = c->buttleMonsterPx;
	MonsterPy = c->buttleMonsterPy;
	MonsterImgLife = c->buttleMonsterImgLife;
	MonsterLife = c->monster2Life;
	MonsterAttckDamege = c->monster2AttckDamege;
	AttckPx = c->buttlePlayerAttckPx;
	AttckPy = c->buttlePlayerAttckPy;
	Rad = c->buttleRad;
	Radian = c->buttleRadian;
	ToRad = c->buttleRadian;
	DamegeCnt = c->buttleDamegeCnt;
	AttckImgLife = c->buttleAttckImgLife;
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
	TextFlag = c->buttleTextFlag;
	TextPx1 = c->buttleTextPx1;
	TextPy1 = c->buttleTextPy1;
	TextPx2 = c->buttleTextPx2;
	TextPy2 = c->buttleTextPy2;
	HpTextPx1 = c->buttleHpTextPx1;
	HpTextPy1 = c->buttleHpTextPy1;
	HpTextPx2 = c->buttleHpTextPx2;
	HpTextPy2 = c->buttleHpTextPy2;
	tatakauPx = c->buttletatakauPx;
	tatakauPy = c->buttletatakauPy;
	kaihukuPx = c->buttlekaihukuPx;
	kaihukuPy = c->buttlekaihukuPy;
	nigeruPx = c->buttlenigeruPx;
	nigeruPy = c->buttlenigeruPy;
	ActionFlag = c->buttlePlayerActionFlag;
	PlayerWin = c->buttlePlayerWin;
	PlayerLose = c->buttlePlayerLose;
	PlayerEscape = c->buttlePlayerEscape;
	//HP_BAR
	for (int i = 0; i < 20; i++) {
		HpImg[i] = c->hpbarImg;
		HpPx[i] = c->hpbarPx + 4 * i;
		HpPy[i] = c->hpbarPy;
	}
	//����
	if (a->weaponImgLife() == 0) {
		PlayerAttckDamege = c->playerAttckDamege;//����Ȃ�
	}
	else {
		PlayerAttckDamege = c->playerAttckDamege2;//���킠��
	}
	Trun = PLAYER_TRUN;
}
void BUTTLE2::update(AITEM_WINDOW* a) {
	if (PlayerLife >= 0 && MonsterLife >= 0 && TextFlag != 7) {
		switch (Trun) {
			//PLAYER�^�[��
		case PLAYER_TRUN:
			//�J�[�\���̈ړ�------------------------------------------------------
			if (ActionFlag == 0) {//�U�����łȂ�
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
				if (isTrigger(KEY_Z)) {//�J�[�\���̈ʒu�ŃA�N�V����PLAYER�̍s�����m��
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
			}
			//PLAYER�s��---------------------------------------------------------
			if (ActionFlag == 1) {//��������
				if (a->weaponImgLife() == 0) {
					TextFlag = 1;
				}
				else {
					TextFlag = 2;
				}
				AttckImgLife = 10;
				MonsterLife -= PlayerAttckDamege;
				Trun = MONSTER_TRUN;
			}
			if (ActionFlag == 2) {//�����ӂ�
				if (a->kaihukuImgLife() == 1) {
					TextFlag = 4;
					PlayerLife += 100;
					if (PlayerLife > 200) {
						PlayerLife = 200;
					}
					a->setKaihukuImgLife(0);
					Trun = MONSTER_TRUN;
				}
				else {
					TextFlag = 5;
					ActionFlag = 0;
				}
			}
			if (ActionFlag == 3) {//�ɂ���
				TextFlag = 7;
			}
			break;
		case MONSTER_TRUN:
			//�����X�^�[�U��
			if (AttckImgLife < 0) {
				ActionFlag = 0;
				if (MonsterAttckFlag == 0) {
					Sleep(300);
					MonsterAttckFlag = 1;
					TextFlag = 3;
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
			}
			break;
		}
	}
	//���s�����܂�����܂��́A�����o������
	else if (MonsterLife <= 0) {
		TextFlag = 6;
		MonsterImgLife = 0;
		if (isTrigger(KEY_Z)) {
			PlayerWin = 1;
		}
	}
	else if (PlayerLife <= 0) {
		PlayerLose = 1;
	}
	else if (TextFlag == 7) {
		if (isTrigger(KEY_Z)) {
			TextFlag = 0;
			PlayerEscape = 1;
		}
	}
}
void BUTTLE2::draw() {
	//�w�i
	image(BackImg, BackPx, BackPy, Rad);
	//�e�L�X�g�\��
	image(TextWindowImg, TextWindowPx, TextWindowPy, Rad);
	image(TextMenyuImg, TextMenyuPx, TextMenyuPy, Rad);
	//�J�[�\��
	image(CursorImg, CursorPx, CursorPy, Rad);

	text("��������", tatakauPx, tatakauPy);
	text("�����ӂ�", kaihukuPx, kaihukuPy);
	text("�ɂ���", nigeruPx, nigeruPy);

	if (TextFlag == 1) {
		text("�v���C���[�̍U���@22�̃_���[�W", TextPx1, TextPy1);
	}
	if (TextFlag == 2) {
		text("�v���C���[�̍U���@45�̃_���[�W", TextPx1, TextPy1);
	}
	if (TextFlag == 3) {
		text("�����X�^�[�̍U���@56�̃_���[�W", TextPx1, TextPy1);
	}
	if (TextFlag == 4) {
		text("�����ӂ��A�C�e�����g����", TextPx1, TextPy1);
	}
	if (TextFlag == 5) {
		text("�����ӂ��A�C�e���������Ă��Ȃ�", TextPx1, TextPy1);
	}
	if (TextFlag == 6) {
		text("�����X�^�[�͓|���ꂽ", TextPx1, TextPy1);
	}
	if (TextFlag == 7) {
		text("�v���C���[�͓����o����", TextPx1, TextPy1);
	}
	//�摜�`��
	//HP_BAR
	for (int i = 0; i < PlayerLife / 10; i++) {
		image(HpImg[i], HpPx[i], HpPy[i], Rad);
	}
	text(PlayerLife, HpTextPx1, HpTextPy1);
	text("/200", HpTextPx2, HpTextPy2);
	//PLAYER_AICON
	image(PlayerAiconImg, PlayerAiconPx, PlayerAiconPy, Rad);
	//�����X�^�[
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
	//�U���G�t�F�N�g
	if (AttckImgLife-- > 0) {
		image(AttckImg, AttckPx, AttckPy, Rad);
	}
}
int BUTTLE2::playerWin() { return PlayerWin; }
int BUTTLE2::playerLose() { return PlayerLose; }
int BUTTLE2::playerEscape() { return PlayerEscape; }