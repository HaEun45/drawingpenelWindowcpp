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
	m_menubar->addMenu(menuFile = new Menu("파일"));
	m_menubar->addMenu(menuEdit = new Menu("편집"));

	menuFile->addMenuItem(miOpen = new MenuItem("열기"));
	menuFile->addMenuItem(miSave = new MenuItem("저장"));
	menuFile->addMenuItem(miExit = new MenuItem("끝내기"));

	menuEdit->addMenuItem(miCopy = new MenuItem("복사"));
	menuEdit->addMenuItem(miCut = new MenuItem("자르기"));
	menuEdit->addMenuItem(miPaste = new MenuItem("붙이기"));

	
}
//메뉴 아이템은 자신의 주소를 전달해주어야 MyFrame이 무슨 행동을 할 지 결정할 수 있다.
//메뉴아이템을 클릭했을 때 출력되는 함수
//각각 메뉴아이템의 포인터와 비교한다.
void MyFrame::processEvent(Window * src) {
	if (src == miOpen) {
		OutputDebugString("메뉴아이템 열기를 클릭");
	}
	else if (src == miSave) {
		OutputDebugString("메뉴아이템 저장을 클릭");
	}
	else if (src == miExit) {
		OutputDebugString("메뉴아이템 나가기를 클릭");
	}
	else if (src == miCopy) {
		OutputDebugString("메뉴아이템 복사를 클릭");
	}
	else if (src == miCut) {
		OutputDebugString("메뉴아이템 지우기를 클릭");
	}
	else if (src == miPaste) {
		OutputDebugString("메뉴아이템 붙여넣기를 클릭");
	}
}