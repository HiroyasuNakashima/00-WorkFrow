#pragma once
#include<string>

class DATA {
	//�f�[�^�l
	float Value = 0;
	//�f�[�^��
	std::string Name;
public:
	//�Z�b�^�[
	void setValue(float value);
	void setName(const char* name);
	//�Q�b�^�[
	float value();
	std::string name();
};