#pragma once
#include "Container.h"
#include <iostream>
#include <list>
using namespace std;

class MenuBar;
class Canvas;
class Frame :public Container{
public:
	Frame(HWND);
	~Frame();
protected:
	HWND myWnd;
	HDC hDC;
	HBRUSH brushWhite, brushBlack;
	HPEN penWhite, penBlack;
	// �ӽ� ����
	int count = 0;
	HPEN thePen;
	HBRUSH theBrush;
public:
	virtual void setWnd(HWND hWnd);
	virtual void OnLButtonDown(long wParam, int x, int y);
	virtual void OnLButtonUp(long wParam, int x, int y);
	virtual void OnRButtonDown(long wParam, int x, int y);
	virtual void OnRButtonUp(long wParam, int x, int y);
	virtual void OnChar(long ch);
	void setPenColor(COLORREF color);         // �� ���� ����. �β��� 1�� �ڵ�.
	void setPen(COLORREF color, int width);   // �� ����� �β����� ����.
	void setFillColor(COLORREF color);
	void setTextColor(COLORREF color);

	void rectangle(int x, int y, int sizeX, int sizeY);
	void ellipse(int x, int y, int sizeX, int sizeY);
	void line(int x, int y, int sizeX, int sizeY);
	void drawText(std::string str, int x, int y);
	void display();
	void invalidate(); //ȭ���� ���� �ٽ� display�� �Ѵ�.
	virtual void onInitialize(); //�����Լ��� �Ѵ�.
	virtual void processEvent(Window * src)=0; //�����Լ��� �����.
	void addMenuBar(MenuBar *mb); //�޴��ٸ� �߰��� �������ִ� �Լ�
	void addCanvas(Canvas *c);  //ĵ������ �߰��� �������ִ� �Լ�
	Window* find(int x, int y); 
	 
protected:
	MenuBar *m_menubar;     //menubar ������ ���� ����
	Canvas *m_canvas;      //canvas ������ ���� ����
};