#include "AttackComponent.h"
#include "PlayerBunker.h"

AttackComponent::AttackComponent(Actor* _owner, int _damages) : Component(_owner)
{
	damages = _damages;
	cooldown = 1.f;
	cooldownTimer = nullptr;
}

void AttackComponent::ApplyDamagesPlayer()
{
	for (size_t i = 0; i < PLAYERBUNKER->GetAllHuman().size(); i++)
	{
		PLAYERBUNKER->GetAllHuman()[i]->ReduceLifeHuman();
	}
}

void AttackComponent::Attack()
{
	ApplyDamagesPlayer();
	cooldownTimer = new Timer([&]() {ApplyDamagesPlayer(); }, seconds(cooldown), true, true);
}

void AttackComponent::StopAttack()
{
	cooldownTimer->Stop();
	cooldownTimer = nullptr;
}
