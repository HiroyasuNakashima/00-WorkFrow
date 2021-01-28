#pragma once
class CONTAINER;

class MAP {
public:
	MAP();
	~MAP();
	void init();
	void draw();
	bool collisionCheck(float px, float py);
	static void setContainer(CONTAINER* c) { C = c; }
private:
	int FieldImg;
	int VerticalBridgeImg;
	int SidewaysBridgeImg;
	int ChipSize = 0;
	char* Data = 0;
	int NumDataColumns = 0;
	int NumDataRows = 0;
	static CONTAINER* C;
};