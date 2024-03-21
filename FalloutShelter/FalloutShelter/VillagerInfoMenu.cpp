#include "VillagerInfoMenu.h"
#include "Macro.h"
#include "GameWindow.h"
#include "PlayerBunker.h"

VillagerInfoMenu::VillagerInfoMenu()
{

	backGround = vector<Drawable*>();
	villagerList = vector<ShapeObject*>();
	frameMenu = nullptr;
	canvas = nullptr;
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
		//villagerList.push_back(new ShapeObject())
	}
}


void VillagerInfoMenu::Update()
{

	// Quand tu scrolle la valeur scrole augment ou descend 
	// sa affiche les valeur qui on comme index scrole, scrole+1 et scrole +2
	// 3 possition predefini;
}

void VillagerInfoMenu::UpdateWindow()
{
}
