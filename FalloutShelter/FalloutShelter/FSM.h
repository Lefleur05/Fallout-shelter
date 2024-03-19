#pragma once
#include"Component.h"
#include"BlackBorad.h"
#include"State.h"
#include<vector>
using namespace std;

class FSM : public Component
{

protected:
	State* currentState = nullptr;
	vector<State*> allState;
public:

	template <typename T>
	T* GetState() const
	{
		for (State* _currentState : allState)
		{
			if (T* _state = (T*)(_currentState))
			{
				return _state;
			}
		}
		return nullptr;
	}
public:
	FSM(Actor* _owner);
	~FSM();
public:
	virtual void Init();
	virtual void Update(const float _deltaTime) override;
};

