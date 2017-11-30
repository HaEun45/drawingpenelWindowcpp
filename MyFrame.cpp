#include "stdafx.h" 
#include "MyFrame.h"
#include "MenuBar.h"
#include "Canvas.h"
#include "Menu.h"
#include "MenuItem.h"


//생성자
MyFrame::MyFrame(HWND w):Frame(w){}


void MyFrame::onInitialize(){

	// *** 모든 윈도들을 여기에서 초기화하자.
	addMenuBar(new MenuBar());
	addCanvas(new Canvas());

	// menuFile 등등은 멤버 변수로 했다. 나중에  event source를 파악해야하니까.
	m_menubar->addMenu(menuFigure = new Menu("도형"));
	m_menubar->addMenu(menuColor = new Menu("색"));

	menuFigure->addMenuItem(miRectangle = new MenuItem("사각형"));
	menuFigure->addMenuItem(miEllipse = new MenuItem("타원"));
	menuFigure->addMenuItem(miLine = new MenuItem("선분"));

	menuColor->addMenuItem(miBlack = new MenuItem("검은색"));
	menuColor->addMenuItem(miRed = new MenuItem("빨간색"));
	menuColor->addMenuItem(miBlue = new MenuItem("파란색"));

}
//메뉴 아이템은 자신의 주소를 전달해주어야 MyFrame이 무슨 행동을 할 지 결정할 수 있다.
//메뉴아이템을 클릭했을 때 출력되는 함수
//각각 메뉴아이템의 포인터와 비교한다.
void MyFrame::processEvent(Window * src) {
	if (src == miRectangle) {
		OutputDebugString("메뉴아이템 사각형을 클릭");
		m_canvas->setFigureType(0); //type를 알려준다.
	}
	else if (src == miEllipse) {
		OutputDebugString("메뉴아이템 타원형을 클릭");
		m_canvas->setFigureType(1);
	}
	else if (src == miLine) {
		OutputDebugString("메뉴아이템 선분을 클릭");
		m_canvas->setFigureType(2);
	}
	else if (src == miBlack) {
		OutputDebugString("메뉴아이템 검정색을 클릭");
		m_canvas->setColor(RGB(0, 0, 0)); //컬러를 저장한다.
	}
	else if (src == miRed) {
		OutputDebugString("메뉴아이템 빨간색을 클릭");
		m_canvas->setColor(RGB(255, 0, 0));
	}
	else if (src == miBlue) {
		OutputDebugString("메뉴아이템 파란색을 클릭");
		m_canvas->setColor(RGB(0, 0, 255));
	}
}
