#include "stdafx.h" 
#include "Canvas.h"
#include "Frame.h"

//생성자
Canvas::Canvas():Window(XCOORDINATE, YCOORDINATE + YSIZE, XSIZE, YCANSIZE) {
	canvasState = false; //상태변수를 false로 초기화해준다.
}

//마우스를 클릭한 경우 발생하는 일들에 대한 함수
void Canvas::onMouseClick(int x, int y) {
	OutputDebugString("Canvas: ");
	OutputDebugString(to_string(x).c_str());
	OutputDebugString(", ");
	OutputDebugString(to_string(y - YSIZE).c_str());
	OutputDebugString("\n");
	//여기서 클릭한 좌표를 저장해놓자.
	clickDownX = x;
	clickDownY = y;
	canvasState = true; //클릭이되면 캔버스의 상태를 true라고 한다.
}

//캔버스를 그려주는 함수
void Canvas::display() {
	m_frame->setPen(RGB(100, 100, 100), 1);
	m_frame->rectangle(m_x, m_y, m_xsize, m_ysize);
	//m_frame->line(x, y - YSIZE,);
}

//마우스를 떼는 순간 그림을 그린다.
void Canvas::onMouseClickUp(int x, int y) { //종점x,y
	if (canvasState == true){ //캔버스가 클릭이 된 경우에만 그림을 그려준다.
		//떼는 경우의 좌표를 저장해둔다.
		clickUpX = x;  
		clickUpY = y;  
		//출력한다.
		OutputDebugString("Click Up.\n");
		OutputDebugString("Canvas: ");
		OutputDebugString(to_string(clickUpX).c_str());
		OutputDebugString(", ");
		OutputDebugString(to_string(clickUpY - YSIZE).c_str());
		OutputDebugString("\n");
		//직선을 그려준다.
		m_frame->line(clickDownX, clickDownY, clickUpX - clickDownX, clickUpY - clickDownY); //x,y는 클릭한 점
		canvasState = false;  //마지막에는 클릭이 되지 않은 상태로 바꿔준다.
		//바꿔주지 않으면 Menu를 누를 때 마다 Canvas를 클릭할 것으로 인지하여 그림이 그려진다.
	}
	else {
		OutputDebugString(" Clicked up.\n");
	}
}
