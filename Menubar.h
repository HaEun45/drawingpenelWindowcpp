#pragma once
#include<iostream>
#include "Container.h"
#include "Menu.h"
using namespace std;

class Frame;
class Menu;
class MenuBar : public Container {
public:
	MenuBar(); //������
	virtual void onMouseClick(int x, int y);//���콺 Ŭ�� �Լ�
	void add(Menu *m); //�޴��� �����ִ� �Լ�
	Window *find(int x, int y); //������(�޴���) ã���ִ� �Լ�
	void display(Frame *f); //ȭ�鿡 ��Ÿ���ִ� �Լ�
	virtual Window* isInside(int x, int y); //�޴��� ���������� �޴����� �޴������� ��ȯ���ִ� �Լ�
protected:
	Menu * m_firstMenu; //�޴��� ù��° ������ ���� ����
	int m_menux; //�޴��� ������ ��Ÿ���� ���� ���� ����
};
