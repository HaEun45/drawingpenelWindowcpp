#pragma once
#include "Window.h"

class MenuBar : public Window {
public:
	MenuBar();
	virtual void onMouseClick(int x, int y);

};