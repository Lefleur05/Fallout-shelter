#include "Human.h"

Human::Human(const ShapeData& _data): Entity("Humain",_data)
{
	stats = new StatsHuman();
	mentalHealth = 100;
	armor = nullptr;
	weapons = nullptr;
}
