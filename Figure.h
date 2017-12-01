#pragma once
#include <iostream>
using namespace std;

class Frame;
class Canvas;
class Figure
{
public:
	Figure();
	Figure(int x, int y, int UpX, int UpY);
	~Figure();
	virtual void draw();
	void registerColor(COLORREF color);
	void setFrame(Frame * f);
	virtual Figure* isInside(int x,int y); 
	void moveFigureXY(int x, int y); //좌표를 평행이동 시켜준다.
protected:
	int m_clickDownX, m_clickDownY, m_clickUpX, m_clickUpY;
	Frame *m_fframe; 
	COLORREF m_color;
};

