#include "ExpeditionMenu.h"
#include "Macro.h"
#include "GameWindow.h"
#include "InputManager.h"

ExpeditionMenu::ExpeditionMenu()
{
	villagerInfoMenu = nullptr;
	backGround = vector<Drawable*>();
	humanExpedition = nullptr;
	closedBuildMEnu = false;

	Init();
}

void ExpeditionMenu::Init()
{
	canvas = new Canvas("ExpeditionMenu");
	InitBackGround();
	InitButtons();
	InitHumanExpedition();
}

void ExpeditionMenu::InitBackGround()
{
	frameMenu = new ShapeObject(ShapeData(Vector2f(WINDOW_SIZE / 2.0f), Vector2f(WINDOW_SIZE.x / 100.0f * 90.0f, WINDOW_SIZE.y / 100.0f * 70.0f)));
	SetOriginAtMiddle(frameMenu->GetShape());

	frameMenu->GetShape()->setFillColor(Color(0, 0, 0, 175));
	frameMenu->GetShape()->setOutlineThickness(10.0f);
	frameMenu->GetShape()->setOutlineColor(Color::Green);

}

void ExpeditionMenu::InitButtons()
{
}

void ExpeditionMenu::InitHumanExpedition()
{
	villagerInfoMenu= new VillagerInfoMenu();
	humanExpedition = villagerInfoMenu->Update();
}

void ExpeditionMenu::Update()
{
	while (WINDOW->isOpen())
	{
		InputManager::GetInstance().Update(*WINDOW);

		if (closedBuildMEnu)
		{
			canvas->SetVisibilityStatus(false);
			return;
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

	for (Widget* _widget : canvas->GetUiWidgets())
	{
		WINDOW->draw(*_widget->GetDrawable());
	}

	WINDOW->display();
}
