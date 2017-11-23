//#include<fstream>
#include "stdafx.h" 
#include "Canvas.h"

//생성자
Canvas::Canvas(Frame *f):Window(xcoordinate,ycoordinate+ysize,xsize,ycansize) {
}
//마우스를 클릭한 경우 발생하는 일들에 대한 함수
void Canvas::onMouseClick(int x, int y) {
	OutputDebugString("Canvas: ");
	OutputDebugString(to_string(x).c_str());
	OutputDebugString(", ");
	OutputDebugString(to_string(y - ysize).c_str());
	OutputDebugString(" ");
}

//캔버스를 그려주는 함수
void Canvas::display(Frame *f) {
	f->setPen(RGB(100, 100, 100), 1);
	f->rectangle(m_x, m_y, m_xsize, m_ysize);
}

