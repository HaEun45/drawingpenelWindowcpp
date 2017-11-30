#include "stdafx.h" 
#include "Canvas.h"
#include "Frame.h"
#include "CRectangle.h"
#include "CEllipse.h"
#include "CLine.h"
#include "Figure.h"


//생성자
Canvas::Canvas():Window(XCOORDINATE, YCOORDINATE + YSIZE, XSIZE, YCANSIZE) {
	canvasState = false; //상태변수를 false로 초기화해준다.
	m_color = RGB(0, 0, 0); //검정색으로 초기화
	m_flist = new list <Figure*>; //리스트 생성
	m_figureType = 0; 
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
	//m_frame->setPen(RGB(100, 100, 100), 1);
	//m_frame->rectangle(m_x, m_y, m_xsize, m_ysize);

	//각각의 도형을 그려준다.
	list<Figure*>::iterator i;
	for (i = m_flist->begin(); i != m_flist->end(); i++) {
		(*i)->draw();  //*i는 각각 도형의 포인터를 의미한다.
	}
}

//도형의 타입을 알려주는 함수
void Canvas::setFigureType(int num) {
	m_figureType = num;
}

//마우스를 떼는 순간 그림을 그린다.
void Canvas::onMouseClickUp(int x, int y) { //종점x,y
	if (canvasState == true){ //캔버스가 클릭이 된 경우에만 그림을 그려준다.
		//떼는 경우의 좌표를 저장해둔다.
		//출력한다.
		OutputDebugString("Click Up.\n");
		OutputDebugString("Canvas: ");
		OutputDebugString(to_string(x).c_str());
		OutputDebugString(", ");
		OutputDebugString(to_string(y - YSIZE).c_str());
		OutputDebugString("\n");
		
		//사각형,타원,선분을 그린다.
		Figure *m_figure;
		if(m_figureType == 0){
			m_figure = new CRectangle(clickDownX, clickDownY, x - clickDownX, y - clickDownY);
			//도형 포인터 변수를  사각형클래로 생성한다.
			m_figure->registerColor(m_color);//캠버스의 m_color를 Figure에 등록해준다.
		}
		else if (m_figureType == 1) {
			m_figure = new CEllipse(clickDownX, clickDownY, x - clickDownX, y - clickDownY);
			m_figure->registerColor(m_color);//캠버스의 m_color를 Figure에 등록해준다.
		}
		else if (m_figureType == 2) {
			m_figure = new CLine(clickDownX, clickDownY, x - clickDownX, y - clickDownY);
			m_figure->registerColor(m_color);//캠버스의 m_color를 Figure에 등록해준다.
		}
		

		m_flist->push_back(m_figure); //각각 도형의 포인터를 m_flist에 넣어준다.
		m_figure->setFrame(m_frame); //도형에 frame을 설정해준다.
		
		m_frame->invalidate(); //화면을 지우고 다시 그려준다.
		canvasState = false;  //마지막에는 클릭이 되지 않은 상태로 바꿔준다.
		//바꿔주지 않으면 Menu를 누를 때 마다 Canvas를 클릭할 것으로 인지하여 그림이 그려진다.
	}
	else {
		OutputDebugString(" Clicked up.\n");
	}

	//도형이 클릭다운이 되고 
	//끌어서 다른 위치에서 클릭업이 되는 순간
	//그림이 새롭게 그려지고 그려있던 그림은 지워진다.
}

//MyFrame에서 전달받은 색을 저장한다.
void Canvas::setColor(COLORREF color) {
	m_color = color;
}

//리스트의 포인터를 제거해주는 경우
void Canvas::removeFigure(int x,int y) {
	list<Figure*>::reverse_iterator i;
	for (i = m_flist->rbegin(); i != m_flist->rend();i++) {
		if ((Figure*)(*i)->isInside(x,y)){//도형내부 안(범위)을 클릭하면
			m_flist->remove(*i); //리스트의 포인터를 삭제한다.
			break;
		}
	}
	//m_flist->erase(f); //리스트의 포인터를 삭제하는 경우 erase를 사용함
}

//onMouseClickdown에서 바로 호출되어 도형을 찾아준다.
Figure* Canvas::find(int x, int y) {
	list<Figure *>::iterator i;
	for (i = m_flist->begin(); i != m_flist->end(); i++) {
		if (((Figure*)*i)->isInside(x, y)) {//도형내부 안(범위)을 클릭하면
			return (*i); //도형을 반환
		}
	}
	return 0;
}

/*
//도형을 이동시켜주는 함수
void Canvas::moveFigure(int x, int y) { //클릭업 된 점이 들어온다.
	//2.아예 그림을 바꾸는방법->캔버스에 저장되어있는 멤버변수를 바꾼다.
	if (find(clickDownX, clickDownY)) { //ex)사각형 내부 한 점을 클릭했다면 크 클릭된 도형의 포인터가 있다면
		//반한된 도형의 클릭된점에서 클릭업된 부분에서 클릭업된 점에 이동한 만큼 더해준다.
		find(clickDownX, clickDownY)
			->moveFigureXY(x- clickDownX, y-clickDownY);
	}
}*/




