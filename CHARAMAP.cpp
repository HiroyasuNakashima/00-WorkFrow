#pragma warning(disable : 4996)
#include<stdio.h>
#include<sys\stat.h>
#include"common.h"
#include"graphic.h"
#include"CONTAINER.h"
#include"CHARACTER.h"
#include"CHARACTER_MANAGER.h"
#include"CHARAMAP.h"
CONTAINER* CHARAMAP::C = 0;
CHARACTER_MANAGER* CHARAMAP::CharacterManager = 0;

CHARAMAP::CHARAMAP() {
	ChipSize = C->charaMapChipsize;
	CHARACTER::setCharaMap(this);
}
CHARAMAP::~CHARAMAP() {
	if (Data) { delete[]Data; Data = 0; }
}
void CHARAMAP::init() {
	//ファイル名
	const char* filename = C->charaMapDataFile1;
	//ファイルを開く

	FILE* fp = fopen(filename, "r");
	WARNING(fp == 0, "マップデータを読み込めません", filename);
	//ファイルサイズを調べる
	struct stat info;
	{
		fstat(fileno(fp), &info);
		//リトライ時、Dataは０でないので開放
		if (Data) { delete[]Data; Data = 0; }
		//サイズ分Dataを用意する
		Data = new char[info.st_size];
		//1文字ずつ読み込みData[i]に入れる。同時に列と行数も求める
		NumDataColumns = 0;
		NumDataRows = 0;
		char c;
		int i = 0;
		while (fscanf(fp, "%c", &c) != EOF) {
			if (c != '\n') {
				Data[i] = c;
				i++;
			}
			else {
				if (NumDataRows == 0) {
					NumDataColumns = i;
				}
				NumDataRows++;
			}
		}
		fclose(fp);
	}
}
void CHARAMAP::draw() {
	for (int col = 0; col < NumDataColumns; col++) {
		for (int row = 0; row < NumDataRows; row++) {
			int i = col + row * NumDataColumns;
			if (Data[i] == 'a') {
				float px = (float)ChipSize * col;
				float py = (float)ChipSize * row;
				CharacterManager->appear(Data[i], px, py, 0, 0);
				Data[i] = '.';
			}
			if ('b' <= Data[i] && Data[i] <= 'z') {
				float px = (float)ChipSize * col;
				float py = (float)ChipSize * row;
				CharacterManager->appear(Data[i], px, py, 0, 0);
			}
		}
	}
}

bool CHARAMAP::collisionCheck(float px, float py) {
	int col = (int)px / ChipSize;
	int row = (int)py / ChipSize;
	if ((col < 0) || (col >= NumDataColumns) || (row < 0) || (row >= NumDataRows)) {
		return false;
	}
	if (Data[col + row * NumDataColumns] >= 'b' &&
		Data[col + row * NumDataColumns] <= 'z' ){
		return true;
	}
	return false;
}

int CHARAMAP::chipSize() { return ChipSize; }