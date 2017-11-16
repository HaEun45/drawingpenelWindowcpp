#pragma once
#include "Window.h"


class MenuBar;
class Menu :public Window{
public:
	Menu(string s); //������
	void setX(int menux); //�޴��� ����� x�� ��ġ ���� �Լ�
	virtual void display(); //ȭ�鿡 ���
	virtual void onMouseClick(int x, int y);//Ŭ���Լ�
	virtual void setNext(Menu *m); //���� ������ �����Լ�
	virtual Window* isInside(int x, int y); //�������� �������� �����͸� ��ȯ�ϴ� �Լ�
private:
	Menu * m_menuNext;  //�޴��� ���� ������ ���� ����
};