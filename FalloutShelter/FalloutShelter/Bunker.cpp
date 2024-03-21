#include "Bunker.h"
#include "Food.h"
#include "Water.h"
#include "Electicity.h"

Bunker::Bunker()
{
	money = 0;
	allItemsInBunker = vector<Items*>();
	ressources = vector<Ressource*>();
	allHuman = vector<Human*>();
	healthPotionsCount = 0;

	InitRessource();
}

Bunker::Bunker(const int& _money, vector<Items*> _allItemsInBunker, vector<Ressource*> _ressources, const int& _healthPotionsCount)
{
	money = _money;
	allItemsInBunker = _allItemsInBunker;
	ressources = _ressources;
	allHuman = vector<Human*>();
	healthPotionsCount = _healthPotionsCount;

	InitRessource();

}

Bunker::~Bunker()
{
	for (Items* _item: allItemsInBunker)
	{
		delete _item;
	}
	for (Ressource* _ressource : ressources)
	{
		delete _ressource;
	}
}

void Bunker::InitRessource()
{
	ressources.push_back(new Electicity(0, 0, 0));
	ressources.push_back(new Food(0, 0, 0));
	ressources.push_back(new Water(0, 0, 0));
}
