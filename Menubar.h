#pragma once
#include "Window.h"
#include "Menu.h"
#include "Frame.h"
#define area 200 //���� ��ŭ �� 200���� ������ �д�.

class Menu;
class MenuBar : public Window {
public:
	MenuBar(Frame * f); //������
	virtual void onMouseClick(int x, int y);//���콺 Ŭ�� �Լ�
	void add(Menu *m); //�޴��� �����ִ� �Լ�
	Window * find(int x, int y); //������(�޴���) ã���ִ� �Լ�
	void display(); //ȭ�鿡 ��Ÿ���ִ� �Լ�
private:
	Menu * m_firstMenu; //�޴��� ù��° ������ ���� ����
	int m_menux; //�޴��� ������ ��Ÿ���� ���� ���� ����
};