#include "HumainMovementComponent.h"
#include"Actor.h"

HumainMovementComponent::HumainMovementComponent(Actor* _owner, const Vector2f& _targetPosition) : MovementComponent(_owner)
{
	pauseDuration = 1.0f;
	startPosition = _owner->GetShapePosition();
	targetPosition = startPosition + _targetPosition;
	cout << targetPosition.x << " " << targetPosition.y << endl;
}

void HumainMovementComponent::ChangeTargetPosition()
{
	const bool _isAtDestination = GetDestination() == startPosition;
	cout << _isAtDestination << endl;
	SetDestination(_isAtDestination ? targetPosition : startPosition);
}

void HumainMovementComponent::Init()
{
	SetCallback([&]()
	{
			SetCanMove(false);
			patrolTimer = new Timer([&]() {ChangeTargetPosition(); }, seconds(pauseDuration), true, false);
	});
}
