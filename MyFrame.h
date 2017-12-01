#pragma once
#include "Frame.h"
#include<iostream>
using namespace std;

class Menu;   
class MenuItem;
class MyFrame :public Frame {
public:
	MyFrame(HWND w);
	virtual void onInitialize(); //�ʱ�ȭ ���ִ� �Լ�
	void processEvent(Window * src); //�޴������� Ŭ���� �����ϴ� �Լ�
protected:
	//�ʿ��� ������ ������ ���� ����
	Menu *menuFigure, *menuColor, *menuEdit;
	MenuItem* miRectangle, *miEllipse, *miLine, *miBlack,*miRed, *miBlue;
	MenuItem* miMove; //������ �̵������� �޴������� �߰�

};