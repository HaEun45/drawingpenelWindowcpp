#include "stdafx.h" 
#include "Menuitem.h"
#include "Frame.h"
#include "Menu.h"

//생성자
MenuItem::MenuItem(string s) : Window(XCOORDINATE,XSIZE, XMENUSIZE, YSIZE) {
	m_text = s;
}

//변화된 x,y의 값을 저장하는 함수
void MenuItem::setXY(int menuitemx, int menuitemy) {
	m_x = menuitemx;
	m_y = menuitemy; //바뀐 menuitemy를 m_y에 저장한다(초기화)
}

//메뉴아이템의 범위에 있는지 없는지 확인해주는 함수
Window* MenuItem::isInside(int x, int y) {
	if (m_x <= x && x < m_x + m_xsize && m_y <= y && y < m_y + m_ysize) {//범위 안이라면
		return this;  //자기자신을 반환
	}
	else { //없으면 0을 반환한다.
		return 0;
	}
}

//마우스가 클릭되면 메뉴를 출력한다
void MenuItem::onMouseClick(int x, int y) {
	OutputDebugString(m_text.c_str()); // 메뉴안의 내용을 출력한다.
	OutputDebugString(" Clicked.\n");
	m_frame->processEvent(this); //메뉴아이템이 자신의 주소를 전달해준다.
}


//메뉴아이템을 만들어주는 함수
void MenuItem::display() {
	m_frame->setPen(RGB(100, 100, 100), 1);
	m_frame->rectangle(m_x, m_y, m_xsize, m_ysize);
	drawContent();
	//메뉴아이템은 더이상 불러올 것이 없으므로 list에 넣지 않는다.

}


//마우스를 뗄 때 출력하는 함수
void MenuItem::onMouseClickUp(int x, int y) {
	OutputDebugString("Menuitem Clicked Up.\n");
}


