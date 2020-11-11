#pragma once
#include<string>

class DATA {
	//データ値
	float Value = 0;
	//データ名
	std::string Name;
public:
	//セッター
	void setValue(float value);
	void setName(const char* name);
	//ゲッター
	float value();
	std::string name();
};