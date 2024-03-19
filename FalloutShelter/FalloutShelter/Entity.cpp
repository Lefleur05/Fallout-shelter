#include "Entity.h"

Entity::Entity(const string& _name, const ShapeData& _data, const int& _life) : Actor(_name, _data)
{
	life = _life;
	//shape = new RectangleShape(_size);
	//shape->setPosition(_position);
}
