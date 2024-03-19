#pragma once
//#include "MovementCompenent"
#include <SFML/Graphics.hpp>
#include"Actor.h"
using namespace sf;

class Entity : public Actor
{
	Shape* shape;
	int life;
	//MovementCompenent* movementComponent;

public:
	Entity(const string& _name, const ShapeData& _data, const int& _life = 100);
};

