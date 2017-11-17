//#include<fstream>
#include "stdafx.h" 
#include "Menubar.h"
#include "Menu.h"
#include "Frame.h"


//������
Menu::Menu(string s) : Container(s , 0, 0, xmenusize, ysize ) {
	m_text = s; //text�� s�� ����
}

//��ȭ�� x�� ���� �����ϴ� �Լ�
void Menu::setX(int menux) {
	m_x = menux; //�ٲ� menux�� m_x�� �����Ѵ�(�ʱ�ȭ)
}

//ȭ�鿡 ����� �� �Լ�
void Menu::display(Frame *f) {
	if (m_menuNext) { //���� �����Ͱ� �ִٸ�
		m_menuNext->display(f); //ȭ�鿡 ������ش�.
	}
	f->setPen(RGB(100, 100, 100), 1);
	f->rectangle(m_x, m_y, m_xsize, m_ysize);
	drawContent(f);
}

//�޴��� Ŭ���� ��� ����ϴ� �κ�
void Menu::onMouseClick(int x, int y) {
	OutputDebugString(m_text.c_str()); // �޴����� ������ ����Ѵ�.
	OutputDebugString("Clicked.\n");
	
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