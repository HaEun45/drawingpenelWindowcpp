#pragma once
#include "Figure.h"

class CRectangle :public Figure
{
public:
	CRectangle();
	CRectangle(int x, int y, int UpX, int UpY);
	~CRectangle();
	virtual void draw();
	virtual Figure* isInside(int x, int y);

};