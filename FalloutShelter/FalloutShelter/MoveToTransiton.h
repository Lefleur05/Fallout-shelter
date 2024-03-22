#pragma once
#include"Transition.h"
#include"Timer.h"

class MoveToTransiton : public Transition  
{
	bool isRange = false;
	Timer* testTimer;
public:
	MoveToTransiton(FSM* _owner);
	virtual void Init() override;
	virtual bool CanNext() const override;
};

