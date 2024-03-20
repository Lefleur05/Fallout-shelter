#pragma once
#include"Timer.h"
#include"Component.h"

class AttackComponent : public Component
{
	int damages;
	float cooldown;
	Timer* cooldownTimer;
private:
	bool IsAttacking() const
	{
		return cooldown && cooldownTimer->IsRunning();
	}
public:
	void SetDamages(const int _damages)
	{
		damages = _damages;
	}
	int GetDamages() const 
	{
		return damages;
	}
public:
	AttackComponent(Actor* _owner, const int _damages);
private:
	void ApplyDamagesPlayer();
public:
	void Attack();
	void StopAttack();
};

