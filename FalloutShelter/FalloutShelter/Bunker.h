#pragma once
#include"Items.h"
#include"Ressource.h"
#include"Human.h"
#include<vector>

using namespace std;

class Bunker
{
	int money;
	vector<Items*> allItemsInBunker; // TODO faire class Items
	vector<Ressource*> ressources;
	vector<Human*> allHuman;
	int healthPotionsCount;


public:
	int GetMoney()
	{
		return money;
	}

	vector<Human*> GetAllHuman()
	{
		return allHuman;
	}

	void AddHuman(Human* _human)
	{
		allHuman.push_back(_human);
	}
	vector<Ressource*> GetAllRessource()
	{
		return ressources;
	}

	void SetMoney(const int& _money)
	{
		money = _money;
	}

public:
	Bunker();
	Bunker(const int& _money, vector<Items*> _allItemsInBunker, vector<Ressource*> _ressources, const int& _healthPotionsCount);
	~Bunker();

public:
	void InitRessource();
	void RemoveRessource();
	



};

