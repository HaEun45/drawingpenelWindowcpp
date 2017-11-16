#include "stdafx.h" 
#include "Canvas.h"
#include "Frame.h"

Canvas::Canvas(Frame *f):Window(1,81,620,500) {
	m_Frame = f;
	f->registerWindow(this);
}

void Canvas::onMouseClick(int x, int y) {
	OutputDebugString("Canvas: ");
	OutputDebugString(to_string(x).c_str());
	OutputDebugString(", ");
	OutputDebugString(to_string(y).c_str());
}

