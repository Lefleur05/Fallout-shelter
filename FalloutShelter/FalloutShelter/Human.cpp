#include "Human.h"

Human::Human(const Vector2f& _position): Entity(_position)
{
	stats = new StatsHuman();
	mentalHealth = 100;
	armor = nullptr;
	weapons = nullptr;
}
