#include "stdafx.h"
#include "string"
#include "stdio.h"
#include "Frame.h"
#include "Canvas.h"
#include "Menubar.h"
#include "Menu.h"
#include "MenuItem.h"
#include "Canvas.h"
#include "Figure.h"



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
	 // *** ��� ������ delete�մϴ�.
	//for (int i = 0; i < numWidget; i++) {
		//delete Windows[i];
	//}
}

void Frame::OnLButtonDown(long wParam, int x, int y)
{
	OutputDebugString("Click \n");
	// ������ ã�Ƽ� ������ onMouseClick�� ����
	Window *w = find(x, y);  //���� find(x,y)�� Frame�� ��
	if (w) { //���� �޴��ٳ� �޴��� ĵ������� 
		m_menubar->closeAllMenu();  //�޴��������� Ŭ���� �� ��� �޴��������� �ݾ��ش�.
		//�޴��������� true�϶��� Ŭ���ȴ�. �׷� ���� w(�޴�������)�� true�� �޴��������̾�� �Ѵ�.
		w->onMouseClick(x, y); //�޴��� onMouseClick���� ���õ� �޴��� ���¸� true�� �����.
	
	}
	invalidate(); //��� â�� ����� �ٽ� ����� �ش�.
		
	//control key�� shift key� ���� �ٸ��� �Ϸ���
	//Ctrl-Ŭ�� �� ���� �����

	if (wParam & MK_CONTROL) {  //��Ʈ�� �������¿��� Ŭ���ϸ�
		//ȭ�鿡 ���������� �׷��� ������ ��������.
		m_canvas->removeFigure(x,y);
	}
	

	
	// �� �ڵ�� �׽�Ʈ���̰�, Frame ��ü�� OnLButtonDown �Լ��� ȣ����
}


void Frame::OnLButtonUp(long wParam, int x, int y)
{
	Window *w = find(x, y); //�����츦 ã�Ƽ� 
	if (!w) {  //���� �����찡 ������ 
		OutputDebugString("Click "); //Click�� ����Ѵ�.
	}
	if (w) {
		w->onMouseClickUp(x, y);
	}
	//invalidate();
	/*
	 * �Ʒ��� �� ����, ä�� ������ �����ϴ� ����� �˷��ݴϴ�.
	setPenColor(RGB(255, 0, 0));
	setFillColor(RGB(255, 255, 0));
	rectangle(x, y, 100, 200);
	*/
}
void Frame::OnRButtonDown(long wParam, int x, int y)
{
	// ���α׷� ���� ����� �����ϱ� ���� ���� ��ư Ŭ���� �Ʒ� ���� ȣ���ϰ� ��������ϴ�.
	PostMessage(myWnd, WM_CLOSE, NULL, NULL);
}

void Frame::OnRButtonUp(long wParam, int x, int y)
{
	// 
}

void Frame::OnChar(long ch)
{
	// Ű���� �Է��� �Ǹ� �� �Լ��� �ڵ� ȣ��˴ϴ�.  cin�̳� getchar, scanf ����
	// ǥ�� �Է��Լ��� �۵����� ������ onchar �� �� �̿��ؾ� �մϴ�.
	
	string s;
	s = "�Էµ� ����: ";
	s += ch;
	setTextColor(RGB(200, 100, 100));
	drawText(s, 100, 100);
	
OutputDebugString("Key �Է�.\n");

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

//�簢��
void Frame::rectangle(int x, int y, int sizeX, int sizeY)
{
	Rectangle(hDC, x, y, x + sizeX, y + sizeY);
}
//Ÿ��
void Frame::ellipse(int x, int y, int sizeX, int sizeY)
{
	Ellipse(hDC, x, y, x + sizeX, y + sizeY);
}

//������ �׷��ִ� �Լ�
void Frame::line(int x, int y, int sizeX, int sizeY)
{
	MoveToEx(hDC, x, y, NULL);  
	//x�� ���ο� ��ġ�� ��ǥ, y�� ���ο� ��ġ��y��ǥ 
	LineTo(hDC, x + sizeX, y + sizeY);
	//x+xsize�� �׸��� ��ǥ ���� x , y+ysize�� �׸��� ��ǥ ����
}


void Frame::drawText(std::string str, int x, int y)
{
	TextOut(hDC, x, y, str.c_str(), strlen(str.c_str()));
}

// ��� �������� �ٽ� �׷��ִ� �Լ�.  ������ �ʿ��� ���̴�.
void Frame::display()
{
	//display�� �������ݴϴ�.
	m_menubar->display(); 
	m_canvas->display();
	//-----------------------------------------------------
	//�ٸ� ���·� display�ȴ�.
	Window * temp = m_menubar->openOneMenu();//���⼭ �޴��������� ����
	//ó������ �޴����� false�� �ʱ�ȭ�� �߱⶧���� 0�� ��ȯ�Ѵ�.
	if (temp) {
		((Menu*)temp)->callMenuitemDisplay(); 
		//temp�� 0�̾ƴ� �޴��������� ��ȯ������  �޴��������� ����Ѵ�.
		//ó������ false�� �ʱ�ȭ�ؼ� ��µ��� �ʴ´�.
	}
}

// ȭ���� ���� ����� �ȵǾ� �ִٰ� �˸��� �Լ��Դϴ�.
// �� �Լ��� ȣ���ϸ� ȭ���� �������� 
// Main.cpp �ʿ� case WM_PAINT: �κ��� ����˴ϴ�.
// �ᱹ�� Frame ��ü�� display�� ����ǰ���.
void Frame::invalidate()
{
	InvalidateRect(myWnd, NULL, true);
}

// ��� �������� onInitialize �Լ����� �ʱ�ȭ����.
void Frame::onInitialize()
{

	// *** ��� �������� ���⿡�� �ʱ�ȭ����.
	addMenuBar(new MenuBar());
	addCanvas(new Canvas());
	Menu *fMenu = new Menu("����"); //Menu�����Ϳ� File�� Edit�� ���� ���(����)�Ѵ�.
	Menu *eMenu = new Menu("����");
	m_menubar->addMenu(fMenu);//fmenu�����Ϳ� emenu�����͸� add�Լ��� �̿��� ������ش�.
	m_menubar->addMenu(eMenu);
	fMenu->addMenuItem(new MenuItem("����"));
	fMenu->addMenuItem(new MenuItem("����"));
	fMenu->addMenuItem(new MenuItem("������"));
	eMenu->addMenuItem(new MenuItem("����"));
	eMenu->addMenuItem(new MenuItem("�ڸ���"));
	eMenu->addMenuItem(new MenuItem("���̱�"));
}

//�޴��� ���� �Լ�
void Frame::addMenuBar(MenuBar * mb) {
	if (!mb) return; //�޴��ٰ� �ƴϸ� �ٷ� ��ȯ�Ѵ�.
	windowList->push_back(mb); //windowList�� �߰����ش�.
	mb->setContainer(this); //WindowList�� ���ԵǾ��ִ� MenuBar�� �������� �ش�.
	mb->setFrame(this); //MenuBar���� �������� �ش�.
	m_menubar = mb; //�޴����� ��������� ����
}
//ĵ���� �����Լ�
void Frame::addCanvas(Canvas *c) {
	if (!c)return;
	windowList->push_back(c); //windowList�� �߰��Ѵ�.
	c->setContainer(this);// container�� ĵ������ ����Ű�� ����� frame�� ����
	c->setFrame(this); //ĵ������ window�� �����ӿ� �����Ѵ�.
	m_canvas = c;//ĵ������ ��������� ����
}

Window * Frame::find(int x, int y) {
	Window *temp;
	// �� �������� isInside(x, y) �� ��� Ŭ���� ��ü�� �����͸� ��������.
	if (m_menubar->isInside(x, y)) {  //�޴��� ��ȯ���� �����ϸ� 
		  //�޴��ٸ� ��ȯ���ش�.
		return m_menubar;
	}
	//�޴������� ��ȯ�ϱ�
	else if(temp = (m_menubar->find(x, y)) ){ //�޴��� ã�µ�
		if (m_menubar->openOneMenu())  //�� ��, ture�� �޴����
			return temp; //�� �޴��� ��ȯ���ش�.
		else
			return m_canvas;
	}
	else {  //�޴��� ������ ĵ������ ��ȯ���ش�.
		return m_canvas;
	}
}