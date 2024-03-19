#pragma once
#include"Transition.h"
#include"Timer.h"
#include<vector>

using namespace std;

class FSM;
class State
{
	Transition* nextTransition = nullptr;
protected:
	FSM* fsm = nullptr;
	vector<Transition*> transitions;

public:
	Transition* GetNextTransition()
	{
		Transition* _nextTransition = nextTransition;
		nextTransition = nullptr;
		return _nextTransition;
	}

public:
	State(FSM* _owner);
	~State();
public:
	virtual void Init();
	virtual void Start();
	virtual void Update(const float _deltaTime);
	virtual void Stop();
};

