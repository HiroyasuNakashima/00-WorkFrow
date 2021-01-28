#pragma warning(disable : 4996)
#include<stdio.h>
#include<sys\stat.h>
#include"common.h"
#include"graphic.h"
#include"CONTAINER.h"
#include"CHARACTER.h"
#include"MAP.h"
CONTAINER* MAP::C = 0;

MAP::MAP() {
	FieldImg = C->mapFieldImg;
	VerticalBridgeImg = C->mapVerticalBridge;
	SidewaysBridgeImg = C->mapSideWaysBridge;
	ChipSize = C->mapChipsize;
	CHARACTER::setMap(this);
}
MAP::~MAP() {
	if (Data) { delete[]Data; Data = 0; }
}
void MAP::init() {
	//ファイル名
	const char* filename = C->mapDataFile1;
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
void MAP::draw() {
	for (int col = 0; col < NumDataColumns; col++) {
		for (int row = 0; row < NumDataRows; row++) {
			int i = col + row * NumDataColumns;
			if (Data[i] == '1') {
				float px = (float)ChipSize * col;
				float py = (float)ChipSize * row;
				image(FieldImg, px, py);
			}
			if (Data[i] == '2') {
				float px = (float)ChipSize * col;
				float py = (float)ChipSize * row;
				image(VerticalBridgeImg, px, py);
			}
			if (Data[i] == '3') {
				float px = (float)ChipSize * col;
				float py = (float)ChipSize * row;
				image(SidewaysBridgeImg, px, py);
			}
		}
	}
}

bool MAP::collisionCheck(float px, float py) {
	int col = (int)px / ChipSize;
	int row = (int)py / ChipSize;
	if ((col < 0) || (col >= NumDataColumns) || (row < 0) || (row >= NumDataRows)) {
		return false;
	}
	if (Data[col + row * NumDataColumns] == '1' ||
		Data[col + row * NumDataColumns] == '2' ||
		Data[col + row * NumDataColumns] == '3') {
		return true;
	}
	return false;
}
