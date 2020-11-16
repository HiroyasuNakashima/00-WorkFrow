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
	if (p->textFlag() >= 6 && p->textFlag() <= 10) {//Ngの時の会話
		ImgLife = 1;
		TextImg1 = 1;
		if (isTrigger(KEY_X)) {
			TextImg1 = 0;
			ImgLife = 0;
			p->setTextFlag(0);
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
			image(WindowImg, WindowPx, WindowPy, Rad);
		}
		if (TextImg1 == 1) {
			text("怖くてあのモンスターが倒せない", TextPx1, TextPy1);
			text("これであのモンスターを倒してくれ！", TextPx2, TextPy2);
		}
		if (TextImg2 == 1) {
			text("シュバルツシルト　を手に入れた", TextPx1, TextPy1);
		}
	}
	if (p->textFlag() == 6) {//NG会話
		if (ImgLife == 1) {
			image(WindowImg, WindowPx, WindowPy, Rad);
		}
		if (TextImg1 == 1) {
			text("怖くてあのモンスターが倒せない", TextPx1, TextPy1);
		}
	}
	if (p->textFlag() == 2) {//村人2への会話
		if (ImgLife == 1) {
			image(WindowImg, WindowPx, WindowPy, Rad);
		}
		if (TextImg1 == 1) {
			text("この我が家に代々伝わる由緒正しい", TextPx1, TextPy1);
			text("まあるいものを授けよう！", TextPx2, TextPy2);
		}
		if (TextImg2 == 1) {
			text("まあるいもの　を手に入れた", TextPx1, TextPy1);
		}
	}
	if (p->textFlag() == 7) {//NG会話
		if (ImgLife == 1) {
			image(WindowImg, WindowPx, WindowPy, Rad);
		}
		if (TextImg1 == 1) {
			text("最近モンスターが増えたのぅ", TextPx1, TextPy1);
		}
	}
	if (p->textFlag() == 3) {//モンスター1への会話
		if (ImgLife == 1) {
			image(WindowImg, WindowPx, WindowPy, Rad);
		}
		if (TextImg1 == 1) {
			text("わん！！", TextPx1, TextPy1);
		}
	}
	if (p->textFlag() == 4) {//モンスター2への会話
		if (ImgLife == 1) {
			image(WindowImg, WindowPx, WindowPy, Rad);
		}
		if (TextImg1 == 1) {
			text("がおー！！", TextPx1, TextPy1);
		}
	}
	if (p->textFlag() == 5) {//モンスター3への会話
		if (ImgLife == 1) {
			image(WindowImg, WindowPx, WindowPy, Rad);
		}
		if (TextImg1 == 1) {
			text("ガシャン！ガシャン！", TextPx1, TextPy1);
		}
	}
}