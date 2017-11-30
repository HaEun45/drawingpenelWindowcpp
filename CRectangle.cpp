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
	m_fframe->rectangle(m_clickDownX, m_clickDownY, m_clickUpX, m_clickUpY); //x,y는 클릭한 점
}


Figure* CRectangle::isInside(int x, int y) {
	if (m_clickUpX < 0 && m_clickUpY > 0) {  //클릭업된 점의 x좌표가 -라면
		m_clickUpX = abs(m_clickUpX); //절댓값을 취해주면 isInside에서 처리가 된다.
		m_clickDownX -= m_clickUpX;//클릭다운 됨 점에서 그만큼 평행이동 
	}
	else if (m_clickUpX > 0 & m_clickUpY < 0) { //클릭업된 점의 y좌표가 -라면
		m_clickUpY = abs(m_clickUpY);
		m_clickDownY -= m_clickUpY; //클릭다운 됨 점에서 그만큼 평행이동 키겨주고
	}
	else if (m_clickUpX < 0 && m_clickUpY < 0) {
		m_clickUpX = abs(m_clickUpX);
		m_clickUpY = abs(m_clickUpY);
		m_clickDownX -= m_clickUpX; //클릭다운 됨 점에서 그만큼 평행이동 키겨주고
		m_clickDownY -= m_clickUpY; //클릭다운 됨 점에서 그만큼 평행이동 키겨주고
	}
	if (m_clickDownX <= x && x < m_clickDownX + m_clickUpX  && m_clickDownY <= y &&  y < m_clickDownY + m_clickUpY) {
		return this;
	}
	else { //없으면 0을 반환한다.
		return 0;
	}


}