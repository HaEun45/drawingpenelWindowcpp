#pragma once
#include<iostream>
#include "Window.h"
#include "Frame.h"
using namespace std;

class Canvas :public Window {
public:
	Canvas();//������
	virtual void onMouseClick(int x, int y);//Ŭ���� ��� ����� �κп� ���� �Լ�
	virtual void display();//ȭ�鿡 ��Ÿ���ִ� �Լ�
};