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
	virtual void onMouseClickUp(int x, int y);  //���콺�� ���� ���� �׸��� �׸���.
protected:
	int clickUpX, clickUpY;  //Ŭ���ϴ� ��� canvas�� ��ǥ
	int clickDownX, clickDownY; //Ŭ���ϰ� ���� ��� canvas�� ��ǥ
	bool canvasState;  //canvas���� Ŭ���� �Ǿ����� �ƴ��� ���¸� ��Ÿ���ִ� ����
};