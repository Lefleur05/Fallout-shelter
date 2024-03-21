#include "Human.h"
#include "Macro.h"
#include"MapManager.h"
#include"PlayerBunker.h"

Human::Human(const ShapeData& _data): Entity(STRING_ID("Humain"),_data)
{
	stats = new StatsHuman();
	mentalHealth = 100;
	armor = nullptr;
	weapons = nullptr;
	movement = new HumainMovementComponent(this, Vector2f(60.f,0.0f));
	components.push_back(movement);
	PLAYERBUNKER->AddHuman(this);
}


