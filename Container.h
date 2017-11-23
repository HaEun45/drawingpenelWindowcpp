#pragma once
#include<iostream>
#include <list>
#include "Window.h"
#include <list>
using namespace std;

class Frame;
class Container :public Window {
public:
	Container();
	Container(int x, int y, int sx, int sy);
	Container(string s, int x, int y, int sx, int sy);
	//void drawContent(Frame *f);
	virtual void onMouseClick(int x, int y);
	void add(Window *w);
	virtual void display(Frame *f); //virtual »õ·Î¾¸
protected:
	list<Window *> * windowList;
};
