#pragma once
#include <iostream>
using namespace std;

class Ressource
{
	string nameRessource;

protected:
	int quantity;
	int criticalQuantity;
	int maxQuantity;

public:
	void SetQuantity(const int& _quantity)
	{
		quantity = _quantity;
	}
	void SetCriticalQuantity(const int& _criticalQuantity)
	{
		criticalQuantity = _criticalQuantity;
	}
	void SetMaxQuantity(const int& _maxQuantity)
	{
		maxQuantity = _maxQuantity;
	}

	int GetQuantity()
	{
		return quantity;
	}
	int GetCriticalQuantity()
	{
		return criticalQuantity;
	}
	int GetMaxQuantity()
	{
		return maxQuantity;
	}

public:
	Ressource(const string& _nameRessource, const int& _quantity, const int& _criticalQuantity, const int& _maxQuantity);
};

