#pragma once
#include "Frame.h"
#include<iostream>
using namespace std;

class Menu;   
class MenuItem;
class MyFrame :public Frame {
public:
	MyFrame(HWND w);
	virtual void onInitialize(); //초기화 해주는 함수
	void processEvent(Window * src); //메뉴아이템 클릭에 반응하는 함수
private:
	//필요한 각각의 포인터 변수 선언
	Menu* menuFigure, *menuColor;
	MenuItem* miRectangle, *miEllipse, *miLine, *miBlack, *miRed, *miBlue;

};