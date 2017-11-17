#pragma once
#include<iostream>
#include "Window.h"
#include "Frame.h"
using namespace std;

class Canvas :public Window {
public:
	Canvas(Frame *f);//생성자
	virtual void onMouseClick(int x, int y);//클릭한 경우 출력할 부분에 대한 함수
	void display(Frame *f);//화면에 나타내주는 함수
};