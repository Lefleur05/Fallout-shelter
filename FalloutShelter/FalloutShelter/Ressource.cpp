#include "Ressource.h"

Ressource::Ressource(const string& _nameRessource, const int& _quantity, const int& _criticalQuantity, const int& _maxQuantity)
{
	nameRessource = _nameRessource;
	quantity = _quantity;
	criticalQuantity = _criticalQuantity;
	maxQuantity = _maxQuantity;
}
