#include "VillagerInfoMenu.h"
#include "Macro.h"
#include "GameWindow.h"
#include "PlayerBunker.h"
#include "InputManager.h"
#include "TextureManager.h"
#include "HUD.h"

VillagerInfoMenu::VillagerInfoMenu()
{

	backGround = vector<Drawable*>();
	villagerList = vector<ShapeObject*>();
	frameMenu = nullptr;
	canvas = nullptr;
	closedBuildMEnu = false;
	scrole = 0;

	Init();
}

VillagerInfoMenu::~VillagerInfoMenu()
{
}

void VillagerInfoMenu::Init()
{
	InitBackGround();
	InitVillagerList();
	InitButtons();
	canvas->SetVisibilityStatus(false);
}

void VillagerInfoMenu::InitBackGround()
{
	frameMenu = new ShapeObject(ShapeData(Vector2f(WINDOW_SIZE / 2.0f), Vector2f(WINDOW_SIZE.x / 100.0f * 90.0f, WINDOW_SIZE.y / 100.0f * 70.0f)));
	SetOriginAtMiddle(frameMenu->GetShape());

	frameMenu->GetShape()->setFillColor(Color(0, 0, 0, 175));
	frameMenu->GetShape()->setOutlineThickness(10.0f);
	frameMenu->GetShape()->setOutlineColor(Color::Green);
}

void VillagerInfoMenu::InitVillagerList()
{
	for (int _i = 0; _i < PLAYERBUNKER->GetAllHuman().size(); _i++)
	{
		villagerList.push_back(new ShapeObject(ShapeData(Vector2f(WINDOW_SIZE.x / 100.0f * 50.0f, WINDOW_SIZE.y / 100.0f * 20.0f), Vector2f(0.0f, 0.0f))));
		if (_i%2==0)
		{
			villagerList[_i]->GetShape()->setFillColor(Color::Green);
		}
	}
}

void VillagerInfoMenu::InitButtons()
{
	canvas = new Canvas("BuildMenu");

#pragma region CloseButton
	float _sizeX = WINDOW_SIZE.x / 100.0f * 10.0f;
	float _sizeY = WINDOW_SIZE.x / 100.0f * 5.0f;

	float _posX = WINDOW_SIZE.x / 100.0f * 80.0f;
	float _posY = WINDOW_SIZE.y / 100.0f * 86.0f;

	Button* _closeBuildMenu = new Button(ShapeData(Vector2f(_posX, _posY), Vector2f(_sizeX, _sizeY)), ButtonData());

	_closeBuildMenu->GetData().releasedCallback = [&]()
	{
		cout << "close" << endl;
		closedBuildMEnu = true;
	};

	TextureManager::GetInstance().Load(_closeBuildMenu->GetObject()->GetShape(), "Assets/Texture/Button_close.png");

	_closeBuildMenu->GetObject()->GetShape()->setFillColor(Color::Green);

	canvas->AddWidget(_closeBuildMenu);

#pragma endregion
}

void VillagerInfoMenu::Update()
{
	// Quand tu scrolle la valeur scrole augment ou descend 
	// sa affiche les valeur qui on comme index scrole, scrole+1 et scrole +2
	// 3 possition predefini;
	canvas->SetVisibilityStatus(true);

	while (WINDOW->isOpen())
	{
		InputManager::GetInstance().Update(*WINDOW);

		if (closedBuildMEnu)
		{
			closedBuildMEnu = false;
			canvas->SetVisibilityStatus(false);
			break;
		}
		UpdateWindow();
	}
}

void VillagerInfoMenu::UpdateWindow()
{
	WINDOW->clear(Color(104, 197, 254));

	for (Drawable* _drawable : backGround)
	{
		WINDOW->draw(*_drawable);
	}
	WINDOW->draw(*frameMenu->GetShape());

	for (Widget* _widget : canvas->GetUiWidgets())
	{
		WINDOW->draw(*_widget->GetDrawable());
	}

	if (scrole< villagerList.size()-3)
	{
		WINDOW->draw(*villagerList[scrole]->GetShape());
		WINDOW->draw(*villagerList[scrole+1]->GetShape());
		WINDOW->draw(*villagerList[scrole+2]->GetShape());
	}

	WINDOW->display();
}
