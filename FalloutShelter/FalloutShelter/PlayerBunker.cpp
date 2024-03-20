#include "PlayerBunker.h"

PlayerBunker::PlayerBunker()
{
	playerBunker = new Bunker();
}

PlayerBunker::~PlayerBunker()
{
	delete playerBunker;
}
