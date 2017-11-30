#include "stdafx.h"
#include "CRectangle.h"
#include "Frame.h"

CRectangle::CRectangle() {}

CRectangle::CRectangle(int x, int y, int UpX, int UpY)
	:Figure(x, y, UpX, UpY)
{
}


CRectangle::~CRectangle()
{
}

void CRectangle::draw() {
	m_fframe->setPen(m_color, 1);
	m_fframe->rectangle(m_clickDownX, m_clickDownY, m_clickUpX, m_clickUpY); //x,y�� Ŭ���� ��
}


Figure* CRectangle::isInside(int x, int y) {
	if (m_clickUpX < 0 && m_clickUpY > 0) {  //Ŭ������ ���� x��ǥ�� -���
		m_clickUpX = abs(m_clickUpX); //������ �����ָ� isInside���� ó���� �ȴ�.
		m_clickDownX -= m_clickUpX;//Ŭ���ٿ� �� ������ �׸�ŭ �����̵� 
	}
	else if (m_clickUpX > 0 & m_clickUpY < 0) { //Ŭ������ ���� y��ǥ�� -���
		m_clickUpY = abs(m_clickUpY);
		m_clickDownY -= m_clickUpY; //Ŭ���ٿ� �� ������ �׸�ŭ �����̵� Ű���ְ�
	}
	else if (m_clickUpX < 0 && m_clickUpY < 0) {
		m_clickUpX = abs(m_clickUpX);
		m_clickUpY = abs(m_clickUpY);
		m_clickDownX -= m_clickUpX; //Ŭ���ٿ� �� ������ �׸�ŭ �����̵� Ű���ְ�
		m_clickDownY -= m_clickUpY; //Ŭ���ٿ� �� ������ �׸�ŭ �����̵� Ű���ְ�
	}
	if (m_clickDownX <= x && x < m_clickDownX + m_clickUpX  && m_clickDownY <= y &&  y < m_clickDownY + m_clickUpY) {
		return this;
	}
	else { //������ 0�� ��ȯ�Ѵ�.
		return 0;
	}


}