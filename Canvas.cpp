#include "stdafx.h" 
#include "Canvas.h"
#include "Frame.h"

//������
Canvas::Canvas():Window(XCOORDINATE, YCOORDINATE + YSIZE, XSIZE, YCANSIZE) {
	canvasState = false; //���º����� false�� �ʱ�ȭ���ش�.
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
	m_frame->setPen(RGB(100, 100, 100), 1);
	m_frame->rectangle(m_x, m_y, m_xsize, m_ysize);
	//m_frame->line(x, y - YSIZE,);
}

//���콺�� ���� ���� �׸��� �׸���.
void Canvas::onMouseClickUp(int x, int y) { //����x,y
	if (canvasState == true){ //ĵ������ Ŭ���� �� ��쿡�� �׸��� �׷��ش�.
		//���� ����� ��ǥ�� �����صд�.
		clickUpX = x;  
		clickUpY = y;  
		//����Ѵ�.
		OutputDebugString("Click Up.\n");
		OutputDebugString("Canvas: ");
		OutputDebugString(to_string(clickUpX).c_str());
		OutputDebugString(", ");
		OutputDebugString(to_string(clickUpY - YSIZE).c_str());
		OutputDebugString("\n");
		//������ �׷��ش�.
		m_frame->line(clickDownX, clickDownY, clickUpX - clickDownX, clickUpY - clickDownY); //x,y�� Ŭ���� ��
		canvasState = false;  //���������� Ŭ���� ���� ���� ���·� �ٲ��ش�.
		//�ٲ����� ������ Menu�� ���� �� ���� Canvas�� Ŭ���� ������ �����Ͽ� �׸��� �׷�����.
	}
	else {
		OutputDebugString(" Clicked up.\n");
	}
}
