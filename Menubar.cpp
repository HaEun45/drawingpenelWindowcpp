//#include <fstream>
#include "stdafx.h" 
#include "Menubar.h"
#include "Frame.h"


//������ 
MenuBar::MenuBar() : Container(xcoordinate, ycoordinate, xsize, ysize) {
	m_menux = 0; //0���� �ʱ�ȭ�Ѵ�.
}

//���콺�� Ŭ������ �� �Ͼ�� �Ͽ� ���� �Լ�
void MenuBar::onMouseClick(int x, int y) {
	OutputDebugString("MenuBar Clicked. "); //���� ����Ѵ�.
	Window * tmp = find(x, y); //�ӽú��� temp�� �޴��� ã�Ƽ� �ִ´�
	if (tmp != 0) { //�޴��� �ִ� ��츸
		tmp->onMouseClick(x, y); //Ŭ���� ��� ������ ������ش�.
	}
}

//menu����Լ�
void MenuBar::add(Menu *m) {
	m->setX(m_menux); //x�� ��ȭ���� �� �Լ��� ����Ų��.
	m_menux += xmenusize;
	m->setNext(m_firstMenu);  //����
	m_firstMenu = m; //������ ����
	
}

//������ ������ش�.
void MenuBar::display(Frame *f) {
	
	f->setPen(RGB(100, 100, 100), 1);
	f->rectangle(m_x, m_y, m_xsize, m_ysize);
	drawContent(f);

	m_firstMenu->display(f);//�޴��ٸ� ����� �� �޴��� ������ش�.
}
//�޴��� ã�´�.   
Window * MenuBar::find(int x, int y) {
	// �� �޴����� isInside(x, y) �� ��� Ŭ���� ��ü�� �����͸� ��������.
	return m_firstMenu->isInside(x, y);
} 
//�޴��� ã�ų� �޴��ٸ� ã�Ƽ� ��ȯ���ִ� �Լ�
Window* MenuBar::isInside(int x, int y) {
	//�޴��پȿ� �ִٸ�
	if (m_x <= x && x < m_x + m_xsize &&	m_y <= y && y < m_y + m_ysize) {
		Window * temp = find(x, y); //�ӽú��� temp�� �޴��� ã�� �Լ��� �־����
		if (temp) { //�޴��� ������
			return temp; //�� �޴��� ��ȯ�ϰ�
		}
		else {  //�޴��� ������ 
			return this;  //�޴��ٸ� ��ȯ�Ѵ�.
		}
	}
	else {
		return 0;
	}
}