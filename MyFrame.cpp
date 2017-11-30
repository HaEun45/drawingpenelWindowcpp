#include "stdafx.h" 
#include "MyFrame.h"
#include "MenuBar.h"
#include "Canvas.h"
#include "Menu.h"
#include "MenuItem.h"


//������
MyFrame::MyFrame(HWND w):Frame(w){}


void MyFrame::onInitialize(){

	// *** ��� �������� ���⿡�� �ʱ�ȭ����.
	addMenuBar(new MenuBar());
	addCanvas(new Canvas());

	// menuFile ����� ��� ������ �ߴ�. ���߿�  event source�� �ľ��ؾ��ϴϱ�.
	m_menubar->addMenu(menuFigure = new Menu("����"));
	m_menubar->addMenu(menuColor = new Menu("��"));

	menuFigure->addMenuItem(miRectangle = new MenuItem("�簢��"));
	menuFigure->addMenuItem(miEllipse = new MenuItem("Ÿ��"));
	menuFigure->addMenuItem(miLine = new MenuItem("����"));

	menuColor->addMenuItem(miBlack = new MenuItem("������"));
	menuColor->addMenuItem(miRed = new MenuItem("������"));
	menuColor->addMenuItem(miBlue = new MenuItem("�Ķ���"));

}
//�޴� �������� �ڽ��� �ּҸ� �������־�� MyFrame�� ���� �ൿ�� �� �� ������ �� �ִ�.
//�޴��������� Ŭ������ �� ��µǴ� �Լ�
//���� �޴��������� �����Ϳ� ���Ѵ�.
void MyFrame::processEvent(Window * src) {
	if (src == miRectangle) {
		OutputDebugString("�޴������� �簢���� Ŭ��");
		m_canvas->setFigureType(0); //type�� �˷��ش�.
	}
	else if (src == miEllipse) {
		OutputDebugString("�޴������� Ÿ������ Ŭ��");
		m_canvas->setFigureType(1);
	}
	else if (src == miLine) {
		OutputDebugString("�޴������� ������ Ŭ��");
		m_canvas->setFigureType(2);
	}
	else if (src == miBlack) {
		OutputDebugString("�޴������� �������� Ŭ��");
		m_canvas->setColor(RGB(0, 0, 0)); //�÷��� �����Ѵ�.
	}
	else if (src == miRed) {
		OutputDebugString("�޴������� �������� Ŭ��");
		m_canvas->setColor(RGB(255, 0, 0));
	}
	else if (src == miBlue) {
		OutputDebugString("�޴������� �Ķ����� Ŭ��");
		m_canvas->setColor(RGB(0, 0, 255));
	}
}
