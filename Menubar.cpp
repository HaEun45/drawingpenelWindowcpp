#include "stdafx.h" 
#include "Menubar.h"
#include "Frame.h"

//생성자 
MenuBar::MenuBar(Frame *f) : Window(0, 0, 620, 80) { 
	m_Frame = f;  //상속받은 Window의 멤버변수 m_Frame에 프레임에서 전달받은 f로 초기화
	f->registerWindow(this); //받은 frame을 등록해준다.
	m_menux = 0; //0으로 초기화한다.
}

//마우스를 클릭했을 때 일어나는 일에 대한 함수
void MenuBar::onMouseClick(int x, int y) {
	OutputDebugString("MenuBar Clicked. "); //먼저 출력한다.
	Window *w = find(x, y);  //윈도우의 w에 범위내에 x,y가 있는지 확인하고 저장한다.
	if (w) { //만약 윈도우가 있다면
		w->onMouseClick(x, y); //onMouseClick함수를 가리킨다.
	}
}

//menu등록함수
void MenuBar::add(Menu *m) {
	m->setX(m_menux); //x를 변화시켜 줄 함수를 가리킨다.
	m_menux += area;
	m->setFrame(m_Frame);
	m->setNext(m_firstMenu);  //연결
	m_firstMenu = m;
	
}
void MenuBar::display() {
	Window::display();
	m_firstMenu->display();
}
   
Window * MenuBar::find(int x, int y) {
	// 각 메뉴에게 isInside(x, y) 를 물어서 클릭된 객체의 포인터를 돌려주자.
	return m_firstMenu->isInside(x, y);
} 

                              