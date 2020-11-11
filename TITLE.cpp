#include"TITLE.h"

void TITLE::init(CONTAINER* c) {
	TitleImg = c->gameoverImg;//�摜�����ւ�����
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
	text("<�Q�[�����[������>", TextPx1, TextPy1);
	text("10���œ��������Ȃ�̂ŋ~���Ă��������B", TextPx2, TextPy2);
	text("<�������>", TextPx3, TextPy3);
	text("�㉺���E�L�[�@�c�@�ړ�", TextPx4, TextPy4);
	text("Z�L�[�@�c�@�b��������A�s���̊m��", TextPx5, TextPy5);
	text("X�L�[�@�c�@�e�L�X�g����", TextPx6, TextPy6);
	if (Push_EnterCnt++ / 60 % 2 == 0) {
		image(Push_EnterImg, Push_EnterPx, Push_EnterPy, Push_EnterRad);
	}
}