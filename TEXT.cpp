#include"TEXT.h"

void TEXT::init(CONTAINER* c) {
	Img = c->textImg;
	Px = c->textPx;
	Py = c->textPy;
	Rad = c->textRad;
	ImgLife = c->textImgLife;
}
void TEXT::update(PLAYER* p) {
	//���l�ւ̉�b
	if (p->textFlag() == 1 || p->textFlag() == 2) {
		ImgLife = 1;//�e�L�X�g�E�B���h�E�\��
		if (TextImg2 == 0) {
			TextImg1 = 1;
		}
		if (TextImg1 == 1) {
			if (isTrigger(KEY_X)) {
				TextImg1 = 0;
				TextImg2 = 1;
			}
		}
		else if (TextImg2 == 1) {
			if (isTrigger(KEY_X)) {
				TextImg2 = 0;
				ImgLife = 0;
				p->setTextFlag(0);
			}
		}
	}
	//�����X�^�[�ւ̉�b
	if (p->textFlag() == 3 || p->textFlag() == 4 || p->textFlag() == 5) {
		ImgLife = 1;
		TextImg1 = 1;
		if (isTrigger(KEY_X)) {
			ImgLife = 0;
			TextImg1 = 0;
			if (p->textFlag() == 3) {//�o�g����ʂ�
				p->setActionFlag(3);
				p->setTextFlag(0);
			}
			if (p->textFlag() == 4) {
				p->setActionFlag(4);
				p->setTextFlag(0);
			}
			if (p->textFlag() == 5) {
				p->setActionFlag(5);
				p->setTextFlag(0);
			}
		}
	}
}
void TEXT::draw(PLAYER* p) {
	if (p->textFlag() == 1) {//���l1�ւ̉�b
		if (ImgLife == 1) {
			image(Img, Px, Py, Rad);
		}
		if (TextImg1 == 1) {
			text("abc", 100, 450);
			text("gg", 100, 475);
		}
		if (TextImg2 == 1) {
			text("fgAc", 100, 450);
			text("LL", 100, 475);
		}
	}
	if (p->textFlag() == 2) {//���l2�ւ̉�b
		if (ImgLife == 1) {
			image(Img, Px, Py, Rad);
		}
		if (TextImg1 == 1) {
			text("vv", 100, 450);
			text("oo", 100, 475);
		}
		if (TextImg2 == 1) {
			text("pq", 100, 450);
			text("hj", 100, 475);
		}
	}
	if (p->textFlag() == 3) {//�����X�^�[1�ւ̉�b
		if (ImgLife == 1) {
			image(Img, Px, Py, Rad);
		}
		if (TextImg1 == 1) {
			text("���I�I", 100, 450);
		}
	}
	if (p->textFlag() == 4) {//�����X�^�[2�ւ̉�b
		if (ImgLife == 1) {
			image(Img, Px, Py, Rad);
		}
		if (TextImg1 == 1) {
			text("�o�E�b�I�I", 100, 450);
		}
	}
	if (p->textFlag() == 5) {//�����X�^�[3�ւ̉�b
		if (ImgLife == 1) {
			image(Img, Px, Py, Rad);
		}
		if (TextImg1 == 1) {
			text("�K�V�����I�K�V�����I", 100, 450);
		}
	}
}