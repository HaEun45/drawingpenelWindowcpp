//#include<fstream>
#include "stdafx.h" 
#include "Canvas.h"

//������
Canvas::Canvas(Frame *f):Window(xcoordinate,ycoordinate+ysize,xsize,ycansize) {
}
//���콺�� Ŭ���� ��� �߻��ϴ� �ϵ鿡 ���� �Լ�
void Canvas::onMouseClick(int x, int y) {
	OutputDebugString("Canvas: ");
	OutputDebugString(to_string(x).c_str());
	OutputDebugString(", ");
	OutputDebugString(to_string(y - ysize).c_str());
	OutputDebugString(" ");
}

//ĵ������ �׷��ִ� �Լ�
void Canvas::display(Frame *f) {
	f->setPen(RGB(100, 100, 100), 1);
	f->rectangle(m_x, m_y, m_xsize, m_ysize);
}

