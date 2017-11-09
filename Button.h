#pragma once
#include "Window.h"
using namespace std;

class Button : public Window {
public:
	Button(int x, int y, int sx, int sy);
	Button(string s, int x, int y, int sx, int sy);
	virtual void onMouseClick(int x, int y);
};