#pragma once
#include <string>
#include<iostream>
#include <list>
using namespace std;
#define xcoordinate 0 
#define ycoordinate 0 
#define xsize 620 //���� ��ŭ �� 200���� ������ �д�.
#define ysize 30
#define xmenusize 100
#define ycansize 400

class Container;
class Frame;
class Window{
public:
	Window(); //Window�⺻������
	Window(int x, int y, int sx, int sy); //�Ű����� �ִ� ������
	virtual void onMouseClick(int x, int y) = 0; //���콺 Ŭ�� �����Լ�
	virtual void display()=0; //ȭ�鿡 ��Ÿ���ִ� �����Լ�
	void drawContent();
	void setContainer(Container *con);
	void setFrame(Frame *f);
	//virtual Window* find(int x, int y)=0;
	//Window* isInside(int x, int y);
protected:
	int m_x, m_y, m_xsize, m_ysize; //���� x,y��ǥ�� �������
	string m_text;
	Container *m_container;
	Frame * m_frame;
	
};
