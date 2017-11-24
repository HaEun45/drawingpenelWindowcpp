//#include<fstream>
#include "stdafx.h" 
#include "Menubar.h"
#include "Menu.h"
#include "Frame.h"


//�޴�������
Menu::Menu(string s) : Container(s , 0, 0, xmenusize, ysize ) {
	m_text = s; //text�� s�� ����
	m_menuitemy = 0;
	windowList = new list<Window *>;
	//menuState = true;
	menuState = false;
}

//��ȭ�� x�� ���� �����ϴ� �Լ�
void Menu::setX(int menux) {
	m_x = menux; //�ٲ� menux�� m_x�� �����Ѵ�(�ʱ�ȭ)
}


//�޴������� ����Լ�
void Menu::addMenuItem(MenuItem * mi) {
	mi->setFrame(m_frame);
	m_menuitemy += ysize;
	mi->setXY(m_x, m_menuitemy); //�ڽ��� m_x��  �޴������ۿ��� �ش�.
	windowList->push_back(mi); //�޴��������� �־��ش�

}



//�޴��� �������� true�� �ٲ�� �ٸ�â�� ��false
//�޴��� �������� ������ �� false

//1-3
//ȭ�鿡 Menu�� ����� �� �Լ� //Menubar�� display���� Menu�� display�� ȣ�����ش�.
void Menu::display() {
	m_frame->setPen(RGB(100, 100, 100), 1);
	m_frame->rectangle(m_x, m_y, m_xsize, m_ysize);
	drawContent();

}

//4-3
Window* Menu::find(int x, int y) {
	list<Window *>::iterator i;
	for (i = windowList->begin(); i != windowList->end(); i++) {
		Window * tmp = ((MenuItem*)*i)->isInside(x, y);
		if (tmp) {
			return tmp; //�޴��� �޴������� �Ѵ� ������ �޴������� ��ȯ
		}
	}
	return 0;
}

//5-3
//�޴��� Ŭ���� ��� ����ϴ� �κ�
void Menu::onMouseClick(int x, int y) {
	OutputDebugString(m_text.c_str()); // �޴����� ������ ����Ѵ�.
	OutputDebugString(" Clicked.\n");	
	menuState = true; // �޴��� ���콺�� �������� �޴��� ���º����� true�̴�.
	//���¸� true�� ����鼭 
}

//4-4
//�޴��� ã���ִ� �Լ�
Window* Menu::isInside(int x, int y) {
	if (m_x <= x && x < m_x + m_xsize && m_y <= y && y < m_y + m_ysize) {//���� ���̶��
		return this;  //�޴��� ��ȯ
	}
	else { //������ 0�� ��ȯ�Ѵ�.
		return 0;
	}
}
//---------------------------------------------------�޴��������� ȣ���ϱ����� �Լ�
//1-4
//�޴��������� ���÷��̸� ȣ���ϴ� �Լ�
void Menu::callMenuitemDisplay() {
	list<Window *>::iterator i;
	for (i = windowList->begin(); i != windowList->end(); i++) {
		//f->invalidate();
		((MenuItem*)*i)->display();
	}
}

//��� false�� �ǵ��ϸ����
void Menu::allMenuFalse() { //6-3
	menuState = false; //���콺�� �޴��� Ŭ���ؼ� ture���� ���¸� ��� false�� �ٲ۴�.
}

//3-3
//�޴������� ���°� ��, �� ���õǸ� �޴������۵��� ��ȯ���ش�.
Menu * Menu::oneMenuTrue() {
	if (menuState == true) {
		return this;
	}
	else {
		return 0;
	}
}
