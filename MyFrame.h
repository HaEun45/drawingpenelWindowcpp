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
	void processEvent(Window * src); //�޴������� Ŭ���� �����ϴ� �Լ�
private:
	Menu* menuFile, *menuEdit;
	MenuItem* miOpen, *miSave, *miExit, *miCopy, *miCut, *miPaste;
};