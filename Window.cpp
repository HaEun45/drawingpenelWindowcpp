#include <fstream>
#include "stdafx.h"
#include "Window.h"
//기본 생성자
Window::Window() {
}
//매개변수가 있는 생성자
Window::Window(int x, int y, int sx, int sy) :
	m_x(x), m_y(y), m_xsize(sx), m_ysize(sy) {
}