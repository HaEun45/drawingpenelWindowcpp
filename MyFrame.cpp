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
	m_menubar->addMenu(menuFile = new Menu("����"));
	m_menubar->addMenu(menuEdit = new Menu("����"));

	menuFile->addMenuItem(miOpen = new MenuItem("����"));
	menuFile->addMenuItem(miSave = new MenuItem("����"));
	menuFile->addMenuItem(miExit = new MenuItem("������"));

	menuEdit->addMenuItem(miCopy = new MenuItem("����"));
	menuEdit->addMenuItem(miCut = new MenuItem("�ڸ���"));
	menuEdit->addMenuItem(miPaste = new MenuItem("���̱�"));

	
}
//�޴� �������� �ڽ��� �ּҸ� �������־�� MyFrame�� ���� �ൿ�� �� �� ������ �� �ִ�.
//�޴��������� Ŭ������ �� ��µǴ� �Լ�
//���� �޴��������� �����Ϳ� ���Ѵ�.
void MyFrame::processEvent(Window * src) {
	if (src == miOpen) {
		OutputDebugString("�޴������� ���⸦ Ŭ��");
	}
	else if (src == miSave) {
		OutputDebugString("�޴������� ������ Ŭ��");
	}
	else if (src == miExit) {
		OutputDebugString("�޴������� �����⸦ Ŭ��");
	}
	else if (src == miCopy) {
		OutputDebugString("�޴������� ���縦 Ŭ��");
	}
	else if (src == miCut) {
		OutputDebugString("�޴������� ����⸦ Ŭ��");
	}
	else if (src == miPaste) {
		OutputDebugString("�޴������� �ٿ��ֱ⸦ Ŭ��");
	}
}