#pragma once
#include "Window.h"
#include <iostream>
#include <string>
using namespace std;

class MenuItem:public Window{
public:
	MenuItem(string s); 
	void setXY(int menuitemx, int menuitemy); //변화된 x,y값을 저장하는 함수
	Window *isInside(int x, int y);
	virtual void onMouseClick(int x, int y); //마우스를 클릭할 때 출력하는 함수
	void display();
	void onMouseClickUp(int x, int y); //마우스를 뗄 때 출력하는 함수

};
