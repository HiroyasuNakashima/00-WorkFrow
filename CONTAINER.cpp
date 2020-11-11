//#include<cassert>
//#include<stdio.h>
//#include"DATA.h"
//#include"CONTAINER.h"
//
//int CONTAINER::loadData(const char* filename) {
//	FILE* fp = 0;
//	fopen_s(&fp, filename, "r");
//	assert(fp != 0);
//	//dataファイルの1行目はdata数でなければならない
//	fscanf_s(fp, "%d", &NumData);
//	//Dataを確保
//	Data = new DATA[NumData];
//	//読み込む
//	char name[256];
//	float value;
//	for (int i = 0; i < NumData; i++) {
//		//すべてfloat値で読み込む
//		fscanf_s(fp, "%s %f",name, 256, &value);
//		Data[i].setName(name);
//		Data[i].setValue(value);
//	}
//	fclose(fp);
//	return 0;
//}
//CONTAINER::~CONTAINER() {
//	if (Data) {
//		delete[] Data;
//		Data = 0;
//	}
//}
//float CONTAINER::fData(const char* name) {
//	int i;
//	for (i = 0; i < NumData; i++) {
//		if (Data[i].name() == name) {
//			return Data[i].value();
//		}
//	}
//	assert(i < NumData);
//	return 0;
//}
//int CONTAINER::iData(const char* name) {
//	int i;
//	for (i = 0; i < NumData; i++) {
//		if (Data[i].name() == name) {
//			return (int)Data[i].value();
//		}
//	}
//	assert(i < NumData);
//	return 0;
//}