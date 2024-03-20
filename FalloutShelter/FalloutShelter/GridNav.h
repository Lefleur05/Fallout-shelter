#pragma once
#include"ShapeObject.h"
using namespace std;

class GridPointData;
class GridNav
{
	GridPointData* data;
	int size = 2;
	int gap = 1;
	Vector2f position;

public:
	GridNav(const int _size, const int _gap,const Vector2f& _offsetGrid);
	~GridNav();
private:
	void Generate();
	void SetSuccessors();
};

