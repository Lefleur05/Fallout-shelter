#pragma once
#include"Ressource.h"
class Food: public Ressource
{
public:
	Food(const int& _quantity, const int& _criticalQuantity, const int& _maxQuantity);
};

