#include"TEXT.h"

void TEXT::init(CONTAINER* c) {
	Img = c->textImg;
	Px = c->textPx;
	Py = c->textPy;
	Rad = c->textRad;
	ImgLife = c->textImgLife;
}
void TEXT::update(PLAYER* p) {
	//村人への会話
	if (p->textFlag() == 1 || p->textFlag() == 2) {
		ImgLife = 1;//テキストウィンドウ表示
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
	//モンスターへの会話
	if (p->textFlag() == 3 || p->textFlag() == 4 || p->textFlag() == 5) {
		ImgLife = 1;
		TextImg1 = 1;
		if (isTrigger(KEY_X)) {
			ImgLife = 0;
			TextImg1 = 0;
			if (p->textFlag() == 3) {//バトル画面へ
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
	if (p->textFlag() == 1) {//村人1への会話
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
	if (p->textFlag() == 2) {//村人2への会話
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
	if (p->textFlag() == 3) {//モンスター1への会話
		if (ImgLife == 1) {
			image(Img, Px, Py, Rad);
		}
		if (TextImg1 == 1) {
			text("わん！！", 100, 450);
		}
	}
	if (p->textFlag() == 4) {//モンスター2への会話
		if (ImgLife == 1) {
			image(Img, Px, Py, Rad);
		}
		if (TextImg1 == 1) {
			text("バウッ！！", 100, 450);
		}
	}
	if (p->textFlag() == 5) {//モンスター3への会話
		if (ImgLife == 1) {
			image(Img, Px, Py, Rad);
		}
		if (TextImg1 == 1) {
			text("ガシャン！ガシャン！", 100, 450);
		}
	}
}