#pragma once
#include"ShapeObject.h"
using namespace std;

class Nodes;
class GridNav
{
	int size = 2;
	int gap = 1;
	Vector2f position;
	vector<Nodes*> nodes;

public:
	GridNav(const int _size, const int _gap,const Vector2f& _offsetGrid);
	~GridNav();
	void RestCost();
	Nodes* GetClosesNode(Vector2f _location);
	vector<Nodes*>& GetNodes()
	{
		return nodes;
	}
private:
	void Generate();
	void SetSuccessors();
};

