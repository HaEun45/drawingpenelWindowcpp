#pragma once
#include <string>
using namespace std;
class Frame;
class Window {
public:
	Window(int x, int y, int sx, int sy); 
	Window(string s, int x, int y, int sx, int sy);
	virtual void setFrame(Frame *);
	virtual void display();
	void drawContent();
	virtual void onMouseClick(int x, int y);
	virtual Window* isInside(int x, int y);
	virtual void setNext(Window *w);
protected:
	int m_x, m_y, m_xsize, m_ysize;
	string m_text;
	Frame *m_Frame;
	Window * m_next; //윈도우 다음 포인터 변수 선언
private:
};
