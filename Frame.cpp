#include "stdafx.h"
#include "string"
#include "stdio.h"
#include "Frame.h"
#include "Canvas.h"
#include "Menubar.h"

Frame::Frame(HWND w):myWnd(w)
{
	hDC = ::GetDC(w);

	onInitialize();
	windowList = new list<Window *>;

}

void Frame::setWnd(HWND hWnd) {

}

Frame::~Frame()
{
	 // *** 모든 윈도을 delete합니다.
	//for (int i = 0; i < numWidget; i++) {
		//delete Windows[i];
	//}
}

void Frame::OnLButtonDown(long wParam, int x, int y)
{
	OutputDebugString("Click \n");
	// 윈도을 찾아서 윈도의 onMouseClick을 실행
	Window *w = find(x, y);  //4-1  //여기 find(x,y)는 Frame의 것
	if (w) { //만약 메뉴바나 메뉴나 캔버스라면 
		m_menubar->closeAllMenu();  //6-1 //메뉴아이템이 클릭된 후 모든 메뉴아이템을 닫아준다.
		//메뉴아이템은 true일때만 클릭된다. 그럼 받은 w(메뉴아이템)이 true인 메뉴아이템이어야 한다.
		w->onMouseClick(x, y); //5-1 //메뉴의 onMouseClick에서 선택된 메뉴의 상태를 true로 만든다.
		
		/*Window * temp = m_menubar->openOneMenu();
		if (temp) {
			((Menu*)temp)->callMenuitemDisplay(this);
		}*/
		// find에서 찾은 반환값이 0이 아니면 항상 메뉴의 부울 변수를 false로 만든다.
		//메뉴아이템이 닫힌다.
	}
	invalidate(); //모든 창을 지우고 다시 만들어 준다.
	/* 
	control key나 shift key등에 따라 다르게 하려면
	if (wParam & MK_CONTROL)  .. MK_SHIFT 등

	*/
	// 위 코드는 테스트용이고, Frame 객체의 OnLButtonDown 함수를 호출해
}


void Frame::OnLButtonUp(long wParam, int x, int y)
{
	Window *w = find(x, y); //윈도우를 찾아서 
	if (!w) {  //만약 윈도우가 없으면 
		OutputDebugString("Click "); //Click을 출력한다.
	}
	/*
	 * 아래는 선 색깔, 채움 색깔을 결정하는 방법을 알려줍니다.
	setPenColor(RGB(255, 0, 0));
	setFillColor(RGB(255, 255, 0));
	rectangle(x, y, 100, 200);
	*/
}
void Frame::OnRButtonDown(long wParam, int x, int y)
{
	// 프로그램 종료 방법을 데모하기 위해 우측 버튼 클릭시 아래 줄을 호출하게 만들었습니다.
	PostMessage(myWnd, WM_CLOSE, NULL, NULL);
}

void Frame::OnRButtonUp(long wParam, int x, int y)
{
	// 
}

void Frame::OnChar(long ch)
{
	// 키보드 입력이 되면 이 함수가 자동 호출됩니다.  cin이나 getchar, scanf 같은
	// 표준 입력함수는 작동하지 않으니 onchar 를 잘 이용해야 합니다.
	/*
	string s;
	s = "입력된 문자: ";
	s += ch;
	setTextColor(RGB(200, 100, 100));
	drawText(s, 100, 100);
	*/
OutputDebugString("Key 입력.\n");

}


void Frame::setPenColor(COLORREF color)
{
	thePen = CreatePen(PS_SOLID, 1, color);
	SelectObject(hDC, thePen);
}

void Frame::setPen(COLORREF color, int width)
{
	thePen = CreatePen(PS_SOLID, width, color);
	SelectObject(hDC, thePen);
}

void Frame::setFillColor(COLORREF color)
{
	theBrush = CreateSolidBrush(color);
	SelectObject(hDC, theBrush);
}


void Frame::setTextColor(COLORREF color)
{
	SetTextColor(hDC, color);
}


void Frame::rectangle(int x, int y, int sizeX, int sizeY)
{
	Rectangle(hDC, x, y, x + sizeX, y + sizeY);
}

void Frame::ellipse(int x, int y, int sizeX, int sizeY)
{
	Ellipse(hDC, x, y, x + sizeX, y + sizeY);
}

void Frame::line(int x, int y, int sizeX, int sizeY)
{
	MoveToEx(hDC, x, y, NULL);
	LineTo(hDC, x + sizeX, y + sizeY);
}


void Frame::drawText(std::string str, int x, int y)
{
	TextOut(hDC, x, y, str.c_str(), strlen(str.c_str()));
}

// 모든 윈도들을 다시 그려주는 함수.  수정이 필요할 것이다.
void Frame::display()
{
	//display를 실행해줍니다.
	m_menubar->display(); //1-1
	m_canvas->display();
	//-----------------------------------------------------
	//다른 형태로 display된다.
	Window * temp = m_menubar->openOneMenu();//3-1 //여기서 메뉴아이템을 연다
	//처음에는 메뉴에서 false로 초기화를 했기때문에 0을 반환한다.
	if (temp) {
		((Menu*)temp)->callMenuitemDisplay(); 
		//temp가 0이아닌 메뉴아이템을 반환했으면  메뉴아이템을 출력한다.
		//처음에는 false로 초기화해서 출력되지 않는다.
	}
}

// 화면이 현재 제대로 안되어 있다고 알리는 함수입니다.
// 이 함수를 호출하면 화면이 지워지고 
// Main.cpp 쪽에 case WM_PAINT: 부분이 실행됩니다.
// 결국은 Frame 객체의 display가 실행되겠죠.
void Frame::invalidate()
{
	InvalidateRect(myWnd, NULL, true);
}

// 모든 윈도들을 onInitialize 함수에서 초기화하자.
void Frame::onInitialize()
{

	// *** 모든 윈도들을 여기에서 초기화하자.
	addMenuBar(new MenuBar());
	addCanvas(new Canvas());
	Menu *fMenu = new Menu("파일"); //Menu포인터에 File과 Edit을 각각 등록(저장)한다.
	Menu *eMenu = new Menu("편집");
	m_menubar->addMenu(fMenu);//fmenu포인터와 emenu포인터를 add함수를 이용해 등록해준다.
	m_menubar->addMenu(eMenu);
	fMenu->addMenuItem(new MenuItem("열기"));
	fMenu->addMenuItem(new MenuItem("저장"));
	fMenu->addMenuItem(new MenuItem("끝내기"));
	eMenu->addMenuItem(new MenuItem("복사"));
	eMenu->addMenuItem(new MenuItem("자르기"));
	eMenu->addMenuItem(new MenuItem("붙이기"));
}

//메뉴바 저장 함수
void Frame::addMenuBar(MenuBar * mb) {
	if (!mb) return; //메뉴바가 아니면 바로 반환한다.
	windowList->push_back(mb); //windowList에 추가해준다.
	mb->setContainer(this); //container에 메뉴바가 가리키는 경우의 frame을 저장
	mb->setFrame(this); //메뉴바가 가리키는 경우의 프레임을 저장
	m_menubar = mb; //메뉴바의 멤버변수에 저장
}
//캔버스 저장함수
void Frame::addCanvas(Canvas *c) {
	if (!c)return;
	windowList->push_back(c); //windowList에 추가한다.
	c->setContainer(this);// container에 캔버스가 가리키는 경우의 frame을 저장
	c->setFrame(this); //캔버스를 window의 프레임에 저장한다.
	m_canvas = c;//캔버스의 멤버변수에 저장
}

Window * Frame::find(int x, int y) {
	Window *temp;
	// 각 윈도에게 isInside(x, y) 를 물어서 클릭된 객체의 포인터를 돌려주자.
	if (m_menubar->isInside(x, y)) {  //메뉴가 반환값이 존재하면 
		  //메뉴바를 반환해준다.
		return m_menubar;
	}
	//메뉴아이템 반환하기
	else if(temp = (m_menubar->find(x, y)) ){
		if (m_menubar->openOneMenu())
			return temp;
		else
			return m_canvas;
	}

		//메뉴바뿐만이 아니라 메뉴도 반환을 해주어야한다.
		//그렇다면 메뉴의 isInside에 접근해야한다.
		/*
		else if (((Menu*)*i)->isInside(x, y)) {
			return ((Menu*)*i)->isInside(x, y);
		}*/
	else {  //메뉴가 없으면 캔버스를 반환해준다.
		return m_canvas;
	}
	//return m_canvas;
}