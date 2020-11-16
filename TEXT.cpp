#include"TEXT.h"

void TEXT::init(CONTAINER* c) {
	WindowImg = c->textWindowImg;
	WindowPx = c->textWindowPx;
	WindowPy = c->textWindowPy;
	TextPx1 = c->textPx1;
	TextPy1 = c->textPy1;
	TextPx2 = c->textPx2;
	TextPy2 = c->textPy2;
	TextPx3 = c->textPx3;
	TextPy3 = c->textPy3;
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
	if (p->textFlag() >= 6 && p->textFlag() <= 10) {//Ng�̎��̉�b
		ImgLife = 1;
		TextImg1 = 1;
		if (isTrigger(KEY_X)) {
			TextImg1 = 0;
			ImgLife = 0;
			p->setTextFlag(0);
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
			image(WindowImg, WindowPx, WindowPy, Rad);
		}
		if (TextImg1 == 1) {
			text("�|���Ă��̃����X�^�[���|���Ȃ�", TextPx1, TextPy1);
			text("����ł��̃����X�^�[��|���Ă���I", TextPx2, TextPy2);
		}
		if (TextImg2 == 1) {
			text("�V���o���c�V���g�@����ɓ��ꂽ", TextPx1, TextPy1);
		}
	}
	if (p->textFlag() == 6) {//NG��b
		if (ImgLife == 1) {
			image(WindowImg, WindowPx, WindowPy, Rad);
		}
		if (TextImg1 == 1) {
			text("�|���Ă��̃����X�^�[���|���Ȃ�", TextPx1, TextPy1);
		}
	}
	if (p->textFlag() == 2) {//���l2�ւ̉�b
		if (ImgLife == 1) {
			image(WindowImg, WindowPx, WindowPy, Rad);
		}
		if (TextImg1 == 1) {
			text("���̉䂪�Ƃɑ�X�`���R��������", TextPx1, TextPy1);
			text("�܂��邢���̂������悤�I", TextPx2, TextPy2);
		}
		if (TextImg2 == 1) {
			text("�܂��邢���́@����ɓ��ꂽ", TextPx1, TextPy1);
		}
	}
	if (p->textFlag() == 7) {//NG��b
		if (ImgLife == 1) {
			image(WindowImg, WindowPx, WindowPy, Rad);
		}
		if (TextImg1 == 1) {
			text("�ŋ߃����X�^�[���������̂�", TextPx1, TextPy1);
		}
	}
	if (p->textFlag() == 3) {//�����X�^�[1�ւ̉�b
		if (ImgLife == 1) {
			image(WindowImg, WindowPx, WindowPy, Rad);
		}
		if (TextImg1 == 1) {
			text("���I�I", TextPx1, TextPy1);
		}
	}
	if (p->textFlag() == 4) {//�����X�^�[2�ւ̉�b
		if (ImgLife == 1) {
			image(WindowImg, WindowPx, WindowPy, Rad);
		}
		if (TextImg1 == 1) {
			text("�����[�I�I", TextPx1, TextPy1);
		}
	}
	if (p->textFlag() == 5) {//�����X�^�[3�ւ̉�b
		if (ImgLife == 1) {
			image(WindowImg, WindowPx, WindowPy, Rad);
		}
		if (TextImg1 == 1) {
			text("�K�V�����I�K�V�����I", TextPx1, TextPy1);
		}
	}
}