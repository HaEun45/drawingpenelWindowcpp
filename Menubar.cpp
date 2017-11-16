#include "stdafx.h" 
#include "Menubar.h"
#include "Frame.h"

//������ 
MenuBar::MenuBar(Frame *f) : Window(0, 0, 620, 80) { 
	m_Frame = f;  //��ӹ��� Window�� ������� m_Frame�� �����ӿ��� ���޹��� f�� �ʱ�ȭ
	f->registerWindow(this); //���� frame�� ������ش�.
	m_menux = 0; //0���� �ʱ�ȭ�Ѵ�.
}

//���콺�� Ŭ������ �� �Ͼ�� �Ͽ� ���� �Լ�
void MenuBar::onMouseClick(int x, int y) {
	OutputDebugString("MenuBar Clicked. "); //���� ����Ѵ�.
	Window *w = find(x, y);  //�������� w�� �������� x,y�� �ִ��� Ȯ���ϰ� �����Ѵ�.
	if (w) { //���� �����찡 �ִٸ�
		w->onMouseClick(x, y); //onMouseClick�Լ��� ����Ų��.
	}
}

//menu����Լ�
void MenuBar::add(Menu *m) {
	m->setX(m_menux); //x�� ��ȭ���� �� �Լ��� ����Ų��.
	m_menux += area;
	m->setFrame(m_Frame);
	m->setNext(m_firstMenu);  //����
	m_firstMenu = m;
	
}
void MenuBar::display() {
	Window::display();
	m_firstMenu->display();
}
   
Window * MenuBar::find(int x, int y) {
	// �� �޴����� isInside(x, y) �� ��� Ŭ���� ��ü�� �����͸� ��������.
	return m_firstMenu->isInside(x, y);
} 

                              