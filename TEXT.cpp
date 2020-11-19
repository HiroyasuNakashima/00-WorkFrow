#include"TEXT.h"

void TEXT::init(CONTAINER* c) {
	Img = c->textWindowImg;
	WindowPx = c->textWindowPx;
	WindowPy = c->textWindowPy;
	TextPx1 = c->textPx1;
	TextPy1 = c->textPy1;
	TextPx2 = c->textPx2;
	TextPy2 = c->textPy2;
	Rad = c->rad;
	ImgLife = c->textImgLife;
}
void TEXT::update(PLAYER* p, AITEM_WINDOW* a) {
	//���l�ւ̉�b(�e�L�X�g�Q�\���j
	if (p->textFlag() == 1 || p->textFlag() == 2) {
		ImgLife = 1;//�e�L�X�g�E�B���h�E�\��
		a->setWindowLife(0);
		if (TextImg1 == 1) {
			if (isTrigger(KEY_X)) {
				TextImg1 = 0;
				TextImg2 = 1;
			}
		}
		else if (TextImg2 == 1) {
			if (isTrigger(KEY_X)) {
				ImgLife = 0;
				TextImg1 = 1;
				TextImg2 = 0;
				p->setTextFlag(0);
				a->setWindowLife(1);
			}
		}
	}
	//�����X�^�[�Ȃǂւ̉�b�i�e�L�X�g��\���j
	if (p->textFlag() >= 3 && p->textFlag() <= 7) {
		ImgLife = 1;
		a->setWindowLife(0);
		if (isTrigger(KEY_X)) {
			ImgLife = 0;
			if (p->textFlag() == 3) {//�o�g����ʂ�
				p->setActionFlag(3);
				p->setTextFlag(0);
				a->setWindowLife(1);
			}
			if (p->textFlag() == 4) {
				p->setActionFlag(4);
				p->setTextFlag(0);
				a->setWindowLife(1);
			}
			if (p->textFlag() == 5) {
				p->setActionFlag(5);
				p->setTextFlag(0);
				a->setWindowLife(1);
			}
			if (p->textFlag() == 6) {
				p->setTextFlag(0);
				a->setWindowLife(1);
			}
			if (p->textFlag() == 7) {
				p->setTextFlag(0);
				a->setWindowLife(1);
			}
		}
	}
	//�Ւd
	if (p->textFlag() == 8 || p->textFlag() == 9) {
		ImgLife = 1;
		a->setWindowLife(0);
		if (p->textFlag() == 8) {
			if (TextImg1 == 1) {
				if (isTrigger(KEY_X)) {
					TextImg1 = 0;
					TextImg2 = 1;
				}
			}
			else if (TextImg2 == 1) {
				if (isTrigger(KEY_X)) {
					ImgLife = 0;
					TextImg1 = 1;
					TextImg2 = 0;
					p->setTextFlag(0);
					p->setOkFlag(5);
				}
			}
		}
		if (p->textFlag() == 9) {
			if (isTrigger(KEY_X)) {
				ImgLife = 0;
				p->setTextFlag(0);
				a->setWindowLife(1);
			}
		}
	}
}
void TEXT::draw(PLAYER* p) {
	if (ImgLife == 1) {
		image(Img, WindowPx, WindowPy, Rad);
		if (p->textFlag() == 1) {//���l1�ւ̉�b
			if (TextImg1 == 1) {
				text("���̃����X�^�[��|���Ă���", TextPx1, TextPy1);
				text("���̕�����������悤�I", TextPx2, TextPy2);
			}
			if (TextImg2 == 1) {
				text("�V���o���c�V���g�@����ɓ��ꂽ", TextPx1, TextPy1);
			}
		}
		if (p->textFlag() == 6) {//���l1�ւ̉�b NG��b
			if (TextImg1 == 1) {
				text("���̃����X�^�[��|���Ă���", TextPx1, TextPy1);
			}
		}
		if (p->textFlag() == 2) {//���l2�ւ̉�b
			if (TextImg1 == 1) {
				text("�����X�^�[��|���Ă��̂�", TextPx1, TextPy1);
				text("����ɂ��́@�܂��邢���́@�������悤", TextPx2, TextPy2);
			}
			if (TextImg2 == 1) {
				text("�܂��邢���́@����ɓ��ꂽ", TextPx1, TextPy1);
			}
		}
		if (p->textFlag() == 7) {//���l2�ւ̉�b NG��b
			if (TextImg1 == 1) {
				text("����...��������ł��܂�", TextPx1, TextPy1);
			}
		}
		if (p->textFlag() == 3) {//�����X�^�[1�ւ̉�b
			if (TextImg1 == 1) {
				text("���I�I", TextPx1, TextPy1);
			}
		}
		if (p->textFlag() == 4) {//�����X�^�[2�ւ̉�b
			if (TextImg1 == 1) {
				text("�o�E�b�I�I", TextPx1, TextPy1);
			}
		}
		if (p->textFlag() == 5) {//�����X�^�[3�ւ̉�b
			if (TextImg1 == 1) {
				text("�K�V�����I�K�V�����I", TextPx1, TextPy1);
			}
		}
		if (p->textFlag() == 8) {//�Ւd
			if (TextImg1 == 1) {
				text("������u�����ڂ݂�����", TextPx1, TextPy1);
				text("�܂��邢���̂��͂ߍ���ł݂�", TextPx2, TextPy2);
			}
			if (TextImg2 == 1) {
				text("���߂łƂ��������܂�", TextPx1, TextPy1);
				text("���͋~���܂���", TextPx2, TextPy2);
			}
		}
		if (p->textFlag() == 9) {
			if (TextImg1 == 1) {
				text("������u�����ڂ݂�����", TextPx1, TextPy1);
			}
		}
	}
}