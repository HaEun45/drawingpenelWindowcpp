#pragma once
#include<iostream>
#include "Window.h"
#include <list>
using namespace std;

class Figure;
class Canvas :public Window {
public:
	Canvas();//������
	virtual void onMouseClick(int x, int y);//Ŭ���� ��� ����� �κп� ���� �Լ�
	virtual void display();//ȭ�鿡 ��Ÿ���ִ� �Լ�
	void setFigureType(int num);
	void setColor(COLORREF color);
	virtual void onMouseClickUp(int x, int y);  //���콺�� ���� ���� �׸��� �׸���.
	void removeFigure(int x, int y);
	Figure* find(int x, int y);
	void moveFigure(int x, int y);
protected:
	int clickDownX, clickDownY; //Ŭ���ϰ� ���� ��� canvas�� ��ǥ
	bool canvasState;  //canvas���� Ŭ���� �Ǿ����� �ƴ��� ���¸� ��Ÿ���ִ� ����
	list <Figure*> *m_flist; //ĵ������ �ش� �������� ��ü�� �������� list����
	int m_figureType; //������ Ÿ���� �˷��ִ� ����
	int m_colorType; //������ Ÿ���� �˷��ִ� ����
	COLORREF m_color;
};