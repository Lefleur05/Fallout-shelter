#include "MoveToTransiton.h"

void MoveToTransiton::Init(State* _nextState)
{
	nextState = _nextState;
}

bool MoveToTransiton::CanNext() const
{
	//si il est isAtLocation()
	return false;
}
