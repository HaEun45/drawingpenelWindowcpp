//#include <fstream>
#include "stdafx.h" 
#include "Menubar.h"
#include "Frame.h"


//생성자 
MenuBar::MenuBar() : Container(xcoordinate, ycoordinate, xsize, ysize) {
	m_menux = 0; //0으로 초기화한다.
	windowList = new list<Window *>; //WindowList를 interface화 시킨다-공간을 만들어준다.
}

//menu등록함수
void MenuBar::addMenu(Menu *m) {
	
	m->setContainer(this); //메뉴아이템에 메뉴를 등록한다.
	m->setFrame(m_frame); //window에 있는 m_frame을 전달한다.
	m->setX(m_menux); //x를 변화시켜 줄 함수를 가리킨다.
	m_menux += xmenusize;
	windowList->push_back(m); // 끝에 요소(포인터)를 추가한다.
}

//내용을 출력해준다.  //1-2
void MenuBar::display() {

	m_frame->setPen(RGB(100, 100, 100), 1);
	m_frame->rectangle(m_x, m_y, m_xsize, m_ysize);
	drawContent();
	//메뉴의 그림을 그려준다
	list<Window *>::iterator i;
	for (i = windowList->begin(); i != windowList->end(); i++) {
		((Menu*)*i)->display(); //Menu의 display
	}
}

//3
//메뉴를 찾는다. - 메뉴를 찾아서 찾은 메뉴를 반환해주는 역할
//find는 여러개 펼쳐져있을때
//4-2
Window* MenuBar::find(int x, int y) {
	//처음부터 끝까지 해당 범위(메뉴)내에 클릭이되었는지 확인한다.
	//메뉴아이템을 찾는다.
	list<Window *>::iterator i;
	for (i = windowList->begin(); i != windowList->end(); i++) {
		Window* temp = ((Menu *)*i)->find(x, y); //형변환을 시켜주어야한다.
		if (temp) { //리턴타입이 있으면 
			return temp; //메뉴 또는 메뉴아이템이 반환된다
		}
		//return 0;
	}
	return 0;
}


//5-2
//마우스를 클릭했을 때 일어나는 일에 대한 함수
void MenuBar::onMouseClick(int x, int y) {
	OutputDebugString("MenuBar Clicked. "); //먼저 출력한다.
	list<Window *>::iterator i;
	for (i = windowList->begin(); i != windowList->end(); i++) {
		Window *temp=((Menu*)*i)->isInside(x, y); //메뉴를 찾는다 //find로 하면 안됨
		if(temp) { 
			temp->onMouseClick(x, y); //메뉴가 있다면 출력된다.
			//메뉴를 출력하면서 이때 상태를 true라고 한다.
		}
	}
	/*
	Window * tmp = find(x, y); //임시변수 temp에 메뉴를 찾아서 넣는다
	if (tmp != 0) { //메뉴가 있는 경우만
		tmp->onMouseClick(x, y); //클릭한 경우 내용을 출력해준다.
	}*/
}


//메뉴를 찾아서 반환하거나 메뉴바를 반환해주는 함수-해당범위내에 있는지 확인
Window* MenuBar::isInside(int x, int y) {
	//메뉴바안에 있다면
	if (m_x <= x && x < m_x + m_xsize &&	m_y <= y && y < m_y + m_ysize) {
		return this;  //메뉴바를 반환한다.
	}
	else {
		return 0;
	}
}


//옆에 메뉴가 클릭되면 
//클릭된 메뉴의 메뉴아이템이 클릭되어져야한다.
//다른 메뉴아이템은 닫혀야 한다.

//메뉴에게 닫으라고 보낸다.
//inside 한개 내 판단 - 펼쳐져있지 않을 때->이용한다.
//find 여러개 내 판단- 펼쳐져 있을 때
void MenuBar::closeAllMenu() {  
	//일단 모든 메뉴아이템을 닫아야하니까 반복을한다.
	list<Window *>::iterator i; 
	for (i = windowList->begin(); i != windowList->end(); i++) {
		((Menu*)*i)->allMenuFalse(); //부울변수를 모두다 false로 바꾼다.
	}
}


//3-2
//메뉴한개만 메뉴아이템을 보여주도록한다.->아이템 하나만 참이여야한다.
Window* MenuBar::openOneMenu() {
	list<Window *>::iterator i;
	for (i = windowList->begin(); i != windowList->end(); i++) {
		Menu * m = ((Menu*)*i)->oneMenuTrue(); //메뉴를 반환해준다
		if (m) { //메뉴가 있으면 메뉴를 출력한다.
			return m;
		}
	}
	return 0;
}
