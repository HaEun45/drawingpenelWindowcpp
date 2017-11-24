#pragma once
#include <string>
#include<iostream>
#include <list>
using namespace std;
#define xcoordinate 0 
#define ycoordinate 0 
#define xsize 620 //더할 만큼 을 200으로 정의해 둔다.
#define ysize 30
#define xmenusize 100
#define ycansize 400

class Container;
class Frame;
class Window{
public:
	Window(); //Window기본생성자
	Window(int x, int y, int sx, int sy); //매개변수 있는 생성자
	virtual void onMouseClick(int x, int y) = 0; //마우스 클릭 가상함수
	virtual void display()=0; //화면에 나타내주는 가상함수
	void drawContent(); //내용물을 그려준다.
	void setContainer(Container *con); //컨테이너에 저장하는 함수
	void setFrame(Frame *f); //프레임에 저장해주는 함수
	//virtual Window* find(int x, int y)=0;
protected:
	int m_x, m_y, m_xsize, m_ysize; //각각 x,y좌표와 사이즈들
	string m_text;
	Container *m_container; //컨테이너의 멤버변수
	Frame * m_frame; //프레임의 멤버변수
	
};
