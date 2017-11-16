#pragma once
#include "Window.h"
#include "Menu.h"
#include "Frame.h"
#define area 200 //더할 만큼 을 200으로 정의해 둔다.

class Menu;
class MenuBar : public Window {
public:
	MenuBar(Frame * f); //생성자
	virtual void onMouseClick(int x, int y);//마우스 클릭 함수
	void add(Menu *m); //메뉴를 더해주는 함수
	Window * find(int x, int y); //윈도우(메뉴를) 찾아주는 함수
	void display(); //화면에 나타내주는 함수
private:
	Menu * m_firstMenu; //메뉴의 첫번째 포인터 변수 선언
	int m_menux; //메뉴를 여러개 나타내기 위한 변수 선언
};