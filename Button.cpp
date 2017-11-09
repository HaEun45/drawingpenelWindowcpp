#include "stdafx.h" 
#include "Button.h"

Button::Button(int x, int y, int sx, int sy) : Window(x, y, sx, sy) {}
Button::Button(string s, int x, int y, int sx, int sy) : Window(x, y, sx, sy) {
	m_text = s;
}
void Button::onMouseClick(int x, int y) {
	OutputDebugString(m_text.c_str());
	OutputDebugString(" Clicked \n");
	OutputDebugString(" ¹öÆ° \n");
}
