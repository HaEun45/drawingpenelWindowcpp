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
	MenuBar(); //������
	void onMouseClick(int x, int y);//���콺 Ŭ�� �Լ�
	void addMenu(Menu *m); //�޴��� �����ִ� �Լ�
	void display(); //ȭ�鿡 ��Ÿ���ִ� �Լ�  //����� ����
	Window* find(int x, int y); //������ �������� ã�Ƽ� ��ȯ���ִ� �Լ�
	Window* isInside(int x, int y); //�޴��� ���������� �޴����� �޴������� ��ȯ���ִ� �Լ�
	void closeAllMenu();  //��� �޴��� false ���·� �����.
	Window* openOneMenu();  //�ϳ��� true�� �޴��� ã�� �Լ�
protected:
	int m_menux; //�޴��� ������ ��Ÿ���� ���� ���� ����
};
