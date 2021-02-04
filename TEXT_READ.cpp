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
	//�t�@�C����
	char filename[256];
	sprintf_s(filename, "assets/text/b1.txt");
	//�t�@�C�����J��
	FILE* fp = fopen(filename, "rb");
	WARNING(fp == 0, "�e�L�X�g�f�[�^��ǂݍ��߂܂���", filename);
	//�t�@�C���T�C�Y�𒲂ׂ�
	struct stat info;
	{
		fstat(fileno(fp), &info);
		//���g���C���AData�͂O�łȂ��̂ŊJ��
		if (Data) { delete[]Data; Data = 0; }
		//�T�C�Y��Data��p�ӂ���
		Data = new char[info.st_size];
		
		//�ǂݍ��񂾃f�[�^��Data�ɓ����
		fread(Data, 1, info.st_size, fp);
		Data[info.st_size - 1] = '\0';
		fclose(fp);
	}
}
void TEXT_READ::draw() {
	tWindow->draw();//�e�L�X�g�E�B���h�E�g
	text(Data, TextPx, TextPy);
}

	
	//0xd = �����s
