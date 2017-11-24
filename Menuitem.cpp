#include "stdafx.h" 
#include "Menuitem.h"
#include "Frame.h"
#include "Menu.h"

//������
MenuItem::MenuItem(string s) : Window(0,xsize, xmenusize, ysize) {
	m_text = s;
}

//��ȭ�� x,y�� ���� �����ϴ� �Լ�
void MenuItem::setXY(int menuitemx,int menuitemy) {
	m_x = menuitemx;
	m_y = menuitemy; //�ٲ� menuitemy�� m_y�� �����Ѵ�(�ʱ�ȭ)
}
//���콺�� Ŭ���Ǹ� �޴��� ����Ѵ�
void MenuItem::onMouseClick(int x, int y) {
	OutputDebugString(m_text.c_str()); // �޴����� ������ ����Ѵ�.
	OutputDebugString(" Clicked.\n");
}
//4-5
Window* MenuItem::isInside(int x, int y) {
	if (m_x <= x && x < m_x + m_xsize && m_y <= y && y < m_y + m_ysize) {//���� ���̶��
		return this;  //�ڱ��ڽ��� ��ȯ
	}
	else { //������ 0�� ��ȯ�Ѵ�.
		return 0;
	}
}
//
void MenuItem::display() {
	m_frame->setPen(RGB(100, 100, 100), 1);
	m_frame->rectangle(m_x, m_y, m_xsize, m_ysize);
	drawContent();
	//�޴��������� ���̻� �ҷ��� ���� �����Ƿ� list�� ���� �ʴ´�.

}