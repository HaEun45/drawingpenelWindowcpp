#include "stdafx.h"
#include "CLine.h"
#include "Frame.h"


//기	본 생성자
CLine::CLine() {}

//생성자
CLine::CLine(int x, int y, int UpX, int UpY)
	:Figure(x, y, UpX, UpY)
{
}


CLine::~CLine()
{
}

//그림을 그려주는 함수
void CLine::draw() {
	m_fframe->setPen(m_color, 1);
	m_fframe->line(m_clickDownX, m_clickDownY, m_clickUpX, m_clickUpY); //x,y는 클릭한 점
}

Figure* CLine::isInside(int x, int y) {
	//선분은 시작점이 바뀌어서는 안된다.
	if (m_clickUpX < 0 && m_clickUpY > 0) {  //클릭업된 점의 x좌표가 -라면
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
	else if (m_clickUpX < 0 & m_clickUpY < 0) { //클릭업된 점의 y좌표가 -라면
		if (m_clickDownX + m_clickUpX <= x && x < m_clickDownX && m_clickUpY + m_clickDownY <= y && y < m_clickDownY) {
			return this;
		}
	}
	if (m_clickDownX <= x && x < m_clickDownX + m_clickUpX  && m_clickDownY <= y &&  y < m_clickDownY + m_clickUpY) {
		return this;
	}
	else { //없으면 0을 반환한다.
		return 0;
	}

}