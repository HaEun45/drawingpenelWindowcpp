#pragma once
#include "Figure.h"
#include <iostream>
using namespace std;

class CEllipse :public Figure
{
public:
	CEllipse();
	CEllipse(int x, int y, int UpX, int UpY);
	~CEllipse();
	virtual void draw();
	
	virtual Figure* isInside(int x, int y);
};
