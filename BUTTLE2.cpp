#include"input.h"
#include"BUTTLE2.h"

void BUTTLE2::init(CONTAINER* c, PLAYER* p, AITEM_WINDOW* a) {
	BackImg = c->buttleBackImg;
	MonsterImg = c->buttleMonster2Img;
	AttckImg = c->playerAttckImg;
	PlayerAiconImg = c->playerAiconImg;
	BackPx = c->buttleBackPx;
	BackPy = c->buttleBackPy;
	PlayerAiconPx = c->buttlePlayerAiconPx;
	PlayerAiconPy = c->buttlePlayerAiconPy;
	PlayerLife = p->life();
	PlayerHeal = c->playerHeal;
	MonsterPx = c->buttleMonsterPx;
	MonsterPy = c->buttleMonsterPy;
	MonsterLife = c->monster2Life;
	MonsterAttckDamege = c->monster1AttckDamege;
	AttckPx = c->buttlePlayerAttckPx;
	AttckPy = c->buttlePlayerAttckPy;
	Rad = c->buttleRad;
	Radian = c->buttleRadian;
	ToRad = c->buttleRadian;
	DamegeCnt = c->buttleDamegeCnt;
	AttckImgLife = c->buttleAttckImgLife;
	TextFlag = c->buttleTextFlag;
	ActionFlag = c->buttlePlaerActionFlag;
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
	PlayerWin = c->buttlePlayerWin;
	PlayerLose = c->buttlePlayerLose;
	PlayerEscape = c->buttlePlayerEscape;
	//���킠��A�Ȃ�
	if (a->weaponImgLife() == 0) {//�Ȃ�
		PlayerAttckDamege = c->playerAttckDamege;
	}
	else if (a->weaponImgLife() == 1) {//����
		PlayerAttckDamege = c->playerAttckDamege2;
	}
	//HP�o�[
	for (int i = 0; i < HP; i++) {
		HpbarImg[i] = c->HpbarImg;
		HpbarPx[i] = c->HpbarPx;
		HpbarPy[i] = c->HpbarPy;
	}
	HpbarTextPx1 = c->HpbarTextPx1;
	HpbarTextPy1 = c->HpbarTextPy1;
	HpbarTextPx2 = c->HpbarTextPx2;
	HpbarTextPy2 = c->HpbarTextPy2;

	Trun = PLAYER_TRUN;
}
void BUTTLE2::update(AITEM_WINDOW* a) {
	if (PlayerLife > 0 && MonsterLife > 0 && TextFlag != 6) {
		switch (Trun) {
			//PLAYER�^�[��
		case PLAYER_TRUN:
			if (ActionFlag == 0) {//�U�����łȂ�
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
				//�J�[�\���̈ʒu�ŃR�}���h���m��
				if (isTrigger(KEY_Z)) {
					if (CursorPy == 403.0f) {//��������
						if (a->weaponImgLife() == 0) {
							TextFlag = 1;
						}
						else {
							TextFlag = 7;
						}
						ActionFlag = 1;
						AttckImgLife = 1;
					}
					else if (CursorPy == 453.0f) {//�����ӂ�
						ActionFlag = 2;
					}
					else if (CursorPy == 503.0f) {//�ɂ���
						ActionFlag = 3;
					}
				}
			}
			else if (ActionFlag == 1) {//��������
				Sleep(180);
				MonsterLife -= PlayerAttckDamege;
				Trun = MONSTER_TRUN;
			}
			else if (ActionFlag == 2) {//�����ӂ�
				if (a->kaihukuImgLife() == 1) {
					TextFlag = 3;
					PlayerLife += PlayerHeal;
					a->setHealImgLife(0);
					if (PlayerLife > 200) {//�����ӂ������l������𒴂�����
						PlayerLife = 200;//HP������ɐݒ�
					}
					Trun = MONSTER_TRUN;
				}
				else {//�����ӂ��A�C�e���������Ă��Ȃ���
					TextFlag = 4;
					ActionFlag = 0;
					Trun = PLAYER_TRUN;
				}
			}
			else if (ActionFlag == 3) {//�ɂ���
				TextFlag = 6;
			}
			break;
		case MONSTER_TRUN:
			//�����X�^�[�U��
			ActionFlag = 0;
			if (MonsterAttckFlag == 0) {
				TextFlag = 2;
				Sleep(120);
				MonsterAttckFlag = 1;
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
					if (PlayerLife < 0) {//HP���O��菭�Ȃ��Ȃ�����
						PlayerLife = 0;//HP���O�ɂ���
					}
					Sleep(60);
					TextFlag = 0;
					Trun = PLAYER_TRUN;
				}
			}
			break;
		}
	}
	//���s�����܂�����܂��́A�����o������
	else if (MonsterLife <= 0) {
		TextFlag = 5;
		MonsterImgLife = 0;
		if (isTrigger(KEY_X)) {
			ActionFlag = 0;
			PlayerWin = 1;
		}
	}
	else if (PlayerLife <= 0) {
		ActionFlag = 0;
		PlayerLose = 1;
	}
	else if (TextFlag == 6) {
		if (isTrigger(KEY_X)) {
			TextFlag = 0;
			ActionFlag = 0;
			PlayerEscape = 1;
		}
	}
}
void BUTTLE2::draw() {
	image(BackImg, BackPx, BackPy, Rad);
	//�e�L�X�g�\��
	image(TextWindowImg, TextWindowPx, TextWindowPy, Rad);
	image(TextMenyuImg, TextMenyuPx, TextMenyuPy, Rad);
	image(CursorImg, CursorPx, CursorPy, Rad);
	image(PlayerAiconImg, PlayerAiconPx, PlayerAiconPy, Rad);

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
		text("�����ӂ��A�C�e���������Ă��Ȃ�", TextPx1, TextPy1);
	}
	if (TextFlag == 5) {
		text("�����X�^�[�͓|���ꂽ", TextPx1, TextPy1);
		text("�����ӂ��A�C�e������ɓ��ꂽ", TextPx2, TextPy2);
	}
	if (TextFlag == 6) {
		text("�v���C���[�͓����o����", TextPx1, TextPy1);
	}
	if (TextFlag == 7) {//���킠��
		text("�v���C���[�̍U���@48�̃_���[�W", TextPx1, TextPy1);
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
	//HP�o�[
	for (int i = 0; i < PlayerLife / 10; i++) {
		image(HpbarImg[i], HpbarPx[i] + 5.0f * i, HpbarPy[i], Rad);
	}
	text(PlayerLife, HpbarTextPx1, HpbarTextPy1);
	text(" / 200", HpbarTextPx2, HpbarTextPy2);
}
int BUTTLE2::playerWin() { return PlayerWin; }
int BUTTLE2::playerLose() { return PlayerLose; }
int BUTTLE2::playerEscape() { return PlayerEscape; }