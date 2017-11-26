#include "stdafx.h" 
#include "Menubar.h"
#include "Menu.h"
#include "Menuitem.h"
#include "Frame.h"



//메뉴생성자
Menu::Menu(string s) : Container(s , XCOORDINATE, YCOORDINATE, XMENUSIZE, YSIZE) {
	m_text = s; //text를 s에 저장
	m_menuitemy = 0;
	windowList = new list<Window *>;
	//menuState = true; 
	menuState = false;
}

//변화된 x의 값을 저장하는 함수
void Menu::setX(int menux) {
	m_x = menux; //바뀐 menux를 m_x에 저장한다(초기화)
}


//메뉴아이템 등록함수
void Menu::addMenuItem(MenuItem * mi) {
	mi->setFrame(m_frame);
	m_menuitemy += YSIZE;
	mi->setXY(m_x, m_menuitemy); //자신의 m_x를  메뉴아이템에게 준다.
	windowList->push_back(mi); //메뉴아이템을 넣어준다

}



//메뉴가 눌러지면 true로 바뀌고 다른창은 다false
//메뉴가 눌러지지 않으면 다 false

//화면에 Menu를 출력해 줄 함수 //Menubar의 display에서 Menu의 display를 호출해준다.
void Menu::display() {
	m_frame->setPen(RGB(100, 100, 100), 1);
	m_frame->rectangle(m_x, m_y, m_xsize, m_ysize);
	drawContent();

}

//메뉴아이템을 찾는다.
Window* Menu::find(int x, int y) {
	list<Window *>::iterator i;
	for (i = windowList->begin(); i != windowList->end(); i++) {
		Window * tmp = ((MenuItem*)*i)->isInside(x, y);
		if (tmp) {
			return tmp; //메뉴아이템 반환
		}
	}
	return 0;
}


//메뉴를 클릭한 경우 출력하는 부분
void Menu::onMouseClick(int x, int y) {
	OutputDebugString(m_text.c_str()); // 메뉴안의 내용을 출력한다.
	OutputDebugString(" Clicked.\n");	
	menuState = true; // 메뉴에 마우스가 눌렸으면 메뉴의 상태변수는 true이다.
}

//마우스 뗼 때 출력되는 함수
void Menu::onMouseClickUp(int x, int y) {
	OutputDebugString(" Menu Cliked Up.\n");
}

//메뉴를 찾아주는 함수
Window* Menu::isInside(int x, int y) {
	if (m_x <= x && x < m_x + m_xsize && m_y <= y && y < m_y + m_ysize) {//범위 안이라면
		return this;  //메뉴만 반환
	}
	else { //없으면 0을 반환한다.
		return 0;
	}
}
//----------------------------------메뉴아이템을 호출하기위한 함수

//메뉴아이템의 디스플레이를 호출하는 함수
void Menu::callMenuitemDisplay() {
	list<Window *>::iterator i;
	for (i = windowList->begin(); i != windowList->end(); i++) {
		//f->invalidate();
		((MenuItem*)*i)->display();
	}
}

//모두 false가 되도록만든다
void Menu::allMenuFalse() { 
	menuState = false; //마우스가 메뉴를 클릭해서 ture였던 상태를 모두 false로 바꾼다.
}


//메뉴아이템 상태가 참, 즉 선택되면 메뉴아이템들을 반환해준다.
Menu * Menu::oneMenuTrue() {
	if (menuState == true) {
		return this;
	}
	else {
		return 0;
	}
}

