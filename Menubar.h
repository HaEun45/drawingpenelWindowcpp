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
	void addMenu(Menu *m); //�޴��� �����ִ� �Լ�
	Window* isInside(int x, int y); //�޴��� ���������� �޴����� �޴������� ��ȯ���ִ� �Լ�
	Window* find(int x, int y); //������ �������� ã�Ƽ� ��ȯ���ִ� �Լ�
	Window* openOneMenu();  //�ϳ��� true�� �޴��� ã�� �Լ�
	void closeAllMenu();  //��� �޴��� false ���·� �����.
	virtual void onMouseClick(int x, int y);//���콺 Ŭ�� �Լ�
	void display(); //ȭ�鿡 ��Ÿ���ִ� �Լ�  //����� ����
	virtual void onMouseClickUp(int x, int y); //���콺 �� �� ��µǴ� �Լ�
protected:
	int m_menux; //�޴��� ������ ��Ÿ���� ���� ���� ����
};
