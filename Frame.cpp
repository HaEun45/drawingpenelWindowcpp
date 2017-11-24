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
	 // *** ��� ������ delete�մϴ�.
	//for (int i = 0; i < numWidget; i++) {
		//delete Windows[i];
	//}
}

void Frame::OnLButtonDown(long wParam, int x, int y)
{
	OutputDebugString("Click \n");
	// ������ ã�Ƽ� ������ onMouseClick�� ����
	Window *w = find(x, y);  //4-1  //���� find(x,y)�� Frame�� ��
	if (w) { //���� �޴��ٳ� �޴��� ĵ������� 
		m_menubar->closeAllMenu();  //6-1 //�޴��������� Ŭ���� �� ��� �޴��������� �ݾ��ش�.
		//�޴��������� true�϶��� Ŭ���ȴ�. �׷� ���� w(�޴�������)�� true�� �޴��������̾�� �Ѵ�.
		w->onMouseClick(x, y); //5-1 //�޴��� onMouseClick���� ���õ� �޴��� ���¸� true�� �����.
		
		/*Window * temp = m_menubar->openOneMenu();
		if (temp) {
			((Menu*)temp)->callMenuitemDisplay(this);
		}*/
		// find���� ã�� ��ȯ���� 0�� �ƴϸ� �׻� �޴��� �ο� ������ false�� �����.
		//�޴��������� ������.
	}
	invalidate(); //��� â�� ����� �ٽ� ����� �ش�.
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
	m_menubar->display(); //1-1
	m_canvas->display();
	//-----------------------------------------------------
	//�ٸ� ���·� display�ȴ�.
	Window * temp = m_menubar->openOneMenu();//3-1 //���⼭ �޴��������� ����
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
	mb->setContainer(this); //container�� �޴��ٰ� ����Ű�� ����� frame�� ����
	mb->setFrame(this); //�޴��ٰ� ����Ű�� ����� �������� ����
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
	else if(temp = (m_menubar->find(x, y)) ){
		if (m_menubar->openOneMenu())
			return temp;
		else
			return m_canvas;
	}

		//�޴��ٻӸ��� �ƴ϶� �޴��� ��ȯ�� ���־���Ѵ�.
		//�׷��ٸ� �޴��� isInside�� �����ؾ��Ѵ�.
		/*
		else if (((Menu*)*i)->isInside(x, y)) {
			return ((Menu*)*i)->isInside(x, y);
		}*/
	else {  //�޴��� ������ ĵ������ ��ȯ���ش�.
		return m_canvas;
	}
	//return m_canvas;
}