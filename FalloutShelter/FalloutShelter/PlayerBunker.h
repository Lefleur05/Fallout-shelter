#pragma once
#include <SFML/Graphics.hpp>
#include "Singleton.h"
#include "Bunker.h"
using namespace sf;

#define PLAYERBUNKER PlayerBunker::GetInstance().GetBunker()

class PlayerBunker : public Singleton<PlayerBunker>
{
	Bunker* playerBunker;

public:
	Bunker* GetBunker() 
	{
		return playerBunker; 
	}
	
public:
	PlayerBunker();
	~PlayerBunker();



};

