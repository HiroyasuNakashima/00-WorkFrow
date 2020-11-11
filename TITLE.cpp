#include"TITLE.h"

void TITLE::init(CONTAINER* c) {
	TitleImg = c->gameoverImg;//画像差し替え注意
	TitlePx = c->titlePx;
	TitlePy = c->titlePy;
	TitleRad = c->titleRad;
	TextPx1 = c->titleTextPx1;
	TextPy1 = c->titleTextPy1;
	TextPx2 = c->titleTextPx2;
	TextPy2 = c->titleTextPy2;
	TextPx3 = c->titleTextPx3;
	TextPy3 = c->titleTextPy3;
	TextPx4 = c->titleTextPx4;
	TextPy4 = c->titleTextPy4;
	TextPx5 = c->titleTextPx5;
	TextPy5 = c->titleTextPy5;
	TextPx6 = c->titleTextPx6;
	TextPy6 = c->titleTextPy6;
	Push_EnterImg = c->pushenterTitleImg;
	Push_EnterPx = c->pushenterTitlePx;
	Push_EnterPy = c->pushenterTitlePy;
	Push_EnterRad = c->pushenterRad;
	Push_EnterCnt = c->pushenterCnt;
}
void TITLE::draw() {
	image(TitleImg, TitlePx, TitlePy, TitleRad);
	text("<ゲームルール説明>", TextPx1, TextPy1);
	text("10日で島が無くなるので救ってください。", TextPx2, TextPy2);
	text("<操作説明>", TextPx3, TextPy3);
	text("上下左右キー　…　移動", TextPx4, TextPy4);
	text("Zキー　…　話しかける、行動の確定", TextPx5, TextPy5);
	text("Xキー　…　テキスト送り", TextPx6, TextPy6);
	if (Push_EnterCnt++ / 60 % 2 == 0) {
		image(Push_EnterImg, Push_EnterPx, Push_EnterPy, Push_EnterRad);
	}
}