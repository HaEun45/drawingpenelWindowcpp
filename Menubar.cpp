#include "stdafx.h" 
#include "Menubar.h"

MenuBar::MenuBar() : Window(0, 0, 620, 100) {}

void MenuBar::onMouseClick(int x, int y) {
	OutputDebugString("MenuBar Clicked.");
}