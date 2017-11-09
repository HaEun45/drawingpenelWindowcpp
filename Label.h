#pragma once
#include "Window.h"
using namespace std;

class Label :public Window {
public:
	Label(int x, int y, int sx, int sy);
	Label(string s, int x, int y, int sx, int sy);
	virtual void onMouseClick(int x, int y);

};