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
	//村人への会話(テキスト２つ表示）
	if (p->textFlag() == 1 || p->textFlag() == 2) {
		ImgLife = 1;//テキストウィンドウ表示
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
	//モンスターなどへの会話（テキスト一つ表示）
	if (p->textFlag() >= 3 && p->textFlag() <= 7) {
		ImgLife = 1;
		a->setWindowLife(0);
		if (isTrigger(KEY_X)) {
			ImgLife = 0;
			if (p->textFlag() == 3) {//バトル画面へ
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
	//祭壇
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
		if (p->textFlag() == 1) {//村人1への会話
			if (TextImg1 == 1) {
				text("あのモンスターを倒してくれ", TextPx1, TextPy1);
				text("この武器ををあげよう！", TextPx2, TextPy2);
			}
			if (TextImg2 == 1) {
				text("シュバルツシルト　を手に入れた", TextPx1, TextPy1);
			}
		}
		if (p->textFlag() == 6) {//村人1への会話 NG会話
			if (TextImg1 == 1) {
				text("あのモンスターを倒してくれ", TextPx1, TextPy1);
			}
		}
		if (p->textFlag() == 2) {//村人2への会話
			if (TextImg1 == 1) {
				text("モンスターを倒してくのか", TextPx1, TextPy1);
				text("お礼にこの　まあるいもの　をあげよう", TextPx2, TextPy2);
			}
			if (TextImg2 == 1) {
				text("まあるいもの　を手に入れた", TextPx1, TextPy1);
			}
		}
		if (p->textFlag() == 7) {//村人2への会話 NG会話
			if (TextImg1 == 1) {
				text("ああ...島が沈んでしまう", TextPx1, TextPy1);
			}
		}
		if (p->textFlag() == 3) {//モンスター1への会話
			if (TextImg1 == 1) {
				text("わん！！", TextPx1, TextPy1);
			}
		}
		if (p->textFlag() == 4) {//モンスター2への会話
			if (TextImg1 == 1) {
				text("バウッ！！", TextPx1, TextPy1);
			}
		}
		if (p->textFlag() == 5) {//モンスター3への会話
			if (TextImg1 == 1) {
				text("ガシャン！ガシャン！", TextPx1, TextPy1);
			}
		}
		if (p->textFlag() == 8) {//祭壇
			if (TextImg1 == 1) {
				text("何かを置くくぼみがある", TextPx1, TextPy1);
				text("まあるいものをはめ込んでみた", TextPx2, TextPy2);
			}
			if (TextImg2 == 1) {
				text("おめでとうございます", TextPx1, TextPy1);
				text("島は救われました", TextPx2, TextPy2);
			}
		}
		if (p->textFlag() == 9) {
			if (TextImg1 == 1) {
				text("何かを置くくぼみがある", TextPx1, TextPy1);
			}
		}
	}
}