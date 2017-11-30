#include "stdafx.h"
#include "CLine.h"
#include "Frame.h"


//��	�� ������
CLine::CLine() {}

//������
CLine::CLine(int x, int y, int UpX, int UpY)
	:Figure(x, y, UpX, UpY)
{
}


CLine::~CLine()
{
}

//�׸��� �׷��ִ� �Լ�
void CLine::draw() {
	m_fframe->setPen(m_color, 1);
	m_fframe->line(m_clickDownX, m_clickDownY, m_clickUpX, m_clickUpY); //x,y�� Ŭ���� ��
}

Figure* CLine::isInside(int x, int y) {
	//������ �������� �ٲ��� �ȵȴ�.
	if (m_clickUpX < 0 && m_clickUpY > 0) {  //Ŭ������ ���� x��ǥ�� -���
		if (m_clickDownX + m_clickUpX <= x && x < m_clickDownX  && m_clickDownY <= y &&  y < m_clickDownY + m_clickUpY) {
			return this;
		}
	}
	else if (m_clickUpX > 0 & m_clickUpY < 0) {
		if (m_clickDownX <= x && x < m_clickDownX + m_clickUpX  && m_clickUpY + m_clickDownY <= y && y < m_clickDownY) {
			return this;
		}
	}
	//m_startX <= x && x < m_startX + m_width && m_startY + m_height <= y
	else if (m_clickUpX < 0 & m_clickUpY < 0) { //Ŭ������ ���� y��ǥ�� -���
		if (m_clickDownX + m_clickUpX <= x && x < m_clickDownX && m_clickUpY + m_clickDownY <= y && y < m_clickDownY) {
			return this;
		}
	}
	if (m_clickDownX <= x && x < m_clickDownX + m_clickUpX  && m_clickDownY <= y &&  y < m_clickDownY + m_clickUpY) {
		return this;
	}
	else { //������ 0�� ��ȯ�Ѵ�.
		return 0;
	}

}