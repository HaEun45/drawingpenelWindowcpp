#include "stdafx.h"
#include "Window.h"
#include "Frame.h"
#include <fstream>

Window::Window(int x, int y, int sx, int sy) :
	m_x(x), m_y(y), m_xsize(sx), m_ysize(sy), m_text("") {
}

Window::Window(string s, int x, int y, int sx, int sy)
	: Window(x, y, sx, sy)
{
	m_text = s;
}

void Window::setFrame(Frame *v) {
	m_Frame = v;
}

void Window::display() {
	if (m_next) {  //만약 다음이 존재한다면
		m_next->display(); //화면에 나타낸다.
	}
	m_Frame->setPen(RGB(100, 100, 100), 1);
	m_Frame->rectangle(m_x, m_y, m_xsize, m_ysize);
	drawContent();
}
void Window::drawContent() {
	m_Frame->drawText(m_text, m_x + 5, m_y + 5);
}
void Window::onMouseClick(int x, int y) {
	//logger << "Window clicked, ";
	//logger << "Name: " << m_text << endl;
	OutputDebugString(m_text.c_str());
	OutputDebugString("Clicked \n");
}

//범위내에 있는지 없는지 확인해주는 함수
Window* Window::isInside(int x, int y) {
	if (m_x <= x && x < m_x + m_xsize &&	m_y <= y && y < m_y + m_ysize) {
		return this;
	}
	else {
		if (m_next!= 0) {
			return m_next->isInside(x, y);
		}
		else {
			return 0;
		}
	}
}

//다음 포인터에 저장해준다.
void Window::setNext(Window *w) {
	m_next = w;
}

