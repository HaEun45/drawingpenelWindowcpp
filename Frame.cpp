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
	Window *w = find(x, y);
	if (w) {
		w->onMouseClick(x, y);
	}
	/* 
	control key�� shift key� ���� �ٸ��� �Ϸ���
	if (wParam & MK_CONTROL)  .. MK_SHIFT ��

	*/
	// �� �ڵ�� �׽�Ʈ���̰�, Frame ��ü�� OnLButtonDown �Լ��� ȣ����
}

void Frame::OnLButtonUp(long wParam, int x, int y)
{
	Window *w = find(x, y); //�����츦 ã�Ƽ�
	if (!w) {  //���� �����찡 ������
		OutputDebugString("Click "); //Click�� ����Ѵ�.
	}
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
	/*
	string s;
	s = "�Էµ� ����: ";
	s += ch;
	setTextColor(RGB(200, 100, 100));
	drawText(s, 100, 100);
	*/
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

// ��� �������� �ٽ� �׷��ִ� �Լ�.  ������ �ʿ��� ���̴�.
void Frame::display()
{
	//display�� �������ݴϴ�.
	m_menubar->display(this);
	m_canvas->display(this);
	//����Ʈ�� ������ִ� �κ�
	list<Window *>::iterator i;
	for (i = stuff->begin(); i != stuff->end(); i++) {
		(*i)->display(this);
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
	m_menubar = new MenuBar(); 
	Menu *fmenu = new Menu("File");  //Menu�����Ϳ� File�� Edit�� ���� ���(����)�Ѵ�.
	Menu *emenu = new Menu("Edit");
	m_menubar->add(fmenu);  //fmenu�����Ϳ� emenu�����͸� add�Լ��� �̿��� ������ش�.
	m_menubar->add(emenu);
	m_canvas = new Canvas(this);  //ĵ������ �ڱ��ڽ��� �ѱ�鼭 ������ش�.

}

Window * Frame::find(int x, int y) {
	// �� �������� isInside(x, y) �� ��� Ŭ���� ��ü�� �����͸� ��������.
	
	if (m_menubar->isInside(x, y)) {  //�޴��� �����Ѵٸ�
		return m_menubar;  //�޴��ٸ� ��ȯ���ش�.
	}
	else {  //�޴��� ������ ĵ������ ��ȯ���ش�.
		return m_canvas;
	}
}