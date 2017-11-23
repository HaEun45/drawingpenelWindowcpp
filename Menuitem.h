#pragma once
#include "Window.h"
#include <iostream>
#include <string>
using namespace std;

class MenuItem:public Window{
public:
	MenuItem(string s);
	virtual void onMouseClick(int x, int y);
	void display(Frame *f);
	Window *isInside(int x, int y);
	void setXY(int menuitemx, int menuitemy);
private:
};
