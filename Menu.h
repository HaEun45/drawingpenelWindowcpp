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
	Menu(string s); //������
	void setX(int menux); //�޴��� ����� x�� ��ġ ���� �Լ�
	void addMenuItem(MenuItem * mi);
	void display();  //ȭ�鿡 ��Ÿ���ִ� �Լ�
	void onMouseClick(int x, int y);//Ŭ���Լ�
	Window* isInside(int x, int y); //�������� �������� �����͸� ��ȯ�ϴ� �Լ�
	Window* find(int x, int y);
	//bool Menu::AreYouMenuClick(int x, int y);
	void callMenuitemDisplay();  //��ü�� ������ش�.
	void allMenuFalse();   //��� �޴��� false�� �����.
	Menu* Menu::oneMenuTrue(); //true�� �޴��� ã�´�.
	void onMouseClickUp(int x, int y); //���콺 �� �� ��µǴ� �Լ�

private:
	bool menuState;  //���º���
	int m_menuitemx,m_menuitemy; //��ġ �������� ����
};