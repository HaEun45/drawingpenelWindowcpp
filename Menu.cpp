#include "stdafx.h" 
#include "Menu.h"
#include "Frame.h"

//������
Menu::Menu(string s) : Window(s , 0, 0, area, 80) {
	m_text = s; //text�� s�� ����
}

//��ȭ�� x�� ���� �����ϴ� �Լ�
void Menu::setX(int menux) {
	m_x = menux; //�ٲ� menux�� m_x�� �����Ѵ�(�ʱ�ȭ)
}

//ȭ�鿡 ����� �� �Լ�
void Menu::display() {
	if (m_menuNext) { //���� �����Ͱ� �ִٸ�
		m_menuNext->display(); //ȭ�鿡 ������ش�.
	}
	m_Frame->setPen(RGB(100, 100, 100), 1);
	m_Frame->rectangle(m_x, m_y, m_xsize, m_ysize);
	drawContent();
}

//Ŭ���� ��� ����ϴ� �κ�
void Menu::onMouseClick(int x, int y) {
	if (x >= 0 && x <= 200 && y >= 0 && y <= 100) {
		OutputDebugString("File Clicked.\n");
	}
	else {
		OutputDebugString("Edit Clicked.\n");
	}
}

//���� ������ ���� �޴� �����͸� �����Ѵ�.
void Menu::setNext(Menu *m){
	m_menuNext = m;
}

////���� ���� ���� ���� �����͸� �����ִ� �Լ�
Window* Menu::isInside(int x, int y) {
	if (m_x <= x && x < m_x + m_xsize && m_y <= y && y < m_y + m_ysize) {//���� ���̶��
		return this;  //�ڱ��ڽ��� ��ȯ
	}
	else {  //�ƴ� ��� ��� �ϰ�
		if (m_menuNext != 0) {
			return m_menuNext->isInside(x, y);
		}
		else { //������ 0�� ��ȯ�Ѵ�.
			return 0;
		}
	}
}