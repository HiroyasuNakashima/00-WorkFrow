#pragma warning(disable : 4996)
#include<stdio.h>
#include<sys\stat.h>
#include"common.h"
#include"CONTAINER.h"
#include"TEXT_WINDOW.h"
#include"CONVERSATION.h"
CONTAINER* CONVERSATION::C = 0;

CONVERSATION::CONVERSATION() {
	tWindow = new TEXT_WINDOW;
	TextPx = C->textPx;
	TextPy = C->textPy;
}
CONVERSATION::~CONVERSATION() {
	if (Data) { delete[]Data; Data = 0; }
	delete tWindow;
}
void CONVERSATION::init(const char charaId, int textFlag) {
	//ファイル名
	char filename[256];
	sprintf_s(filename, "assets/text/%c%d.txt", charaId, textFlag);
	//ファイルを開く
	FILE* fp = fopen(filename, "r");
	WARNING(fp == 0, "テキストデータを読み込めません", filename);
	//ファイルサイズを調べる
	struct stat info;
	{
		fstat(fileno(fp), &info);
		//リトライ時、Dataは０でないので開放
		if (Data) { delete[]Data; Data = 0; }
		//サイズ分Dataを用意する
		Data = new char[info.st_size];
		//1行ずつ読み込みDataに入れる。
		while (fgets(Data, info.st_size, fp) != NULL)
		fclose(fp);
	}
}
void CONVERSATION::draw() {
	tWindow->draw();
	text(Data, TextPx, TextPy);
}