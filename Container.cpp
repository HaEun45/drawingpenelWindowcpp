#include <fstream>
#include "stdafx.h" 
#include "Container.h"
#include "Frame.h"

//기본생성자
Container::Container():Window() {
	windowList = new list<Window *>;

}
//생성자
Container::Container(int x, int y, int sx, int sy) :Window(x,y,sx,sy){

}

//생성자
Container::Container(string s, int x, int y, int sx, int sy)
	: Window(x, y, sx, sy)
{
	m_text = s;
}


void Container::onMouseClick(int x, int y) {

}


void Container::display() {
	//리스트로 만들어주는 부분
	list<Window *>::iterator i;
	for (i = windowList->begin(); i != windowList->end(); i++) {
		(*i)->display();
	}
}

void Container::onMouseClickUp(int x, int y) {

}