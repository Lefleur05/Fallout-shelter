#include "AttackComponent.h"
#include"Game.h"

AttackComponent::AttackComponent(Actor* _owner, int _damages) : Component(_owner)
{
	damages = _damages;
	cooldown = 0.5f;
	cooldownTimer = nullptr;
}

void AttackComponent::ApplyDamagesPlayer()
{
	//recuperer la vie des humain via le hall
}

void AttackComponent::Attack()
{
	if (IsAttacking())
		return;
	ApplyDamagesPlayer();
	cooldownTimer = new Timer([&]() {ApplyDamagesPlayer(); }, seconds(cooldown), true, true);
}

void AttackComponent::StopAttack()
{
	cooldownTimer->Stop();
	cooldownTimer = nullptr;
}
