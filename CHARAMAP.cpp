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
	//�t�@�C����
	const char* filename = C->charaMapDataFile1;
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