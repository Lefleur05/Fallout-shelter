#include "ExpeditionMenu.h"
#include "Macro.h"
#include "GameWindow.h"
#include "InputManager.h"
#include "TextureManager.h"

ExpeditionMenu::ExpeditionMenu()
{
	villagerInfoMenu = nullptr;
	backGround = vector<Drawable*>();
	frameMenu = nullptr;
	frameBackgroundItem = nullptr;
	humanDraw = nullptr;
	humanExpedition = nullptr;
	frameBackgroundEvent = nullptr;
	capsuleCount = nullptr;
	closedBuildMEnu = false;
	capsuleCountint = 0;

	Init();
}

void ExpeditionMenu::Init()
{
	canvas = new Canvas("ExpeditionMenu");
	InitBackGround();
	InitButtons();
	InitRessource();
}

void ExpeditionMenu::InitBackGround()
{
	InitframeMenu();
	InitframeBackgroundItem();
	IniframeBackgroundEvent();
}

void ExpeditionMenu::InitButtons()
{
	InitCloseButton();
	InitItemsButton();
	InitEventButton();
}

void ExpeditionMenu::InitCloseButton()
{
#pragma region CloseButton
	float _sizeX = WINDOW_SIZE.x / 100.0f * 10.0f;
	float _sizeY = WINDOW_SIZE.x / 100.0f * 5.0f;

	float _posX = WINDOW_SIZE.x / 100.0f * 80.0f;
	float _posY = WINDOW_SIZE.y / 100.0f * 86.0f;

	Button* _closeBuildMenu = new Button(ShapeData(Vector2f(_posX, _posY), Vector2f(_sizeX, _sizeY)), ButtonData());

	_closeBuildMenu->GetData().releasedCallback = [&]()
	{
		//cout << "close" << endl;
		closedBuildMEnu = true;
	};

	TextureManager::GetInstance().Load(_closeBuildMenu->GetObject()->GetShape(), "Assets/Texture/Button_close.png");

	_closeBuildMenu->GetObject()->GetShape()->setFillColor(Color::Green);

	canvas->AddWidget(_closeBuildMenu);

#pragma endregion
}

void ExpeditionMenu::InitItemsButton()
{
	float _sizeX = WINDOW_SIZE.x / 100.0f * 7.5f;
	float _sizeY = WINDOW_SIZE.x / 100.0f * 3.75f;

	float _posX = WINDOW_SIZE.x / 100.0f * 15.0f;
	float _posY = WINDOW_SIZE.y / 100.0f * 65.0f;

	Button* _items = new Button(ShapeData(Vector2f(_posX, _posY), Vector2f(_sizeX, _sizeY)), ButtonData());

	_items->GetData().releasedCallback = [&]()
	{
		//cout << "Open more Items " << endl;
	};

	TextureManager::GetInstance().Load(_items->GetObject()->GetShape(), "Assets/Texture/Items.png");

	_items->GetObject()->GetShape()->setFillColor(Color::Green);

	canvas->AddWidget(_items);
}

void ExpeditionMenu::InitEventButton()
{
	float _sizeX = WINDOW_SIZE.x / 100.0f * 7.5f;
	float _sizeY = WINDOW_SIZE.x / 100.0f * 3.75f;

	float _posX = WINDOW_SIZE.x / 100.0f * 45.0f;
	float _posY = WINDOW_SIZE.y / 100.0f * 20.0f;

	Button* _event = new Button(ShapeData(Vector2f(_posX, _posY), Vector2f(_sizeX, _sizeY)), ButtonData());

	_event->GetData().releasedCallback = [&]()
	{
		//cout << "Open more Event " << endl;
	};

	TextureManager::GetInstance().Load(_event->GetObject()->GetShape(), "Assets/Texture/Event.png");

	_event->GetObject()->GetShape()->setFillColor(Color::Green);

	canvas->AddWidget(_event);
}

void ExpeditionMenu::InitframeMenu()
{
	frameMenu = new ShapeObject(ShapeData(Vector2f(WINDOW_SIZE / 2.0f), Vector2f(WINDOW_SIZE.x / 100.0f * 90.0f, WINDOW_SIZE.y / 100.0f * 70.0f)));
	SetOriginAtMiddle(frameMenu->GetShape());

	frameMenu->GetShape()->setFillColor(Color(0, 0, 0, 175));
	frameMenu->GetShape()->setOutlineThickness(10.0f);
	frameMenu->GetShape()->setOutlineColor(Color::Green);
}

void ExpeditionMenu::InitframeBackgroundItem()
{
	frameBackgroundItem = new ShapeObject(ShapeData(Vector2f(WINDOW_SIZE.x / 2.0f, WINDOW_SIZE.y / 100.0f * 72.5f), Vector2f(WINDOW_SIZE.x / 100.0f * 80.0f, WINDOW_SIZE.y / 100.0f * 15.0f)));
	SetOriginAtMiddle(frameBackgroundItem->GetShape());

	frameBackgroundItem->GetShape()->setFillColor(Color::Transparent);
	frameBackgroundItem->GetShape()->setOutlineThickness(5.0f);
	frameBackgroundItem->GetShape()->setOutlineColor(Color::Green);
}

void ExpeditionMenu::IniframeBackgroundEvent()
{
	frameBackgroundEvent = new ShapeObject(ShapeData(Vector2f(WINDOW_SIZE.x / 100.0f * 65.0f, WINDOW_SIZE.y / 100.0f * 40.0f), Vector2f(WINDOW_SIZE.x / 100.0f * 50.0f, WINDOW_SIZE.y / 100.0f * 40.0f)));
	SetOriginAtMiddle(frameBackgroundEvent->GetShape());

	frameBackgroundEvent->GetShape()->setFillColor(Color::Transparent);
	frameBackgroundEvent->GetShape()->setOutlineThickness(5.0f);
	frameBackgroundEvent->GetShape()->setOutlineColor(Color::Green);
}

void ExpeditionMenu::InitRessource()
{
	Vector2f _sizeIcon = Vector2f(50.0f, 50.0f);

#pragma region Capsule/Money

	Vector2f _position = Vector2f(WINDOW_SIZE.x / 100.0f * 20.0f, WINDOW_SIZE.y / 100.0f * 57.5f);
	capsuleCount = new TextWidget(TextData(to_string(capsuleCountint), _position, "Overseer_Italic.otf", 30, Color::Green));
	canvas->AddWidget(capsuleCount);

	Vector2f _positionIcon = Vector2f(WINDOW_SIZE.x / 100.0f *17.5f, WINDOW_SIZE.y / 100.0f * 60.0f);

	ShapeWidget* _capsule = new ShapeWidget(ShapeData(_positionIcon, _sizeIcon, "Icon/Capsule_Icon.png"));
	canvas->AddWidget(_capsule);

#pragma endregion
}

void ExpeditionMenu::HumanExpedition()
{
	/*villagerInfoMenu= new VillagerInfoMenu();
	villagerInfoMenu->SetBackGround(backGround);
	humanExpedition = villagerInfoMenu->Update();*/

	humanDraw = new ShapeObject(ShapeData(Vector2f(WINDOW_SIZE.x / 100.0f * 25.0f, WINDOW_SIZE.y / 100.0f*35.0f), Vector2f(WINDOW_SIZE.x / 100.0f * 20.0f, WINDOW_SIZE.y / 100.0f * 45.0f)));
	SetOriginAtMiddle(humanDraw->GetShape());
	TextureManager::GetInstance().Load(humanDraw, "Villager.png");	
}

void ExpeditionMenu::Update()
{
	closedBuildMEnu = false;
	canvas->SetVisibilityStatus(true);

	while (WINDOW->isOpen())
	{
		InputManager::GetInstance().Update(*WINDOW);

		if (closedBuildMEnu)
		{
			canvas->SetVisibilityStatus(false);
			return;
		}

		if (humanExpedition == nullptr)
		{
			HumanExpedition();
		}

		UpdateWindow();
	}
}

void ExpeditionMenu::UpdateWindow()
{
	WINDOW->clear(Color(104, 197, 254));

	for (Drawable* _drawable : backGround)
	{
		WINDOW->draw(*_drawable);
	}
	WINDOW->draw(*frameMenu->GetShape());
	WINDOW->draw(*frameBackgroundItem->GetShape());
	WINDOW->draw(*frameBackgroundEvent->GetShape());



	if (humanDraw)
	{
		WINDOW->draw(*humanDraw->GetShape());
	}

	for (Widget* _widget : canvas->GetUiWidgets())
	{
		WINDOW->draw(*_widget->GetDrawable());
	}



	WINDOW->display();
}
