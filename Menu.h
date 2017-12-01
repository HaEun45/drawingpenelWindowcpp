#pragma once
#include "Container.h"
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
	Window* find(int x, int y);
	Window* isInside(int x, int y); //�������� �������� �����͸� ��ȯ�ϴ� �Լ�
	Menu* oneMenuTrue(); //true�� �޴��� ã�´�.
	void onMouseClick(int x, int y);//Ŭ���Լ�
	void allMenuFalse();   //��� �޴��� false�� �����.
	void display();  //ȭ�鿡 ��Ÿ���ִ� �Լ�
	void onMouseClickUp(int x, int y); //���콺 �� �� ��µǴ� �Լ�
	void callMenuitemDisplay();  //��ü�� ������ش�.

private:
	bool menuState;  //���º���
	int m_menuitemx,m_menuitemy; //��ġ �������� ����
};