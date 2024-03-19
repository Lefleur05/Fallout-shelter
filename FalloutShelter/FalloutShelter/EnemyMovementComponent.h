#pragma once
#include"MovementComponent.h"

class EnemyMovementComponent : public MovementComponent
{
	Vector2f destination;
	bool canMove;
	float minRange;
public:
	EnemyMovementComponent(Actor* _owner);
	virtual void Update(const float _deltaTime) override;
	void MoveTo(const float _deltaTime);
	void SetDestination(Vector2f _destination, bool _canMove = true);
	const bool IsAtPosition();
};

