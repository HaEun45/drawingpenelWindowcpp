#pragma once
#include "Window.h"
#include <iostream>
#include <string>
using namespace std;

class MenuItem:public Window{
public:
	MenuItem(string s); 
	virtual void onMouseClick(int x, int y); //���콺�� Ŭ���� �� ����ϴ� �Լ�
	void display();
	Window *isInside(int x, int y);
	void setXY(int menuitemx, int menuitemy); //��ȭ�� x,y���� �����ϴ� �Լ�
	void onMouseClickUp(int x, int y); //���콺�� �� �� ����ϴ� �Լ�

};
