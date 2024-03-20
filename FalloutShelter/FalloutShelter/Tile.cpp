#include "Tile.h"

Tile::Tile( const Vector2f& _position, const TileType& _type, const Vector2f& _size)
{
	type = _type;
	shape = new RectangleShape(_size);
	shape->setPosition(_position);
	hall = nullptr;

	if (type== ET_EXTERNE)
	{
		TextureManager::GetInstance().Load(shape, EXTRENE_TEXTURE);
		return;
	}
	TextureManager::GetInstance().Load(shape, DIRT_TEXTURE);
}

Tile::~Tile()
{
	delete shape;
}

void Tile::Update()
{

}
