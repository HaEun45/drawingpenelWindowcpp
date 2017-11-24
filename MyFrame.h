#pragma once
#include "Frame.h"
#include<iostream>
using namespace std;

class Menu;   
class MenuItem;
class MyFrame :public Frame {
public:
	MyFrame(HWND w);
	virtual void onInitialize();
	void processEvent(Window * src); //메뉴아이템 클릭에 반응하는 함수
private:
	Menu* menuFile, *menuEdit;
	MenuItem* miOpen, *miSave, *miExit, *miCopy, *miCut, *miPaste;
};