#include "Enemy.h"

Enemy::Enemy(const string& _name, const ShapeData& _data) : Entity(_name, _data, CT_BLOCK)
{
	move = new EnemyMovementComponent(this);
	components.push_back(move);
}

void Enemy::Update(const float _deltaTime)
{
	Entity::Update(_deltaTime);
	move->FollowPath(_deltaTime);
}

