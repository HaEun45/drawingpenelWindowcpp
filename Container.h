#pragma once
#include<iostream>
#include <list>
#include "Window.h"
using namespace std;
#define xcoordinate 0 
#define ycoordinate 0 
#define xsize 620 //더할 만큼 을 200으로 정의해 둔다.
#define ysize 80
#define xmenusize 150
#define ycansize 350

class Frame;
class Container :public Window {
public:
	Container();
	Container(int x, int y, int sx, int sy);
	Container(string s, int x, int y, int sx, int sy);
	void drawContent(Frame *f);
	virtual void onMouseClick(int x, int y);
	void add(Window *w);
	virtual void display(Frame *f);
protected:
	string m_text;
	list<Window *> * stuff;
};
