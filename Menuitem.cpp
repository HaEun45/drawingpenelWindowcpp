#include "stdafx.h" 
#include "Menuitem.h"
#include "Frame.h"
#include "Menu.h"

//생성자
MenuItem::MenuItem(string s) : Window(0,xsize, xmenusize, ysize) {
	m_text = s;
}

//변화된 x,y의 값을 저장하는 함수
void MenuItem::setXY(int menuitemx,int menuitemy) {
	m_x = menuitemx;
	m_y = menuitemy; //바뀐 menuitemy를 m_y에 저장한다(초기화)
}
//마우스가 클릭되면 메뉴를 출력한다
void MenuItem::onMouseClick(int x, int y) {
	OutputDebugString(m_text.c_str()); // 메뉴안의 내용을 출력한다.
	OutputDebugString(" Clicked.\n");
}
//4-5
Window* MenuItem::isInside(int x, int y) {
	if (m_x <= x && x < m_x + m_xsize && m_y <= y && y < m_y + m_ysize) {//범위 안이라면
		return this;  //자기자신을 반환
	}
	else { //없으면 0을 반환한다.
		return 0;
	}
}
//
void MenuItem::display() {
	m_frame->setPen(RGB(100, 100, 100), 1);
	m_frame->rectangle(m_x, m_y, m_xsize, m_ysize);
	drawContent();
	//메뉴아이템은 더이상 불러올 것이 없으므로 list에 넣지 않는다.

}