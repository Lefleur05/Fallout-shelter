#pragma once
#include"MoveToState.h"
#include"Actor.h"
#include"FSM.h"

class FSMEnemy : public FSM
{
	MoveToState* moveTo = nullptr;
public:
	MoveToState* GetMoveTo()
	{
		return moveTo;
	}
public:
	FSMEnemy(Actor* _owner);
public: 
	 void Init();
};

