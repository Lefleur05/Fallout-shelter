#pragma once
#include "Entity.h"
#include "Weapons.h"
#include "Armor.h"
#include"HumainMovementComponent.h"

struct StatsHuman
{
	//force
	int strength;
	//perception
	int perception;
	//endurance
	int endurance;
	//charisme
	int charism;
	//agilité
	int agility;
	//chance
	int luck;

	int mentalHealth;

public:
	StatsHuman()
	{
		strength = 1;
		perception = 1;
		endurance = 1;
		charism = 1;
		agility = 1;
		luck = 1;
		mentalHealth = 100;
	}
};

class Human: public Entity
{
	StatsHuman* stats;
	Armor* armor;
	Weapons* weapons;
	HumainMovementComponent* movement;


public:
	StatsHuman* GetStats()
	{
		return stats;
	}
public:
	Human(const ShapeData& _data);
};

