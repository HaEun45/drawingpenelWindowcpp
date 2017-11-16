#include "stdafx.h" 
#include "Menu.h"
#include "Frame.h"

//생성자
Menu::Menu(string s) : Window(s , 0, 0, area, 80) {
	m_text = s; //text를 s에 저장
}

//변화된 x의 값을 저장하는 함수
void Menu::setX(int menux) {
	m_x = menux; //바뀐 menux를 m_x에 저장한다(초기화)
}

//화면에 출력해 줄 함수
void Menu::display() {
	if (m_menuNext) { //다음 포인터가 있다면
		m_menuNext->display(); //화면에 출력해준다.
	}
	m_Frame->setPen(RGB(100, 100, 100), 1);
	m_Frame->rectangle(m_x, m_y, m_xsize, m_ysize);
	drawContent();
}

//클릭한 경우 출력하는 부분
void Menu::onMouseClick(int x, int y) {
	if (x >= 0 && x <= 200 && y >= 0 && y <= 100) {
		OutputDebugString("File Clicked.\n");
	}
	else {
		OutputDebugString("Edit Clicked.\n");
	}
}

//다음 포인터 값에 메뉴 포인터를 저장한다.
void Menu::setNext(Menu *m){
	m_menuNext = m;
}

////범위 내의 값에 대한 포인터를 돌려주는 함수
Window* Menu::isInside(int x, int y) {
	if (m_x <= x && x < m_x + m_xsize && m_y <= y && y < m_y + m_ysize) {//범위 안이라면
		return this;  //자기자신을 반환
	}
	else {  //아닌 경우 계속 하고
		if (m_menuNext != 0) {
			return m_menuNext->isInside(x, y);
		}
		else { //없으면 0을 반환한다.
			return 0;
		}
	}
}