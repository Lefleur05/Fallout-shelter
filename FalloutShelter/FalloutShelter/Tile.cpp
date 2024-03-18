#include "Tile.h"

Tile::Tile( const Vector2f& _position, const TileType& _type, const Vector2f& _size)
{
	type = _type;
	shape = new RectangleShape(_size);
	shape->setPosition(_position);
	hall = nullptr;
}

Tile::~Tile()
{
	delete shape;
}
