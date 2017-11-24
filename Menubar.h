#pragma once
#include<iostream>
#include "Container.h"
#include "Menu.h"
#include <list>
using namespace std;

class Frame;
class Menu;
class MenuBar : public Container {
public:
	MenuBar(); //생성자
	void onMouseClick(int x, int y);//마우스 클릭 함수
	void addMenu(Menu *m); //메뉴를 더해주는 함수
	void display(); //화면에 나타내주는 함수  //버츄얼 써줌
	Window* find(int x, int y); //윈도우(메뉴를) 찾아주는 함수
	Window* isInside(int x, int y); //메뉴바 범위내에서 메뉴인지 메뉴바인지 반환해주는 함수
	void closeAllMenu(); 
	Window* openOneMenu();
protected:
	int m_menux; //메뉴를 여러개 나타내기 위한 변수 선언
};
