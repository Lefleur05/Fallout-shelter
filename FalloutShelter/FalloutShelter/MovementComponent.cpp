#include "MovementComponent.h"
#include "AnimationComponent.h"
#include "Actor.h"
#include"Macro.h"
#include "DevUtils.h"

MovementComponent::MovementComponent(Actor* _owner) : Component(_owner)
{
	canMove = true;
	minRange = 0.5f;
	//destination = _owner->GetShapePosition();
	speed = 0.2f;
	collision = _owner->GetComponent<CollisionComponent>();
}

void MovementComponent::SetCanMove(const bool _status)
{
	canMove = _status;

	if (!animation)
	{
		animation = owner->GetComponent<AnimationComponent>();
		if (!animation) return;
	}

	if (!canMove)
	{
		animation->RunAnimation("Idle", lastDirection.x);
	}
}

void MovementComponent::SetDestination(const Vector2f& _destination, const bool _canMove)
{
	destination = _destination;
	canMove = _canMove;

	Vector2f _newDirection = _destination - owner->GetShapePosition();
	Normalize(_newDirection);

	//if (_newDirection.x != lastDirection.x)
	//{
	//	canMove = false;
	//	owner->GetComponent<AnimationComponent>()->RunAnimation("Turn", lastDirection.x);
	//	owner->GetComponent<AnimationComponent>()->GetCurrentAnimation()->SetDirectionX(_newDirection.x);

	//	new Timer([&]()
	//		{
	//			SetCanMove(true);
	//		}, seconds(0.75f), true, false);
	//}
	//else
	//{
	//	owner->GetComponent<AnimationComponent>()->RunAnimation("Running", lastDirection.x);
	//}
}

void MovementComponent::MoveToDestination(const float _deltaTime)
{
	if (!canMove) return;
	if (IsAtPosition())
	{
		if (callback)
		{
			callback();
		}

		canMove = false;
		return;
	}
	Shape* _shape = owner->GetDrawable();
	Vector2f _direction = destination - _shape->getPosition();
	Normalize(_direction);
	lastDirection = _direction;

	const Vector2f& _position = _shape->getPosition() + _direction * speed * _deltaTime;
	_shape->setPosition(_position);
	//LOG("Move");
}

//bool MobMovementComponent::CheckGround()
//{
//	HitInfo _hit;
//	const bool _hasHit = Raycast(owner->GetShapePosition() + Vector2f(0.0f, 40.0f), Vector2f(0.0f, 1.0f),
//		checkGroundDistance, _hit, { owner });
//
//	return _hasHit;
//}

void MovementComponent::Update(const float _deltaTime)
{
	Component::Update(_deltaTime);
	MoveToDestination(_deltaTime);

	Vector2f _offset = Vector2f(0.0f, 0.0f);
	Vector2f _direction = destination;
	Normalize(_direction);
	//if (isOnGround && owner->GetComponent<EnemyLifeComponent>()->GetLife() <= 0)
	//{
	//	owner->GetComponent<AnimationComponent>()->GetCurrentAnimation()->StopLoopAnimation();
	//	return;
	//}

	//if (!(isOnGround = CheckGround()) && !isJumping && !isFlying)
	//{
	//	// Application de la gravité
	//	_offset = _direction + Vector2f(0.0f, 1.0f);
	//	Normalize(_offset);
	//	_offset *= gravity * _deltaTime;
	//}
	//else if (isJumping)
	//{
	//	// Application du saut
	//	_offset = _direction + Vector2f(0.0f, -1.0f);
	//	Normalize(_offset);
	//	_offset *= jumpForce * _deltaTime;
	//}
	owner->GetDrawable()->move(_offset);
}

bool MovementComponent::IsAtPosition() const
{
	return Distance(owner->GetShapePosition(), destination) <= minRange;
}