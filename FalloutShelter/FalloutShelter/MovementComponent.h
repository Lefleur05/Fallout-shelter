#pragma once
#include "Component.h"
#include "CollisionComponent.h"
#include "AnimationComponent.h"

#include <SFML/Graphics.hpp>
#include <functional>
#include <iostream>

using namespace std;
using namespace sf;

class MovementComponent : public Component
{
protected:
	bool canMove;
	float speed;
	float gravity;
	float minRange;
	Vector2f lastDirection;
	Vector2f destination;
	function<void()> callback;
	AnimationComponent* animation;
	CollisionComponent* collision;

public:
	void SetSpeed(const float _speed)
	{
		speed = _speed;
	}	

	void SetCallback(const function<void()>& _callback)
	{
		callback = _callback;
	}
	void SetCanMove(const bool _status);
	void SetDestination(const Vector2f& _destination, const bool _canMove = true);
	void Update(const float _deltaTime) override;
	bool IsAtPosition() const;
	bool GetCanMove() const
	{
		return canMove;
	}
	Vector2f GetLastDirection() const
	{
		return lastDirection;
	}
	Vector2f GetDestination() const
	{
		return destination;
	}

public:
	MovementComponent(Actor* _owner);
private:
	void MoveToDestination(const float _deltaTime);
};
