#include <fstream>
#include "stdafx.h"
#include "Window.h"
//�⺻ ������
Window::Window() {
}
//�Ű������� �ִ� ������
Window::Window(int x, int y, int sx, int sy) :
	m_x(x), m_y(y), m_xsize(sx), m_ysize(sy) {
}