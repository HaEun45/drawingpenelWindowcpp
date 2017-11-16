#pragma once
#include "Window.h"


class MenuBar;
class Menu :public Window{
public:
	Menu(string s); //생성자
	void setX(int menux); //메뉴를 출력할 x의 위치 설정 함수
	virtual void display(); //화면에 출력
	virtual void onMouseClick(int x, int y);//클릭함수
	virtual void setNext(Menu *m); //다음 포인터 설정함수
	virtual Window* isInside(int x, int y); //범위내의 값에대한 포인터를 반환하는 함수
private:
	Menu * m_menuNext;  //메뉴의 다음 포인터 변수 선언
};