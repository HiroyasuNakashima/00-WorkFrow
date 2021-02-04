#pragma warning(disable : 4996)
#include<stdio.h>
#include<sys\stat.h>
#include"common.h"
#include"CONTAINER.h"
#include"TEXT_WINDOW.h"
#include"TEXT_READ.h"
CONTAINER* TEXT_READ::C = 0;

TEXT_READ::TEXT_READ() {
	tWindow = new TEXT_WINDOW;
	TextPx = C->textPx;
	TextPy = C->textPy;
}
TEXT_READ::~TEXT_READ() {
	if (Data) { delete[]Data; Data = 0; }
	delete tWindow;
}
void TEXT_READ::init() {
	//ファイル名
	char filename[256];
	sprintf_s(filename, "assets/text/b1.txt");
	//ファイルを開く
	FILE* fp = fopen(filename, "rb");
	WARNING(fp == 0, "テキストデータを読み込めません", filename);
	//ファイルサイズを調べる
	struct stat info;
	{
		fstat(fileno(fp), &info);
		//リトライ時、Dataは０でないので開放
		if (Data) { delete[]Data; Data = 0; }
		//サイズ分Dataを用意する
		Data = new char[info.st_size];
		
		//読み込んだデータをDataに入れる
		fread(Data, 1, info.st_size, fp);
		Data[info.st_size - 1] = '\0';
		fclose(fp);
	}
}
void TEXT_READ::draw() {
	tWindow->draw();//テキストウィンドウ枠
	text(Data, TextPx, TextPy);
}

	
	//0xd = が改行
