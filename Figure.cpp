#include "stdafx.h"
#include "Figure.h"
#include "Frame.h"
#include "stdlib.h"


//�⺻ ������
Figure::Figure() {}

//������
Figure::Figure(int x, int y, int UpX, int UpY)
	:m_clickDownX(x), m_clickDownY(y), m_clickUpX(UpX), m_clickUpY(UpY)
{
	m_color = RGB(0, 0, 0); //������ ���������� �ʱ�ȭ
}


Figure::~Figure()
{
}

//�׸��� �׷��ִ� �Լ�
void Figure::draw() {
	m_fframe->setPen(m_color, 1);
	m_fframe->rectangle(m_clickDownX, m_clickDownY, m_clickUpX, m_clickUpY); //x,y�� Ŭ���� ��
}

//Canvas���� �޾ƿ� ������ ������ ���(����)���ش�.
void Figure::registerColor(COLORREF color) {
	m_color = color;
}

//�������� �����صд�.
void Figure::setFrame(Frame * f) {
	m_fframe = f;
}

//������ �������� �ִ��� ������ �˷��ִ� �Լ�
Figure* Figure::isInside(int x,int y) {

	if (m_clickDownX <= x && x < m_clickDownX + m_clickUpX  && m_clickDownY <= y &&  y < m_clickDownY + m_clickUpY) {
		return this;
	}
	else { //������ 0�� ��ȯ�Ѵ�.
		return 0;
	}

}
/*
//Ŭ�� down,up�� x,y�� �ٲ��. //�����̵���Ų��.
void Figure::moveFigureXY(int x, int y) {
	m_clickDownX += x;
	m_clickDownY += y;
}*/

