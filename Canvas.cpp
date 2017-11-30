#include "stdafx.h" 
#include "Canvas.h"
#include "Frame.h"
#include "CRectangle.h"
#include "CEllipse.h"
#include "CLine.h"
#include "Figure.h"


//������
Canvas::Canvas():Window(XCOORDINATE, YCOORDINATE + YSIZE, XSIZE, YCANSIZE) {
	canvasState = false; //���º����� false�� �ʱ�ȭ���ش�.
	m_color = RGB(0, 0, 0); //���������� �ʱ�ȭ
	m_flist = new list <Figure*>; //����Ʈ ����
	m_figureType = 0; 
}

//���콺�� Ŭ���� ��� �߻��ϴ� �ϵ鿡 ���� �Լ�
void Canvas::onMouseClick(int x, int y) {
	OutputDebugString("Canvas: ");
	OutputDebugString(to_string(x).c_str());
	OutputDebugString(", ");
	OutputDebugString(to_string(y - YSIZE).c_str());
	OutputDebugString("\n");
	//���⼭ Ŭ���� ��ǥ�� �����س���.
	clickDownX = x;
	clickDownY = y;
	canvasState = true; //Ŭ���̵Ǹ� ĵ������ ���¸� true��� �Ѵ�.
}


//ĵ������ �׷��ִ� �Լ�
void Canvas::display() {
	//m_frame->setPen(RGB(100, 100, 100), 1);
	//m_frame->rectangle(m_x, m_y, m_xsize, m_ysize);

	//������ ������ �׷��ش�.
	list<Figure*>::iterator i;
	for (i = m_flist->begin(); i != m_flist->end(); i++) {
		(*i)->draw();  //*i�� ���� ������ �����͸� �ǹ��Ѵ�.
	}
}

//������ Ÿ���� �˷��ִ� �Լ�
void Canvas::setFigureType(int num) {
	m_figureType = num;
}

//���콺�� ���� ���� �׸��� �׸���.
void Canvas::onMouseClickUp(int x, int y) { //����x,y
	if (canvasState == true){ //ĵ������ Ŭ���� �� ��쿡�� �׸��� �׷��ش�.
		//���� ����� ��ǥ�� �����صд�.
		//����Ѵ�.
		OutputDebugString("Click Up.\n");
		OutputDebugString("Canvas: ");
		OutputDebugString(to_string(x).c_str());
		OutputDebugString(", ");
		OutputDebugString(to_string(y - YSIZE).c_str());
		OutputDebugString("\n");
		
		//�簢��,Ÿ��,������ �׸���.
		Figure *m_figure;
		if(m_figureType == 0){
			m_figure = new CRectangle(clickDownX, clickDownY, x - clickDownX, y - clickDownY);
			//���� ������ ������  �簢��Ŭ���� �����Ѵ�.
			m_figure->registerColor(m_color);//ķ������ m_color�� Figure�� ������ش�.
		}
		else if (m_figureType == 1) {
			m_figure = new CEllipse(clickDownX, clickDownY, x - clickDownX, y - clickDownY);
			m_figure->registerColor(m_color);//ķ������ m_color�� Figure�� ������ش�.
		}
		else if (m_figureType == 2) {
			m_figure = new CLine(clickDownX, clickDownY, x - clickDownX, y - clickDownY);
			m_figure->registerColor(m_color);//ķ������ m_color�� Figure�� ������ش�.
		}
		

		m_flist->push_back(m_figure); //���� ������ �����͸� m_flist�� �־��ش�.
		m_figure->setFrame(m_frame); //������ frame�� �������ش�.
		
		m_frame->invalidate(); //ȭ���� ����� �ٽ� �׷��ش�.
		canvasState = false;  //���������� Ŭ���� ���� ���� ���·� �ٲ��ش�.
		//�ٲ����� ������ Menu�� ���� �� ���� Canvas�� Ŭ���� ������ �����Ͽ� �׸��� �׷�����.
	}
	else {
		OutputDebugString(" Clicked up.\n");
	}

	//������ Ŭ���ٿ��� �ǰ� 
	//��� �ٸ� ��ġ���� Ŭ������ �Ǵ� ����
	//�׸��� ���Ӱ� �׷����� �׷��ִ� �׸��� ��������.
}

//MyFrame���� ���޹��� ���� �����Ѵ�.
void Canvas::setColor(COLORREF color) {
	m_color = color;
}

//����Ʈ�� �����͸� �������ִ� ���
void Canvas::removeFigure(int x,int y) {
	list<Figure*>::reverse_iterator i;
	for (i = m_flist->rbegin(); i != m_flist->rend();i++) {
		if ((Figure*)(*i)->isInside(x,y)){//�������� ��(����)�� Ŭ���ϸ�
			m_flist->remove(*i); //����Ʈ�� �����͸� �����Ѵ�.
			break;
		}
	}
	//m_flist->erase(f); //����Ʈ�� �����͸� �����ϴ� ��� erase�� �����
}

//onMouseClickdown���� �ٷ� ȣ��Ǿ� ������ ã���ش�.
Figure* Canvas::find(int x, int y) {
	list<Figure *>::iterator i;
	for (i = m_flist->begin(); i != m_flist->end(); i++) {
		if (((Figure*)*i)->isInside(x, y)) {//�������� ��(����)�� Ŭ���ϸ�
			return (*i); //������ ��ȯ
		}
	}
	return 0;
}

/*
//������ �̵������ִ� �Լ�
void Canvas::moveFigure(int x, int y) { //Ŭ���� �� ���� ���´�.
	//2.�ƿ� �׸��� �ٲٴ¹��->ĵ������ ����Ǿ��ִ� ��������� �ٲ۴�.
	if (find(clickDownX, clickDownY)) { //ex)�簢�� ���� �� ���� Ŭ���ߴٸ� ũ Ŭ���� ������ �����Ͱ� �ִٸ�
		//���ѵ� ������ Ŭ���������� Ŭ������ �κп��� Ŭ������ ���� �̵��� ��ŭ �����ش�.
		find(clickDownX, clickDownY)
			->moveFigureXY(x- clickDownX, y-clickDownY);
	}
}*/




