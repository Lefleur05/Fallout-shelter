#include "Enemy.h"

Enemy::Enemy(const string& _name, const ShapeData& _data) : Actor(_name, _data, CT_NONE)
{

}

void Enemy::Update(const float _deltaTime)
{
	Actor::Update(_deltaTime);
}
