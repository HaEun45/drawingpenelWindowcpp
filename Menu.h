#pragma once
#include "Container.h"
#include<iostream>
using namespace std;

class Frame;
class MenuBar;
class Menu :public Container {
public:
	Menu(string s); //������
	void setX(int menux); //�޴��� ����� x�� ��ġ ���� �Լ�
	void setNext(Menu *m); //���� ������ �����Լ�
	virtual void onMouseClick(int x, int y);//Ŭ���Լ�
	Window* isInside(int x, int y); //�������� �������� �����͸� ��ȯ�ϴ� �Լ�
	void display(Frame *f);  //ȭ�鿡 ��Ÿ���ִ� �Լ�
private:
	Menu * m_menuNext;  //�޴��� ���� ������ ���� ����
};