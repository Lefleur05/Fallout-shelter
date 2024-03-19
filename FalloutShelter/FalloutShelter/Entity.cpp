#include "Entity.h"
#include"Macro.h"

Entity::Entity(const string& _name, const ShapeData& _data, const int& _life) : Actor(_name + to_string(GetUniqueID()), _data)
{
	life = _life;
	shape = new RectangleShape(_data.size);
	shape->setPosition(_data.position);
}
