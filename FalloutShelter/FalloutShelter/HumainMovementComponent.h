#pragma once
#include"MovementComponent.h"

class HumainMovementComponent : public MovementComponent
{
	float pauseDuration;
	Vector2f startPosition;
	Vector2f targetPosition;
	Timer* patrolTimer;

public:
	HumainMovementComponent(Actor* _owner,const Vector2f& _targetPosition);
public:
	void SetTargetPosition(const Vector2f& _targetPosition)
	{
		targetPosition = _targetPosition;
	}
private:
	void ChangeTargetPosition();
public:
	virtual void Init() override;
};

