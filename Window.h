#pragma once
#include <string>
#include<iostream>
#include <list>
using namespace std;

class Frame;
class Window{
public:
	Window(); //Window�⺻������
	Window(int x, int y, int sx, int sy); //�Ű����� �ִ� ������
	virtual void onMouseClick(int x, int y) = 0; //���콺 Ŭ�� �����Լ�
	virtual void display(Frame *f)=0; //ȭ�鿡 ��Ÿ���ִ� �����Լ�
protected:
	int m_x, m_y, m_xsize, m_ysize; //���� x,y��ǥ�� �������
};
