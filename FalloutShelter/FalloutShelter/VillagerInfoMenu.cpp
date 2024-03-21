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
		villagerList.push_back(new ShapeObject(ShapeData(Vector2f(0.0f, 0.0f), Vector2f(WINDOW_SIZE.x / 100.0f * 85.0f, WINDOW_SIZE.y / 100.0f * 20.0f))));
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

void VillagerInfoMenu::Set3VillagerInfoPosition()
{
	vector<Vector2f> _position = {
		Vector2f(WINDOW_SIZE.x / 100.0f * 7.5f,WINDOW_SIZE.y / 100.0f * 17.5f),
		Vector2f(WINDOW_SIZE.x / 100.0f * 7.5f,WINDOW_SIZE.y / 100.0f * 40.0f),
		Vector2f(WINDOW_SIZE.x / 100.0f * 7.5f,WINDOW_SIZE.y / 100.0f * 62.5f),
	};

	villagerList[scrole]->SetShapePosition(_position[0]);
	villagerList[scrole + 1]->SetShapePosition(_position[1]);
	villagerList[scrole + 2]->SetShapePosition(_position[2]);
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

	/*	Event _event;
		while (WINDOW->pollEvent(_event))
		{
			if (scrole < villagerList.size() - 3);

			if (_event.type == Event::MouseWheelScrolled)
			{
				if (_event.mouseWheelScroll.wheel == Mouse::VerticalWheel)
				{
					cout << "mouse x: " << _event.mouseWheelScroll.x << endl;
				}
			}
		}*/
		


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
		Set3VillagerInfoPosition();

		WINDOW->draw(*villagerList[scrole]->GetShape());
		WINDOW->draw(*villagerList[scrole + 1]->GetShape());
		WINDOW->draw(*villagerList[scrole + 2]->GetShape());
	}

	WINDOW->display();
}
