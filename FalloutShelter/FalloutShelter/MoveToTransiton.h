#pragma once
#include"Transition.h"

class MoveToTransiton : public Transition  
{
public:
	virtual void Init(State* _nextState) override;
	virtual bool CanNext() const override;
};

