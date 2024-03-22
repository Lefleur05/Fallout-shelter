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

//#define ZOMBIE_PATH ""

Game::Game()
{
	map = nullptr;
	canvas = nullptr;
	titleMenu = nullptr;
	buildMenu = nullptr;
	villagerInfoMenu = nullptr;
	capsuleCount = nullptr;
	villagerCount = nullptr;
	electricityBar = nullptr;
	foodBar = nullptr;
	waterBar = nullptr;

	Init();
}

void Game::Init()
{
	canvas = new Canvas("Button");
	InitMap();
	InitUIInfo();
	InitButton();
	InitHuman();
	InitButton();
	InitGridNav();
	InitZombie();
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
	Vector2f _sizeIcon = Vector2f(50.0f, 50.0f);

	#pragma region Capsule/Money
	
	Vector2f _position = Vector2f(WINDOW_SIZE.x / 100.0f * 90.0f, WINDOW_SIZE.y / 100.0f * 5.0f);
	capsuleCount = new TextWidget(TextData(to_string(PLAYERBUNKER->GetMoney()), _position, "Overseer_Italic.otf", 30, Color::Green));
	canvas->AddWidget(capsuleCount);

	Vector2f _positionIcon = Vector2f(WINDOW_SIZE.x / 100.0f * 87.5f, WINDOW_SIZE.y / 100.0f * 7.5f);

	ShapeWidget* _capsule = new ShapeWidget(ShapeData(_positionIcon, _sizeIcon, "Icon/Capsule_Icon.png"));
	canvas->AddWidget(_capsule);

	#pragma endregion

	const Vector2f& _progresseBarSize = Vector2f(150.0f, 37.5f);

	#pragma region ProgressBar Electicity
	const Vector2f& _electricityPos = Vector2f(WINDOW_SIZE.x / 100.0f * 25.0f, WINDOW_SIZE.y / 100.0f * 5.0f);

	electricityBar = new ProgressBar(ShapeData(_electricityPos, _progresseBarSize, EMPTY_PROGRESS_BAR), FILLED_PROGRESS_BAR, ProgressType::PT_LEFT, PLAYERBUNKER->GetAllRessource()[0]->GetMaxQuantity());

	canvas->AddWidget(electricityBar);
	canvas->AddWidget(electricityBar->GetForeground());


	_positionIcon = Vector2f(WINDOW_SIZE.x / 100.0f * 17.5f, WINDOW_SIZE.y / 100.0f * 5.0f);

	ShapeWidget* _electricityIcon= new ShapeWidget(ShapeData(_positionIcon, _sizeIcon, "Icon/Electicity_Icon.png"));
	canvas->AddWidget(_electricityIcon);

	#pragma endregion

	#pragma region ProgressBar Food
	const Vector2f& _foodPos = Vector2f(WINDOW_SIZE.x / 100.0f * 50.0f, WINDOW_SIZE.y / 100.0f * 5.0f);

	foodBar = new ProgressBar(ShapeData(_foodPos, _progresseBarSize, EMPTY_PROGRESS_BAR), FILLED_PROGRESS_BAR, ProgressType::PT_LEFT, PLAYERBUNKER->GetAllRessource()[1]->GetMaxQuantity());

	canvas->AddWidget(foodBar);
	canvas->AddWidget(foodBar->GetForeground());


	_positionIcon = Vector2f(WINDOW_SIZE.x / 100.0f * 42.5f, WINDOW_SIZE.y / 100.0f * 5.0f);

	ShapeWidget* _foodIcon = new ShapeWidget(ShapeData(_positionIcon, _sizeIcon, "Icon/Food_Icon.png"));
	canvas->AddWidget(_foodIcon);
	#pragma endregion

	#pragma region ProgressBar Water
	const Vector2f& _waterPos = Vector2f(WINDOW_SIZE.x / 100.0f * 75.0f, WINDOW_SIZE.y / 100.0f * 5.0f);

	waterBar = new ProgressBar(ShapeData(_waterPos, _progresseBarSize, EMPTY_PROGRESS_BAR), FILLED_PROGRESS_BAR, ProgressType::PT_LEFT, PLAYERBUNKER->GetAllRessource()[2]->GetMaxQuantity());

	canvas->AddWidget(waterBar);
	canvas->AddWidget(waterBar->GetForeground());

	_positionIcon = Vector2f(WINDOW_SIZE.x / 100.0f * 67.5f, WINDOW_SIZE.y / 100.0f * 5.0f);

	ShapeWidget* _waterIcon = new ShapeWidget(ShapeData(_positionIcon, _sizeIcon, "Icon/Water_Icon.png"));
	canvas->AddWidget(_waterIcon);
	#pragma endregion
}

void Game::InitButton()
{
	#pragma region _modeBuildButton

	buildMenu = new BuildMenu();
	Button* _modeBuildButton = new Button(ShapeData(Vector2f(WINDOW_SIZE.x / 100.0f * 92.5f, WINDOW_SIZE.y / 100.0f * 92.5f), Vector2f(100.0f, 100.0f)), ButtonData());
	_modeBuildButton->GetData().releasedCallback = [&]()
	{
		for (Human* _human : PLAYERBUNKER->GetAllHuman())
		{
			_human->GetComponent<MovementComponent>()->SetCanMove(false);
		}
		canvas->SetVisibilityStatus(false);
		cout << "mode build" << endl;
		buildMenu->SetBackGround(MapManager::GetInstance().GetDrawables());		
		buildMenu->Update();
		
		for (Human* _human : PLAYERBUNKER->GetAllHuman())
		{
			_human->GetComponent<MovementComponent>()->SetCanMove(true);
		}

		canvas->SetVisibilityStatus(true);
	};

	SetOriginAtMiddle(_modeBuildButton->GetObject()->GetShape());
	TextureManager::GetInstance().Load(_modeBuildButton->GetObject()->GetShape(), "Assets/Texture/Icon/Building_Icon.png");
	_modeBuildButton->GetObject()->GetShape()->setFillColor(Color::Green);
	canvas->AddWidget(_modeBuildButton);
	#pragma endregion

	#pragma region _modeExplorationButton
	Button* _modeExplorationButton = new Button(ShapeData(Vector2f(WINDOW_SIZE.x / 100.0f * 5.0f, WINDOW_SIZE.y / 100.0f * 92.5f), Vector2f(100.0f, 100.0f)), ButtonData());
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
	#pragma endregion

	#pragma region _villagerInfoButton
	villagerInfoMenu = new VillagerInfoMenu();
	Button* _villagerInfoButton = new Button(ShapeData(Vector2f(WINDOW_SIZE.x / 100.0f * 5.0f, WINDOW_SIZE.y / 100.0f * 7.5f), Vector2f(100.0f, 100.0f)), ButtonData());
	_villagerInfoButton->GetData().releasedCallback = [&]()
	{
		canvas->SetVisibilityStatus(false);
		cout << "villager Info" << endl;
		villagerInfoMenu->SetBackGround(MapManager::GetInstance().GetDrawables());
		villagerInfoMenu->Update();
		canvas->SetVisibilityStatus(true);
	};
	SetOriginAtMiddle(_villagerInfoButton->GetObject()->GetShape());
	TextureManager::GetInstance().Load(_villagerInfoButton->GetObject()->GetShape(), "Assets/Texture/Icon/Villager_Info_Icon.png");
	_villagerInfoButton->GetObject()->GetShape()->setFillColor(Color::Green);
	canvas->AddWidget(_villagerInfoButton);

	villagerCount = new TextWidget(TextData(to_string(PLAYERBUNKER->GetAllHuman().size()), Vector2f(WINDOW_SIZE.x / 100.0f * 4.0f, WINDOW_SIZE.y / 100.0f * 4.0f), "Overseer_Italic.otf", 50, Color::Green));
	canvas->AddWidget(villagerCount);

	#pragma endregion
}

void Game::InitTitleMenu()
{
	titleMenu = new TitleMenu();
	titleMenu->Update();
}

void Game::InitGridNav()
{
	grid = new GridNav(10, 50, Vector2f(50, 150));
	//grid->GetNodes()[80]->GetShape()->setFillColor(Color::Red);
}

void Game::InitZombie()
{
	Zombie* _zombie = new Zombie(ShapeData(grid->GetNodes()[99]->GetShapePosition(), Vector2f(20, 60)));
	_zombie->GetComponent<EnemyMovementComponent>()->SetGrid(grid);
	_zombie->GetShape()->setFillColor(Color::Cyan);
	_zombie->Init();
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

	electricityBar->SetValue(PLAYERBUNKER->GetAllRessource()[0]->GetQuantity());
	electricityBar->SetMaxValue(PLAYERBUNKER->GetAllRessource()[0]->GetMaxQuantity());

	foodBar->SetValue(PLAYERBUNKER->GetAllRessource()[1]->GetQuantity());
	foodBar->SetMaxValue(PLAYERBUNKER->GetAllRessource()[1]->GetMaxQuantity());

	waterBar->SetValue(PLAYERBUNKER->GetAllRessource()[2]->GetQuantity());
	waterBar->SetMaxValue(PLAYERBUNKER->GetAllRessource()[2]->GetMaxQuantity());

	
	villagerCount->GetObject()->SetText(to_string(PLAYERBUNKER->GetAllHuman().size()));
}

void Game::UpdateWindow()
{
	WINDOW->clear(Color(104,197,254));

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

	Human* _h = new Human(ShapeData(_pos, _sizeHuman));
	_h->Init();
	//TODO Enlever cette ligne ( ligne de teste , trouver mieux)
	MapManager::GetInstance().GetCurrent()->GetGrid()->GetAllTiles()[0][3]->GetHall()->AddHumanInHall(_h);

	Human* _h1 = new Human(ShapeData(_pos, _sizeHuman));
	_h1->Init();
	//TODO Enlever cette ligne ( ligne de teste , trouver mieux)
	MapManager::GetInstance().GetCurrent()->GetGrid()->GetAllTiles()[0][3]->GetHall()->AddHumanInHall(_h1);

	Human* _hGenerator = new Human(ShapeData(_posGenerator, _sizeHuman));
	_hGenerator->Init();
	MapManager::GetInstance().GetCurrent()->GetGrid()->GetAllTiles()[1][1]->GetHall()->AddHumanInHall(_hGenerator);


	Human* _hDinner = new Human(ShapeData(_posDinner, _sizeHuman));
	_hDinner->Init();
	MapManager::GetInstance().GetCurrent()->GetGrid()->GetAllTiles()[1][0]->GetHall()->AddHumanInHall(_hDinner);


	Human* _hWaterTreatment = new Human(ShapeData(_posWaterTreatment, _sizeHuman));
	_hWaterTreatment->Init();
	MapManager::GetInstance().GetCurrent()->GetGrid()->GetAllTiles()[1][3]->GetHall()->AddHumanInHall(_hWaterTreatment);

}
