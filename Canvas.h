#pragma once
#include<iostream>
#include "Window.h"
#include "Frame.h"
using namespace std;

class Canvas :public Window {
public:
	Canvas();//생성자
	virtual void onMouseClick(int x, int y);//클릭한 경우 출력할 부분에 대한 함수
	virtual void display();//화면에 나타내주는 함수
	virtual void onMouseClickUp(int x, int y);  //마우스를 떼는 순간 그림을 그린다.
protected:
	int clickUpX, clickUpY;  //클릭하는 경우 canvas의 좌표
	int clickDownX, clickDownY; //클릭하고 떼는 경우 canvas의 좌표
	bool canvasState;  //canvas에서 클릭이 되었는지 아닌지 상태를 나타내주는 변수
};