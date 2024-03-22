#include "HumainMovementComponent.h"
#include"Actor.h"

HumanMovementComponent::HumanMovementComponent(Actor* _owner, const Vector2f& _targetPosition) : MovementComponent(_owner)
{
	pauseDuration = 1.0f;
	destination = _owner->GetShapePosition();
	startPosition = _owner->GetShapePosition();
	targetPosition = startPosition + _targetPosition;
	cout << targetPosition.x << " " << targetPosition.y << endl;
}

void HumanMovementComponent::ChangeTargetPosition()
{
	const bool _isAtDestination = GetDestination() == startPosition;
	cout << _isAtDestination << endl;
	SetDestination(_isAtDestination ? targetPosition : startPosition);
}

void HumanMovementComponent::Init()
{
	SetCallback([&]()
	{
			SetCanMove(false);
			patrolTimer = new Timer([&]() {ChangeTargetPosition(); }, seconds(pauseDuration), true, false);
	});
}
