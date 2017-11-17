#pragma once
#include <string>
#include<iostream>
#include <list>
using namespace std;

class Frame;
class Window{
public:
	Window(); //Window기본생성자
	Window(int x, int y, int sx, int sy); //매개변수 있는 생성자
	virtual void onMouseClick(int x, int y) = 0; //마우스 클릭 가상함수
	virtual void display(Frame *f)=0; //화면에 나타내주는 가상함수
protected:
	int m_x, m_y, m_xsize, m_ysize; //각각 x,y좌표와 사이즈들
};
