#include "Human.h"
#include "Macro.h"
#include"MapManager.h"
#include"PlayerBunker.h"

#define PATH_VILLAGER "Villager.png"

Human::Human(const ShapeData& _data)
	: Entity(STRING_ID("Humain"), ShapeData(_data.position, _data.size, PATH_VILLAGER, _data.rect))
{
	stats = new StatsHuman();
	armor = nullptr;
	weapons = nullptr;
	movement = new HumainMovementComponent(this, Vector2f(60.f,0.0f));
	components.push_back(movement);
	PLAYERBUNKER->AddHuman(this);
}


