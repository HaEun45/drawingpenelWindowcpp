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
	Menu(string s); //������
	void setX(int menux); //�޴��� ����� x�� ��ġ ���� �Լ�
	void display(Frame *f);  //ȭ�鿡 ��Ÿ���ִ� �Լ�
	void onMouseClick(int x, int y);//Ŭ���Լ�
	Window* isInside(int x, int y); //�������� �������� �����͸� ��ȯ�ϴ� �Լ�
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