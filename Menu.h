#pragma once
#include "Container.h"
//#include "Menuitem.h"
#include<iostream>
using namespace std;

class MenuItem;
class Frame;
class MenuBar;
class Menu :public Container {
public:
	Menu(string s); //생성자
	void setX(int menux); //메뉴를 출력할 x의 위치 설정 함수
	void addMenuItem(MenuItem * mi);
	void display();  //화면에 나타내주는 함수
	void onMouseClick(int x, int y);//클릭함수
	Window* isInside(int x, int y); //범위내의 값에대한 포인터를 반환하는 함수
	Window* find(int x, int y);
	//bool Menu::AreYouMenuClick(int x, int y);
	void callMenuitemDisplay();  //전체를 출력해준다.
	void allMenuFalse();   //모든 메뉴를 false로 만든다.
	Menu* Menu::oneMenuTrue(); //true인 메뉴를 찾는다.
	void onMouseClickUp(int x, int y); //마우스 뗼 때 출력되는 함수

private:
	bool menuState;  //상태변수
	int m_menuitemx,m_menuitemy; //위치 설정위한 변수
};