#include "TitleMenu.h"
#include "GameWindow.h"
#include "TextureManager.h"
#include "InputManager.h"
#include "HUD.h"
#include "Macro.h"

TitleMenu::TitleMenu()
{
	backGround = nullptr;
	canvas = nullptr;
	launchGame = false;

	Init();
}

TitleMenu::~TitleMenu()
{
	delete backGround;
}

void TitleMenu::Init()
{
	InitBackGround();
	InitButton();
}

void TitleMenu::InitBackGround()
{
	backGround = new RectangleShape(WINDOW_SIZE);
	TextureManager::GetInstance().Load(backGround, "Assets/Texture/FalloutShelterMenu.jpg");
}

void TitleMenu::InitButton()
{
	canvas = new Canvas("TitleMenu");

	float _sizeX = WINDOW_SIZE.x / 100.0f * 27.5f;
	float _sizeY = WINDOW_SIZE.x / 100.0f * 6.0f;

	Button* _launchGame = new Button(ShapeData(Vector2f(WINDOW_SIZE.x / 100.0f * 50.0, WINDOW_SIZE.y / 100.0f * 80.7f), Vector2f(_sizeX, _sizeY)), ButtonData());

	SetOriginAtMiddle(_launchGame->GetObject()->GetShape());	
	_launchGame->GetObject()->GetShape()->setFillColor(Color::Transparent);

	_launchGame->GetData().releasedCallback = [&]()
	{
		launchGame = true;
	};
	canvas->AddWidget(_launchGame);
}

void TitleMenu::Update()
{
	while (WINDOW->isOpen())
	{
		InputManager::GetInstance().Update(*WINDOW);
		if (launchGame)
		{
			canvas->SetVisibilityStatus(false);
			break;
		}
		UpdateWindow();
	}
}

void TitleMenu::UpdateWindow()
{
	WINDOW->clear();

	WINDOW->draw(*backGround);

	for (Widget* _widget : canvas->GetUiWidgets())
	{
		WINDOW->draw(*_widget->GetDrawable());
	}

	WINDOW->display();
}
