#include "Enemy.h"

Enemy::Enemy(const string& _name, const ShapeData& _data) : Entity(_name, _data, CT_NONE)
{
	move = new EnemyMovementComponent(this);
	components.push_back(move);
}

void Enemy::Update(const float _deltaTime)
{
	Actor::Update(_deltaTime);
}
