#pragma once
#include<SFML/Graphics.hpp>
#include<vector>
#include"Actor.h"
using namespace sf;
using namespace std;

class GridNav;
class Nodes : public Actor
{
	vector<int> succesors;
	float G;
	float H;
	float F;
	bool isOpen = true;
	Nodes* parent;
	GridNav* gridNav = nullptr;
public:
	Nodes(const ShapeData& _data, GridNav* _grid);
	Nodes(const ShapeData& _data);
	void ResteNode();
	void AddSuccessor(const int _successors)
	{
		succesors.push_back(_successors);
	}
	void SetIsOpen(const bool _isOpen)
	{
		isOpen = _isOpen;
	}
	void SetG(float _g) { G = _g; }
	void SetH(float _h) { H = _h; }
	void SetParent(Nodes* _parent) { parent = _parent; }
public:
	float GetG()  { return G; }
	float GetH()  { return H; }
	float GetF() const { return F; }
	bool GetIsOpen() { return isOpen; }
	vector<int>& GetSuccessors()
	{
		return succesors;
	}
	Nodes* GetParent() const
	{
		return parent;
	}
	GridNav* GetGridNav()
	{
		return gridNav;
	}
};

