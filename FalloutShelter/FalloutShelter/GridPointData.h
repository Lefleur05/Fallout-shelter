#pragma once
#include<SFML/Graphics.hpp>
#include<vector>
#include"Nodes.h"
using namespace std;
using namespace sf;

class GridPointData
{
	vector<Nodes*> nodes;

public:
	GridPointData();
	void RestCost();
	Nodes* GetClosesNode(Vector2f _location);
	vector<Nodes*>& GetNodes()
	{
		return nodes;
	}
};

