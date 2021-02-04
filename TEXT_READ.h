#pragma once
class CONTAINER;
class TEXT_WINDOW;

class TEXT_READ {
public:
	TEXT_READ();
	~TEXT_READ();
	void init();
	void draw();
	static void setContainer(CONTAINER* c) { C = c; }
private:
	TEXT_WINDOW* tWindow = 0;
	int NumDataColumns = 0;
	int NumDataRows = 0;
	int TextPx;
	int TextPy;
	char* Data = 0;
	static CONTAINER* C;
};