#include "Game.h"
#include "MapManager.h"
#include "GameWindow.h"
#include "HUD.h"
#include "InputManager.h"
#include "Macro.h"
#include "TextWidget.h"
#include "TimerManager.h"


Game::Game()
{
	playerBunker = nullptr;
	map = nullptr;
	canvas = new Canvas("Button");
	titleMenu = nullptr;
	buildMenu = nullptr;


	Init();
}

void Game::Init()
{
	InitMap();
	InitBunkerPlayer();
	InitUIInfo();
	InitButton();
	InitGridNav();
	InitTitleMenu();
}

void Game::InitBunkerPlayer()
{
	playerBunker = new Bunker();
}

void Game::InitMap()
{
	map = new Map("map");
	map->GetGrid()->GetAllTiles()[0][2]->SetHall(new Hall(HALL_ELEVATOR));
	map->GetGrid()->GetAllTiles()[0][3]->SetHall(new Hall(HALL_DORTOIR));
	map->GetGrid()->GetAllTiles()[1][2]->SetHall(new Hall(HALL_ELEVATOR));
	map->GetGrid()->GetAllTiles()[1][1]->SetHall(new Hall(HALL_GENERATOR));
	map->GetGrid()->GetAllTiles()[1][0]->SetHall(new Hall(HALL_FAST_FOOD));
	map->GetGrid()->GetAllTiles()[1][3]->SetHall(new Hall(HALL_TRAITEMENT_DES_EAUX));
}

void Game::InitUIInfo()
{
	#pragma region Capsule/Money
	Vector2f _position = Vector2f(WINDOW_SIZE.x / 100.0f * 90.0f, WINDOW_SIZE.y / 100.0f * 5.0f);
	TextWidget* _capsuleCount= new TextWidget(TextData(to_string(playerBunker->GetMoney()), _position, "Overseer_Italic.otf", 30, Color::Green));
	canvas->AddWidget(_capsuleCount);


	Vector2f _sizeIcon = Vector2f(50.0f,50.0f);
	Vector2f _positionIcon = Vector2f(WINDOW_SIZE.x / 100.0f * 87.5f, WINDOW_SIZE.y / 100.0f * 7.5f);

	ShapeWidget* _capsule = new ShapeWidget(ShapeData(_positionIcon, _sizeIcon,"Icon/Capsule_Icon.png"));

	canvas->AddWidget(_capsule);

	#pragma endregion
}

void Game::InitButton()
{
	buildMenu = new BuildMenu();

	Button* _modeBuildButton = new Button(ShapeData(Vector2f(WINDOW_SIZE.x / 100.0f * 92.5f, WINDOW_SIZE.y / 100.0f * 90.0f), Vector2f(100.0f, 100.0f)), ButtonData());
	_modeBuildButton->GetData().releasedCallback = [&]()
	{
		canvas->SetVisibilityStatus(false);
		cout << "mode build" << endl;
		buildMenu->SetBackGround(MapManager::GetInstance().GetDrawables());		
		buildMenu->Update();
		canvas->SetVisibilityStatus(true);
	};
	SetOriginAtMiddle(_modeBuildButton->GetObject()->GetShape()),
	TextureManager::GetInstance().Load(_modeBuildButton->GetObject()->GetShape(), "Assets/Texture/Icon/Building_Icon.png");
	_modeBuildButton->GetObject()->GetShape()->setFillColor(Color::Green);
	canvas->AddWidget(_modeBuildButton);


	Button* _modeExplorationButton = new Button(ShapeData(Vector2f(WINDOW_SIZE.x / 100.0f * 7.5f, WINDOW_SIZE.y / 100.0f * 90.0f), Vector2f(100.0f, 100.0f)), ButtonData());
	_modeExplorationButton->GetData().releasedCallback = [&]()
	{
		canvas->SetVisibilityStatus(false);
		cout << "mode Exploration" << endl;
		canvas->SetVisibilityStatus(true);
	};
	SetOriginAtMiddle(_modeExplorationButton->GetObject()->GetShape());
	TextureManager::GetInstance().Load(_modeExplorationButton->GetObject()->GetShape(), "Assets/Texture/Icon/Exploration_Icon.png");
	_modeExplorationButton->GetObject()->GetShape()->setFillColor(Color::Green);
	canvas->AddWidget(_modeExplorationButton);


	Button* _villagerInfoButton = new Button(ShapeData(Vector2f(WINDOW_SIZE.x / 100.0f * 7.5f, WINDOW_SIZE.y / 100.0f * 10.0f), Vector2f(100.0f, 100.0f)), ButtonData());
	_villagerInfoButton->GetData().releasedCallback = [&]()
	{
		canvas->SetVisibilityStatus(false);
		cout << "villager Info" << endl;
		canvas->SetVisibilityStatus(true);
	};
	SetOriginAtMiddle(_villagerInfoButton->GetObject()->GetShape());
	TextureManager::GetInstance().Load(_villagerInfoButton->GetObject()->GetShape(), "Assets/Texture/Icon/Villager_Info_Icon.png");
	_villagerInfoButton->GetObject()->GetShape()->setFillColor(Color::Green);
	canvas->AddWidget(_villagerInfoButton);
}

void Game::InitTitleMenu()
{
	titleMenu = new TitleMenu();
	titleMenu->Update();
}

void Game::InitGridNav()
{
	grid = new GridNav(8, 100, Vector2f(100, 0));
}


void Game::Update()
{
	while (WINDOW->isOpen())
	{
		InputManager::GetInstance().Update(*WINDOW);
		//MapManager::GetInstance().Update();
		TimerManager::GetInstance().Update();


		UpdateWindow();
	}
}

void Game::UpdateWindow()
{
	WINDOW->clear();

	for (Drawable* _drawables: MapManager::GetInstance().GetDrawables())
	{
		WINDOW->draw(*_drawables);
	}

	for (Drawable* _actorDraw : ActorManager::GetInstance().GetDrawables())
	{
		WINDOW->draw(*_actorDraw);
	}

	for (Widget* _widget : canvas->GetUiWidgets())
	{
		WINDOW->draw(*_widget->GetDrawable());
	}


	WINDOW->display();
}
