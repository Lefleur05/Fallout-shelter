#include "BuildMenu.h"
#include "GameWindow.h"
#include "InputManager.h"
#include "HUD.h"
#include "Macro.h"
#include "TextureManager.h"
#include "TextWidget.h"

BuildMenu::BuildMenu()
{
	backGround = vector<Drawable*>();
	frameMenu = nullptr;
	canvas = nullptr;
	closedBuildMEnu = false;
	Init();
}

void BuildMenu::Init()
{
	InitBackGround();
	InitButtons();
	canvas->SetVisibilityStatus(false);
}

void BuildMenu::Update()
{
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

void BuildMenu::UpdateWindow()
{
	WINDOW->clear(Color(104, 197, 254));

	for (Drawable* _drawable: backGround)
	{
		WINDOW->draw(*_drawable);
	}
	WINDOW->draw(*frameMenu->GetShape());

	for (Widget* _widget : canvas->GetUiWidgets())
	{
		WINDOW->draw(*_widget->GetDrawable());
	}

	WINDOW->display();
}

void BuildMenu::InitBackGround()
{
	frameMenu = new ShapeObject(ShapeData(Vector2f(WINDOW_SIZE / 2.0f), Vector2f(WINDOW_SIZE.x / 100.0f * 90.0f, WINDOW_SIZE.y / 100.0f * 70.0f)));
	SetOriginAtMiddle(frameMenu->GetShape());

	frameMenu->GetShape()->setFillColor(Color(0, 0, 0,175));
	frameMenu->GetShape()->setOutlineThickness(10.0f);
	frameMenu->GetShape()->setOutlineColor(Color::Green);
}

void BuildMenu::InitButtons()
{
	canvas = new Canvas("BuildMenu");

	#pragma region CloseButton
	float _sizeX = WINDOW_SIZE.x / 100.0f * 10.0f;
	float _sizeY = WINDOW_SIZE.x / 100.0f * 5.0f;

	float _posX = WINDOW_SIZE.x / 100.0f * 80.0f;
	float _posY =WINDOW_SIZE.y / 100.0f * 86.0f;

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

	float _sizeXInMenu = frameMenu->GetShapeSize().x / 3.5f;
	float _sizeYInMenu = frameMenu->GetShapeSize().y / 2.5f;

	#pragma region _buttonElevator
	Button* _buttonElevator = new Button(ShapeData(Vector2f(WINDOW_SIZE.x / 100.0f * 20.5f, WINDOW_SIZE.y / 100.0f * 33.0f), Vector2f(_sizeXInMenu, _sizeYInMenu)), ButtonData());
	_buttonElevator->GetData().releasedCallback = [&]()
	{
		//cout << "_buttonElevator" << endl;
	};

	_buttonElevator->GetObject()->GetShape()->setFillColor(Color(0, 0, 0, 175));
	_buttonElevator->GetObject()->GetShape()->setOutlineThickness(5.0f);
	_buttonElevator->GetObject()->GetShape()->setOutlineColor(Color::Green);

	canvas->AddWidget(_buttonElevator);

	Vector2f _position = Vector2f(WINDOW_SIZE.x / 100.0f * 17.0f, WINDOW_SIZE.y / 100.0f * 30.0f);
	TextWidget* _elevator = new TextWidget(TextData("Elevator", _position, "Overseer_Italic.otf", 30, Color::Green));

	canvas->AddWidget(_elevator);

	#pragma endregion

	#pragma region _buttonLivingQuarters
	Button* _buttonLivingQuarters = new Button(ShapeData(Vector2f(WINDOW_SIZE.x / 100.0f * 20.5f, WINDOW_SIZE.y / 100.0f * 67.0f), Vector2f(_sizeXInMenu, _sizeYInMenu)), ButtonData());
	_buttonLivingQuarters->GetData().releasedCallback = [&]()
	{
		//cout << "_buttonLivingQuarters" << endl;
	};
	_buttonLivingQuarters->GetObject()->GetShape()->setFillColor(Color(0, 0, 0, 175));
	_buttonLivingQuarters->GetObject()->GetShape()->setOutlineThickness(5.0f);
	_buttonLivingQuarters->GetObject()->GetShape()->setOutlineColor(Color::Green);

	canvas->AddWidget(_buttonLivingQuarters);

	_position = Vector2f(WINDOW_SIZE.x / 100.0f * 14.0f, WINDOW_SIZE.y / 100.0f * 64.5f);
	TextWidget* _livingQuarters = new TextWidget(TextData("Living Quarters", _position, "Overseer_Italic.otf", 30, Color::Green));

	canvas->AddWidget(_livingQuarters);

	#pragma endregion

	#pragma region _buttonGenerator
	Button* _buttonGenerator = new Button(ShapeData(Vector2f(WINDOW_SIZE.x / 100.0f * 50.0f, WINDOW_SIZE.y / 100.0f * 33.0f), Vector2f(_sizeXInMenu, _sizeYInMenu)), ButtonData());
	_buttonGenerator->GetData().releasedCallback = [&]()
	{
		//cout << "_buttonGenerator" << endl;
	};
	_buttonGenerator->GetObject()->GetShape()->setFillColor(Color(0, 0, 0, 175));
	_buttonGenerator->GetObject()->GetShape()->setOutlineThickness(5.0f);
	_buttonGenerator->GetObject()->GetShape()->setOutlineColor(Color::Green);

	canvas->AddWidget(_buttonGenerator);

	_position = Vector2f(WINDOW_SIZE.x / 100.0f * 45.5f, WINDOW_SIZE.y / 100.0f * 30.0f);
	TextWidget* _generator = new TextWidget(TextData("Generator", _position, "Overseer_Italic.otf", 30, Color::Green));

	canvas->AddWidget(_generator);

	#pragma endregion

	#pragma region _buttonWaterTreatement
	Button* _buttonWaterTreatement = new Button(ShapeData(Vector2f(WINDOW_SIZE.x / 100.0f * 50.0f, WINDOW_SIZE.y / 100.0f * 67.0f), Vector2f(_sizeXInMenu, _sizeYInMenu)), ButtonData());
	_buttonWaterTreatement->GetData().releasedCallback = [&]()
	{
		//cout << "_buttonWaterTreatement" << endl;
	};
	_buttonWaterTreatement->GetObject()->GetShape()->setFillColor(Color(0, 0, 0, 175));
	_buttonWaterTreatement->GetObject()->GetShape()->setOutlineThickness(5.0f);
	_buttonWaterTreatement->GetObject()->GetShape()->setOutlineColor(Color::Green);

	canvas->AddWidget(_buttonWaterTreatement);


	_position = Vector2f(WINDOW_SIZE.x / 100.0f * 42.5f, WINDOW_SIZE.y / 100.0f * 64.5f);
	TextWidget* _waterTreatement = new TextWidget(TextData("Water Treatement", _position, "Overseer_Italic.otf", 30, Color::Green));

	canvas->AddWidget(_waterTreatement);

	#pragma endregion

	#pragma region _buttonDiner
	Button* _buttonDiner = new Button(ShapeData(Vector2f(WINDOW_SIZE.x / 100.0f * 79.5f, WINDOW_SIZE.y / 100.0f * 33.0f), Vector2f(_sizeXInMenu, _sizeYInMenu)), ButtonData());
	_buttonDiner->GetData().releasedCallback = [&]()
	{
		//cout << "_buttonDiner" << endl;
	};
	_buttonDiner->GetObject()->GetShape()->setFillColor(Color(0, 0, 0, 175));
	_buttonDiner->GetObject()->GetShape()->setOutlineThickness(5.0f);
	_buttonDiner->GetObject()->GetShape()->setOutlineColor(Color::Green);

	canvas->AddWidget(_buttonDiner);

	_position = Vector2f(WINDOW_SIZE.x / 100.0f * 77.5f, WINDOW_SIZE.y / 100.0f * 30.0f);
	TextWidget* _diner = new TextWidget(TextData("Diner", _position, "Overseer_Italic.otf", 30, Color::Green));

	canvas->AddWidget(_diner);

	#pragma endregion

}
