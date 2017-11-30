#include "stdafx.h"
#include "Figure.h"
#include "Frame.h"
#include "stdlib.h"


//기본 생성자
Figure::Figure() {}

//생성자
Figure::Figure(int x, int y, int UpX, int UpY)
	:m_clickDownX(x), m_clickDownY(y), m_clickUpX(UpX), m_clickUpY(UpY)
{
	m_color = RGB(0, 0, 0); //색깔을 검정색으로 초기화
}


Figure::~Figure()
{
}

//그림을 그려주는 함수
void Figure::draw() {
	m_fframe->setPen(m_color, 1);
	m_fframe->rectangle(m_clickDownX, m_clickDownY, m_clickUpX, m_clickUpY); //x,y는 클릭한 점
}

//Canvas에서 받아온 색깔을 도형에 등록(저장)해준다.
void Figure::registerColor(COLORREF color) {
	m_color = color;
}

//프레임을 저장해둔다.
void Figure::setFrame(Frame * f) {
	m_fframe = f;
}

//도형이 범위내에 있는지 없는지 알려주는 함수
Figure* Figure::isInside(int x,int y) {

	if (m_clickDownX <= x && x < m_clickDownX + m_clickUpX  && m_clickDownY <= y &&  y < m_clickDownY + m_clickUpY) {
		return this;
	}
	else { //없으면 0을 반환한다.
		return 0;
	}

}
/*
//클릭 down,up한 x,y가 바뀐다. //평행이동시킨다.
void Figure::moveFigureXY(int x, int y) {
	m_clickDownX += x;
	m_clickDownY += y;
}*/

