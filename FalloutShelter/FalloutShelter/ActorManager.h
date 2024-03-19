#pragma once
#include "Singleton.h"
#include "IManager.h"
#include "Actor.h"
#include<iostream>
//#include "InteractableActor.h"

class ActorManager : public Singleton<ActorManager>, public IManager<string, Actor>
{
	//vector<InteractableActor*> interactables;

	bool stop;
public:
	//void AddInteractable(InteractableActor* _interactable)
	//{
	//	interactables.push_back(_interactable);
	//}
	//vector<InteractableActor*> GetInteractables() const
	//{
	//	return interactables;
	//}
	vector<Drawable*> GetDrawables()
	{
		vector<Drawable*> _drawables;
		for (Actor* _actor : GetAllValues())
		{
			_drawables.push_back(_actor->GetDrawable());
			std::cout << _actor->GetShapePosition().x << endl;
			std::cout << _actor->GetShapePosition().y << endl;
		}
		return _drawables;
	}
	void SetStop(const bool _stop)
	{
		stop = _stop;
	}
public:
	ActorManager();

public:
	void Init();
	void Update();
};

