#pragma once
#include<iostream>
#include "Window.h"
#include "Frame.h"
using namespace std;

class Canvas :public Window {
public:
	Canvas(Frame *f);//������
	virtual void onMouseClick(int x, int y);//Ŭ���� ��� ����� �κп� ���� �Լ�
	void display(Frame *f);//ȭ�鿡 ��Ÿ���ִ� �Լ�
};