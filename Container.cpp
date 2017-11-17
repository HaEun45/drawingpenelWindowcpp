#include <fstream>
#include "stdafx.h" 
#include "Container.h"
#include "Frame.h"


Container::Container():Window() {
	stuff = new list<Window *>;

}

Container::Container(int x, int y, int sx, int sy) :Window(x,y,sx,sy){
	//m_x(x), m_y(y), m_xsize(sx), m_ysize(sy), m_text("") 
}

Container::Container(string s, int x, int y, int sx, int sy)
	: Window(x, y, sx, sy)
{
	m_text = s;
}


void Container::drawContent(Frame *f) {
	f->drawText(m_text, m_x + 5, m_y + 5);
}

void Container::onMouseClick(int x, int y) {

}



void Container::add(Window *w) {
	stuff->push_back(w);
}

void Container::display(Frame *f) {
}