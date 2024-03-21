#include "Game.h"
#include "MapManager.h"
#include "GameWindow.h"
#include "HUD.h"
#include "InputManager.h"
#include "Macro.h"
#include "TimerManager.h"
#include "PlayerBunker.h"


#define EMPTY_PROGRESS_BAR "Icon/Empty_Progresse_Bar.png"
#define FILLED_PROGRESS_BAR  "Icon/Filled_Progresse_Bar.png"

Game::Game()
{
	map = nullptr;
	canvas = nullptr;
	titleMenu = nullptr;
	buildMenu = nullptr;
	capsuleCount = nullptr;
	electricityBar = nullptr;

	Init();
}

void Game::Init()
{
	canvas = new Canvas("Button");
	InitMap();
	InitUIInfo();
	DrawHuman();
	//InitButton();
	//InitHuman();
	InitGridNav();
	//InitZombie();
	InitTitleMenu();
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
	capsuleCount = new TextWidget(TextData(to_string(PLAYERBUNKER->GetMoney()), _position, "Overseer_Italic.otf", 30, Color::Green));
	canvas->AddWidget(capsuleCount);

	Vector2f _sizeIcon = Vector2f(50.0f, 50.0f);
	Vector2f _positionIcon = Vector2f(WINDOW_SIZE.x / 100.0f * 87.5f, WINDOW_SIZE.y / 100.0f * 7.5f);

	ShapeWidget* _capsule = new ShapeWidget(ShapeData(_positionIcon, _sizeIcon, "Icon/Capsule_Icon.png"));
	canvas->AddWidget(_capsule);

	#pragma endregion

	#pragma region ProgressBar Electicity

	const Vector2f& _electricityPos = Vector2f(WINDOW_SIZE.x / 100.0f * 25.0f, WINDOW_SIZE.y / 100.0f * 5.0f);
	const Vector2f& _electricitySize = Vector2f(100.0f, 50.0f);

	electricityBar = new ProgressBar(ShapeData(_electricityPos, _electricitySize, EMPTY_PROGRESS_BAR), FILLED_PROGRESS_BAR, ProgressType::PT_RIGHT);

	canvas->AddWidget(electricityBar);
	canvas->AddWidget(electricityBar->GetForeground());


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
	SetOriginAtMiddle(_modeBuildButton->GetObject()->GetShape());
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

void Game::InitZombie()
{
	Zombie* _zombie = new Zombie(ShapeData(Vector2f(100,0),Vector2f(20,60)));
	_zombie->GetShape()->setFillColor(Color::Cyan);
	_zombie->Init();
}

void Game::InitGridNav()
{
	grid = new GridNav(10, 100, Vector2f(50, 50));
}


void Game::Update()
{
	while (WINDOW->isOpen())
	{
		InputManager::GetInstance().Update(*WINDOW);
		TimerManager::GetInstance().Update();
		ActorManager::GetInstance().Update();

		UpdateUIInfo();
		UpdateWindow();
	}
}

void Game::UpdateUIInfo()
{
	capsuleCount->GetObject()->SetText(to_string(PLAYERBUNKER->GetMoney()));
}

void Game::UpdateWindow()
{
	WINDOW->clear();

	DrawMap();
	DrawActor();
	for (Tile* _tile: map->GetGrid()->GetRessourceTiles())
	{
		if (_tile->GetHall()->GetCanvas()->IsVisible())
		{
			for (Widget* _widget : _tile->GetHall()->GetCanvas()->GetUiWidgets())
			{
				WINDOW->draw(*_widget->GetDrawable());
			}
		}	

	}
	for (Widget* _widget : canvas->GetUiWidgets())
	{
		WINDOW->draw(*_widget->GetDrawable());
	}

	WINDOW->display();
}

Vector2f Game::PositionHumanInHall(int _indexX, int _indexY,Vector2f _offset)
{
	Vector2f _position = MapManager::GetInstance().GetCurrent()->GetGrid()->GetAllTiles()[_indexX][_indexY]->GetShape()->getPosition() + _offset;
	return _position;
}

void Game::DrawActor()
{
	for (Drawable* _actorDraw : ActorManager::GetInstance().GetDrawables())
	{
		WINDOW->draw(*_actorDraw);
	}
}

void Game::DrawMap()
{
	for (Drawable* _drawables : MapManager::GetInstance().GetDrawables())
	{
		WINDOW->draw(*_drawables);
	}
}

void Game::InitHuman()
{
	Vector2f _sizeHuman = Vector2f(20, 50);
	Vector2f _offset = Vector2f(20, 50);
	Vector2f _pos = PositionHumanInHall(0, 3, _offset);
	Vector2f _posGenerator = PositionHumanInHall(1, 1, _offset);
	Vector2f _posDinner = PositionHumanInHall(1, 0, _offset);
	Vector2f _posWaterTreatment = PositionHumanInHall(1, 3, _offset);

	for (int i = 0; i < 5; i++)
	{
		Human* _h = new Human(ShapeData(_pos, _sizeHuman));
		_h->Init();
		allHuman.push_back(_h);
		//allHuman[0]->GetShape()->setPosition(_posGenerator);
		_h->GetShape()->setPosition(_posGenerator);
		//_h->GetShape()->setPosition(_posDinner);
		//_h->GetShape()->setPosition(_posWaterTreatment);
	}
}

void Game::DrawHuman()
{
	Vector2f _sizeHuman = Vector2f(20, 50);
	Vector2f _offset = Vector2f(20, 50);
	Vector2f _pos = PositionHumanInHall(0, 3, _offset);
	Vector2f _posGenerator = PositionHumanInHall(1, 1, _offset);
	Vector2f _posDinner = PositionHumanInHall(1, 0, _offset);
	Vector2f _posWaterTreatment = PositionHumanInHall(1, 3, _offset);

	Human* _h = new Human(ShapeData(_pos, _sizeHuman));
	_h->Init();

	Human* _hGenerator = new Human(ShapeData(_posGenerator, _sizeHuman));
	_hGenerator->Init();

	Human* _hDinner = new Human(ShapeData(_posDinner, _sizeHuman));
	_hDinner->Init();

	Human* _hWaterTreatment = new Human(ShapeData(_posWaterTreatment, _sizeHuman));
	_hWaterTreatment->Init();
}
