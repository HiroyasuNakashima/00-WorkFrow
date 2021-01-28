#pragma once
class CONTAINER;
class TEXT_WINDOW;

class CONVERSATION {
public:
	CONVERSATION();
	~CONVERSATION();
	void init(const char charaId, int textFlag);
	void draw();
	static void setContainer(CONTAINER* c) { C = c; }
private:
	TEXT_WINDOW* tWindow = 0;
	int TextPx;
	int TextPy;
	char* Data = 0;
	static CONTAINER* C;
};