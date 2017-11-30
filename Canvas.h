#pragma once
#include<iostream>
#include "Window.h"
#include <list>
using namespace std;

class Figure;
class Canvas :public Window {
public:
	Canvas();//생성자
	virtual void onMouseClick(int x, int y);//클릭한 경우 출력할 부분에 대한 함수
	virtual void display();//화면에 나타내주는 함수
	virtual void onMouseClickUp(int x, int y);  //마우스를 떼는 순간 그림을 그린다.
	void setFigureType(int num);
	void setColor(COLORREF color);
	//void moveFigure(int x, int y);
	void removeFigure(int x, int y);
	Figure* find(int x, int y);
protected:
	//int clickUpX, clickUpY;  //클릭하는 경우 canvas의 좌표
	int clickDownX, clickDownY; //클릭하고 떼는 경우 canvas의 좌표
	bool canvasState;  //canvas에서 클릭이 되었는지 아닌지 상태를 나타내주는 변수
	list <Figure*> *m_flist; //캔버스가 해당 도형들의 객체를 갖고있을 list선언
	int m_figureType; //도형의 타입을 알려주는 변수
	int m_colorType; //색깔의 타입을 알려주는 변수
	COLORREF m_color;
};