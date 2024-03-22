#pragma once
#include"Transition.h"

class MoveToTransiton : public Transition  
{
public:
	MoveToTransiton(FSM* _owner);
	virtual void Init(State* _nextState) override;
	virtual bool CanNext() const override;
};

