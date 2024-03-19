#include "Tile.h"

Tile::Tile( const Vector2f& _position, const TileType& _type, const Vector2f& _size)
{
	type = _type;
	shape = new RectangleShape(_size);
	shape->setPosition(_position);
	hall = nullptr;

	TextureManager::GetInstance().LoadWithRect(shape, DIRT_TEXTURE, rect);
}

Tile::~Tile()
{
	delete shape;
}
