#pragma once
#include <SFML/Graphics.hpp>
#include "Singleton.h"
using namespace sf;

#define WINDOW GameWindow::GetInstance().GetWindow()
#define WINDOW_SIZE GameWindow::GetInstance().GetWindowSize()

class GameWindow : public Singleton<GameWindow>
{
	RenderWindow* window;
	Vector2f windowSize;

public:
	RenderWindow* GetWindow()
	{
		return window;
	}

	Vector2f GetWindowSize()
	{
		return windowSize;
	}

public:
	GameWindow();
	~GameWindow();




};

