//#include <fstream>
#include "stdafx.h" 
#include "Menubar.h"
#include "Frame.h"


//생성자 
MenuBar::MenuBar() : Container(xcoordinate, ycoordinate, xsize, ysize) {
	m_menux = 0; //0으로 초기화한다.
}

//마우스를 클릭했을 때 일어나는 일에 대한 함수
void MenuBar::onMouseClick(int x, int y) {
	OutputDebugString("MenuBar Clicked. "); //먼저 출력한다.
	Window * tmp = find(x, y); //임시변수 temp에 메뉴를 찾아서 넣는다
	if (tmp != 0) { //메뉴가 있는 경우만
		tmp->onMouseClick(x, y); //클릭한 경우 내용을 출력해준다.
	}
}

//menu등록함수
void MenuBar::add(Menu *m) {
	m->setX(m_menux); //x를 변화시켜 줄 함수를 가리킨다.
	m_menux += xmenusize;
	m->setNext(m_firstMenu);  //연결
	m_firstMenu = m; //연결후 저장
	
}

//내용을 출력해준다.
void MenuBar::display(Frame *f) {
	
	f->setPen(RGB(100, 100, 100), 1);
	f->rectangle(m_x, m_y, m_xsize, m_ysize);
	drawContent(f);

	m_firstMenu->display(f);//메뉴바를 출력한 후 메뉴도 출력해준다.
}
//메뉴를 찾는다.   
Window * MenuBar::find(int x, int y) {
	// 각 메뉴에게 isInside(x, y) 를 물어서 클릭된 객체의 포인터를 돌려주자.
	return m_firstMenu->isInside(x, y);
} 
//메뉴를 찾거나 메뉴바를 찾아서 반환해주는 함수
Window* MenuBar::isInside(int x, int y) {
	//메뉴바안에 있다면
	if (m_x <= x && x < m_x + m_xsize &&	m_y <= y && y < m_y + m_ysize) {
		Window * temp = find(x, y); //임시변수 temp에 메뉴를 찾는 함수를 넣어놓고
		if (temp) { //메뉴가 있으면
			return temp; //그 메뉴를 반환하고
		}
		else {  //메뉴가 없으면 
			return this;  //메뉴바를 반환한다.
		}
	}
	else {
		return 0;
	}
}