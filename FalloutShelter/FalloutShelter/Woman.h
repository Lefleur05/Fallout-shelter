#pragma once
#include "Human.h"
class Woman : public Human
{
	bool isPregnant;

public:
	Woman(const Vector2f& _position);
};

