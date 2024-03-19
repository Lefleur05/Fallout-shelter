#pragma once
#include "Human.h"
class Woman : public Human
{
	bool isPregnant;

public:
	Woman(const ShapeData& _data);
};

