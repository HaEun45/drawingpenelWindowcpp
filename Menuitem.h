#pragma once
#include "Window.h"
#include <iostream>
#include <string>
using namespace std;

class MenuItem:public Window{
public:
	MenuItem(string s); 
	void setXY(int menuitemx, int menuitemy); //��ȭ�� x,y���� �����ϴ� �Լ�
	Window *isInside(int x, int y);
	virtual void onMouseClick(int x, int y); //���콺�� Ŭ���� �� ����ϴ� �Լ�
	void display();
	void onMouseClickUp(int x, int y); //���콺�� �� �� ����ϴ� �Լ�

};
