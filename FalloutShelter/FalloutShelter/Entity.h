#pragma once
//#include "MovementCompenent"
#include <SFML/Graphics.hpp>
#include"Actor.h"
using namespace sf;

class Entity : public Actor
{
protected:
	Shape* shape;
	int life;
public:
	Entity(const string& _name, const ShapeData& _data, const int& _life = 100);
	int GetLifeEntity()
	{
		return life;
	}	
	int ReduceLifeHuman()
	{
		if (life == 0)
		{
			return 0;
		}
		return life--;
	}
};

