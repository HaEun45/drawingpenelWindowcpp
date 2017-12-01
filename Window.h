#pragma once
#include <string>
#include<iostream>
#include <list>
using namespace std;
#define XCOORDINATE 0 
#define YCOORDINATE 0 
#define XSIZE 620 
#define YSIZE 30
#define XMENUSIZE 100
#define YCANSIZE 400

class Container;
class Frame;
class Window{
public:
	Window(); //Window�⺻������
	Window(int x, int y, int sx, int sy); //�Ű����� �ִ� ������
	virtual void onMouseClick(int x, int y) = 0; //���콺 Ŭ�� �����Լ�
	void drawContent(); //���빰�� �׷��ش�.
	void setContainer(Container *con); //�����̳ʿ� �����ϴ� �Լ�
	void setFrame(Frame *f); //�����ӿ� �������ִ� �Լ�
	virtual void onMouseClickUp(int x, int y);// ���츦 up�ϴ� ������ ��ǥ�� �����ִ� �Լ�
	virtual void display()=0; //ȭ�鿡 ��Ÿ���ִ� �����Լ�
protected:
	int m_x, m_y, m_xsize, m_ysize; //���� x,y��ǥ�� �������
	string m_text;
	Container *m_container; //�����̳��� �������
	Frame * m_frame; //�������� �������
	
};
