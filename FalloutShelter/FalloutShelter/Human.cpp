#include "Human.h"
#include "Macro.h"
#include"MapManager.h"

Human::Human(const ShapeData& _data): Entity(STRING_ID("Humain"),_data)
{
	stats = new StatsHuman();
	mentalHealth = 100;
	armor = nullptr;
	weapons = nullptr;
	movement = new HumainMovementComponent(this, Vector2f(80.f,0.0f));
	components.push_back(movement);
}


