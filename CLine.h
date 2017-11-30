#pragma once
#include "Figure.h" 
#include <iostream>
using namespace std;

class CLine :public Figure
{
public:
	CLine();
	CLine(int x, int y, int UpX, int UpY);
	~CLine();
	virtual void draw();
	virtual Figure* isInside(int x, int y);
};
