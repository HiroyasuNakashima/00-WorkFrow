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
	//�t�@�C����
	const char* filename = C->mapDataFile1;
	//�t�@�C�����J��
	FILE* fp = fopen(filename, "r");
	WARNING(fp == 0, "�}�b�v�f�[�^��ǂݍ��߂܂���", filename);
	//�t�@�C���T�C�Y�𒲂ׂ�
	struct stat info;
	{
		fstat(fileno(fp), &info);
		//���g���C���AData�͂O�łȂ��̂ŊJ��
		if (Data) { delete[]Data; Data = 0; }
		//�T�C�Y��Data��p�ӂ���
		Data = new char[info.st_size];
		//1�������ǂݍ���Data[i]�ɓ����B�����ɗ�ƍs�������߂�
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
