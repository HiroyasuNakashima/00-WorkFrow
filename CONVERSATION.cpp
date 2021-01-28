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
	//�t�@�C����
	char filename[256];
	sprintf_s(filename, "assets/text/%c%d.txt", charaId, textFlag);
	//�t�@�C�����J��
	FILE* fp = fopen(filename, "r");
	WARNING(fp == 0, "�e�L�X�g�f�[�^��ǂݍ��߂܂���", filename);
	//�t�@�C���T�C�Y�𒲂ׂ�
	struct stat info;
	{
		fstat(fileno(fp), &info);
		//���g���C���AData�͂O�łȂ��̂ŊJ��
		if (Data) { delete[]Data; Data = 0; }
		//�T�C�Y��Data��p�ӂ���
		Data = new char[info.st_size];
		//1�s���ǂݍ���Data�ɓ����B
		while (fgets(Data, info.st_size, fp) != NULL)
		fclose(fp);
	}
}
void CONVERSATION::draw() {
	tWindow->draw();
	text(Data, TextPx, TextPy);
}