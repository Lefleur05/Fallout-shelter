#include "GameWindow.h"

GameWindow::GameWindow()
{
	window = new RenderWindow(VideoMode(1200, 800), "Fallout Shelter");
	windowSize = Vector2f(1200, 800.0f);
}

GameWindow::~GameWindow()
{
	delete window;
}
