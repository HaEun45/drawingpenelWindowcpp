#include "stdafx.h" 
#include "Label.h"

Label::Label(int x, int y, int sx, int sy) :Window(x, y, sx, sy) {}
Label::Label(string s, int x, int y, int sx, int sy) : Window(s, x, y, sx, sy) {
	m_text = s;
}
void Label::onMouseClick(int x, int y) {
	OutputDebugString(m_text.c_str());
	OutputDebugString(" Clicked \n");
	OutputDebugString("Label \n");
}