#pragma once
//#include "MovementCompenent"
#include <SFML/Graphics.hpp>
using namespace sf;

class Entity
{
	Shape* shape;
	int life;
	//MovementCompenent* movementComponent;

public:
	Entity(const Vector2f& _position, const Vector2f& _size = Vector2f(50.0f, 50.0f), const int& _life = 100);


};

