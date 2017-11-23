#pragma once
#include "Container.h"
#include "Menuitem.h"
#include<iostream>
using namespace std;

class MenuItem;
class Frame;
class MenuBar;
class Menu :public Container {
public:
	Menu(string s); //생성자
	void setX(int menux); //메뉴를 출력할 x의 위치 설정 함수
	void display(Frame *f);  //화면에 나타내주는 함수
	void onMouseClick(int x, int y);//클릭함수
	Window* isInside(int x, int y); //범위내의 값에대한 포인터를 반환하는 함수
	void addMenuItem(MenuItem * m);
	Window* find(int x, int y);
	//bool Menu::AreYouMenuClick(int x, int y);
	void callMenuitemDisplay(Frame *f);
	void allMenuFalse();
	Menu* Menu::oneMenuTrue();
private:
	bool menuState;
	int m_menuitemx,m_menuitemy;
};