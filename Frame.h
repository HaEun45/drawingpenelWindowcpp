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
	// 임시 변수
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
	void setPenColor(COLORREF color);         // 펜 색깔 설정. 두께는 1로 자동.
	void setPen(COLORREF color, int width);   // 펜 색깔과 두께까지 설정.
	void setFillColor(COLORREF color);
	void setTextColor(COLORREF color);

	void rectangle(int x, int y, int sizeX, int sizeY);
	void ellipse(int x, int y, int sizeX, int sizeY);
	void line(int x, int y, int sizeX, int sizeY);
	void drawText(std::string str, int x, int y);
	void display();
	void invalidate(); //화면을 엎고 다시 display를 한다.
	virtual void onInitialize(); //가상함수로 한다.
	virtual void processEvent(Window * src)=0; //가상함수로 만든다.
	void addMenuBar(MenuBar *mb); //메뉴바를 추가해 저장해주는 함수
	void addCanvas(Canvas *c);  //캔버스를 추가해 저장해주는 함수
	Window* find(int x, int y); 
	 
protected:
	MenuBar *m_menubar;     //menubar 포인터 변수 선언
	Canvas *m_canvas;      //canvas 포인터 변수 선언
};