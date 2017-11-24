//#include <fstream>
#include "stdafx.h" 
#include "Menubar.h"
#include "Frame.h"


//������ 
MenuBar::MenuBar() : Container(xcoordinate, ycoordinate, xsize, ysize) {
	m_menux = 0; //0���� �ʱ�ȭ�Ѵ�.
	windowList = new list<Window *>; //WindowList�� interfaceȭ ��Ų��-������ ������ش�.
}

//menu����Լ�
void MenuBar::addMenu(Menu *m) {
	
	m->setContainer(this); //�޴������ۿ� �޴��� ����Ѵ�.
	m->setFrame(m_frame); //window�� �ִ� m_frame�� �����Ѵ�.
	m->setX(m_menux); //x�� ��ȭ���� �� �Լ��� ����Ų��.
	m_menux += xmenusize;
	windowList->push_back(m); // ���� ���(������)�� �߰��Ѵ�.
}

//������ ������ش�.  //1-2
void MenuBar::display() {

	m_frame->setPen(RGB(100, 100, 100), 1);
	m_frame->rectangle(m_x, m_y, m_xsize, m_ysize);
	drawContent();
	//�޴��� �׸��� �׷��ش�
	list<Window *>::iterator i;
	for (i = windowList->begin(); i != windowList->end(); i++) {
		((Menu*)*i)->display(); //Menu�� display
	}
}

//3
//�޴��� ã�´�. - �޴��� ã�Ƽ� ã�� �޴��� ��ȯ���ִ� ����
//find�� ������ ������������
//4-2
Window* MenuBar::find(int x, int y) {
	//ó������ ������ �ش� ����(�޴�)���� Ŭ���̵Ǿ����� Ȯ���Ѵ�.
	//�޴��������� ã�´�.
	list<Window *>::iterator i;
	for (i = windowList->begin(); i != windowList->end(); i++) {
		Window* temp = ((Menu *)*i)->find(x, y); //����ȯ�� �����־���Ѵ�.
		if (temp) { //����Ÿ���� ������ 
			return temp; //�޴� �Ǵ� �޴��������� ��ȯ�ȴ�
		}
		//return 0;
	}
	return 0;
}


//5-2
//���콺�� Ŭ������ �� �Ͼ�� �Ͽ� ���� �Լ�
void MenuBar::onMouseClick(int x, int y) {
	OutputDebugString("MenuBar Clicked. "); //���� ����Ѵ�.
	list<Window *>::iterator i;
	for (i = windowList->begin(); i != windowList->end(); i++) {
		Window *temp=((Menu*)*i)->isInside(x, y); //�޴��� ã�´� //find�� �ϸ� �ȵ�
		if(temp) { 
			temp->onMouseClick(x, y); //�޴��� �ִٸ� ��µȴ�.
			//�޴��� ����ϸ鼭 �̶� ���¸� true��� �Ѵ�.
		}
	}
	/*
	Window * tmp = find(x, y); //�ӽú��� temp�� �޴��� ã�Ƽ� �ִ´�
	if (tmp != 0) { //�޴��� �ִ� ��츸
		tmp->onMouseClick(x, y); //Ŭ���� ��� ������ ������ش�.
	}*/
}


//�޴��� ã�Ƽ� ��ȯ�ϰų� �޴��ٸ� ��ȯ���ִ� �Լ�-�ش�������� �ִ��� Ȯ��
Window* MenuBar::isInside(int x, int y) {
	//�޴��پȿ� �ִٸ�
	if (m_x <= x && x < m_x + m_xsize &&	m_y <= y && y < m_y + m_ysize) {
		return this;  //�޴��ٸ� ��ȯ�Ѵ�.
	}
	else {
		return 0;
	}
}


//���� �޴��� Ŭ���Ǹ� 
//Ŭ���� �޴��� �޴��������� Ŭ���Ǿ������Ѵ�.
//�ٸ� �޴��������� ������ �Ѵ�.

//�޴����� ������� ������.
//inside �Ѱ� �� �Ǵ� - ���������� ���� ��->�̿��Ѵ�.
//find ������ �� �Ǵ�- ������ ���� ��
void MenuBar::closeAllMenu() {  
	//�ϴ� ��� �޴��������� �ݾƾ��ϴϱ� �ݺ����Ѵ�.
	list<Window *>::iterator i; 
	for (i = windowList->begin(); i != windowList->end(); i++) {
		((Menu*)*i)->allMenuFalse(); //�οﺯ���� ��δ� false�� �ٲ۴�.
	}
}


//3-2
//�޴��Ѱ��� �޴��������� �����ֵ����Ѵ�.->������ �ϳ��� ���̿����Ѵ�.
Window* MenuBar::openOneMenu() {
	list<Window *>::iterator i;
	for (i = windowList->begin(); i != windowList->end(); i++) {
		Menu * m = ((Menu*)*i)->oneMenuTrue(); //�޴��� ��ȯ���ش�
		if (m) { //�޴��� ������ �޴��� ����Ѵ�.
			return m;
		}
	}
	return 0;
}
