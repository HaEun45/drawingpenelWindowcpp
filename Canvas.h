#pragma once
#include "Window.h" 

class Canvas :public Window {
public:
	Canvas(Frame *f);
	virtual void onMouseClick(int x, int y);
};