#pragma once
#include<iostream>
#include <list>
#include "Window.h"
using namespace std;

class Frame;
class Container :public Window {
public:
	Container();
	Container(int x, int y, int sx, int sy);
	Container(string s, int x, int y, int sx, int sy);
	virtual void onMouseClick(int x, int y); ///���콺 Ŭ�� down
	virtual void onMouseClickUp(int x, int y);//���콺 Ŭ�� Up
	//void add(Window *w);  
	virtual void display(); 
protected:
	list<Window *> * windowList; //������ ����Ʈ
};
