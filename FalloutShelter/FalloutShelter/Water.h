#pragma once
#include "Ressource.h"

class Water : public Ressource
{
public:
	Water(const int& _quantity, const int& _criticalQuantity, const int& _maxQuantity);
};

