#pragma once
#include"Items.h"
#include"Ressource.h"
#include<vector>

using namespace std;

class Bunker
{
	int money;
	vector<Items*> allItemsInBunker; // TODO faire class Items
	vector<Ressource*> ressources;
	int healthPotionsCount;


public:
	int GetMoney()
	{
		return money;
	}

public:
	Bunker();
	Bunker(const int& _money, vector<Items*> _allItemsInBunker, vector<Ressource*> _ressources, const int& _healthPotionsCount);
	~Bunker();

public:
	void InitRessource();




};

