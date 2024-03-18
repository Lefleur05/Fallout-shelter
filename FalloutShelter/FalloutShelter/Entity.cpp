#include "Entity.h"

Entity::Entity(const Vector2f& _position, const Vector2f& _size, const int& _life)
{
	life = _life;
	shape = new RectangleShape(_size);
	shape->setPosition(_position);

}
