#include <fstream>
#include "stdafx.h"
#include "Window.h"
#include "Frame.h"


//기본 생성자
Window::Window() {
}
//매개변수가 있는 생성자
Window::Window(int x, int y, int sx, int sy) :
	m_x(x), m_y(y), m_xsize(sx), m_ysize(sy) {
}

//내용을 그려주는 함수
void Window::drawContent() {
	m_frame->drawText(m_text, m_x + 5, m_y + 5);
}

//여기서 프레임에 메뉴와 캔버스를 저장한다.
void Window::setContainer(Container *con) {
	m_container = con;
} 

//프레임을 저장해준다. 
void Window::setFrame(Frame *f) {
	m_frame = f;
}

void Window::onMouseClickUp(int x, int y) {
}
