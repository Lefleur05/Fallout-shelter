#include "VillagerInfoMenu.h"
#include "Macro.h"
#include "GameWindow.h"
#include "PlayerBunker.h"
#include "InputManager.h"
#include "TextureManager.h"
#include "HUD.h"

VillagerInfoMenu::VillagerInfoMenu()
{
	handle = nullptr;
	backGround = vector<Drawable*>();
	villagerInfo = new VillagerList();
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
	InitButtons();
	InitScrollBar();
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

void VillagerInfoMenu::InitScrollBar()
{
	const float _windowOneThirdX = WINDOW_SIZE.x / 100.0f* 94.0f;
	const Vector2f& _scrollSize = Vector2f(0.0f, 0.0f);

	handle = new ScrollBar(ShapeData(Vector2f(_windowOneThirdX, 225.0f), _scrollSize, ""),100, [&](bool _scrolltype) { ComputeScroll(villagerInfo, _scrolltype); });
	canvas->AddWidget(handle);
}

void VillagerList::Set3VillagerInfoPosition(const int& _scrole)
{
	vector<float> _positionY = {
		WINDOW_SIZE.y / 100.0f * 17.5f,
		WINDOW_SIZE.y / 100.0f * 40.0f,
		WINDOW_SIZE.y / 100.0f * 62.5f,
	};

	villagerList[_scrole]->SetPositionY(_positionY[0]);
	villagerList[_scrole+1]->SetPositionY(_positionY[1]);
	villagerList[_scrole + 2]->SetPositionY(_positionY[2]);
}

void VillagerList::UpdateVillagerList()
{
	villagerList = vector<VillagerInfo*>();
	Init();
}
void VillagerInfoMenu::Update()
{
	// Quand tu scrolle la valeur scrole augment ou descend 
	// sa affiche les valeur qui on comme index scrole, scrole+1 et scrole +2
	// 3 possition predefini;
	canvas->SetVisibilityStatus(true);
	closedBuildMEnu = false;
	villagerInfo->UpdateVillagerList();
	handle->SetScrollAmount(PLAYERBUNKER->GetAllHuman().size() - 2);

	while (WINDOW->isOpen())
	{
		InputManager::GetInstance().Update(*WINDOW);

		if (closedBuildMEnu)
		{
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

	if (scrole< villagerInfo->GetVillagerList().size()-2)
	{
		villagerInfo->Set3VillagerInfoPosition(scrole);

		for (Drawable* _drawable: villagerInfo->GetVillagerList()[scrole]->GetDrawables())
		{
			WINDOW->draw(*_drawable);
		}

		for (Drawable* _drawable : villagerInfo->GetVillagerList()[scrole+1]->GetDrawables())
		{
			WINDOW->draw(*_drawable);
		}

		for (Drawable* _drawable : villagerInfo->GetVillagerList()[scrole+2]->GetDrawables())
		{
			WINDOW->draw(*_drawable);
		}
		//cout << scrole << endl;
	}

	WINDOW->display();
}

VillagerList::VillagerList()
{
	villagerList = vector<VillagerInfo*>();
	Init();
}

void VillagerList::Init()
{
	int _index = 0;
	for (int _i = 0; _i < PLAYERBUNKER->GetAllHuman().size(); _i++)
	{
		villagerList.push_back(new VillagerInfo(PLAYERBUNKER->GetAllHuman()[_i]));
		villagerList[_i]->GetVillagerInfoShape()->GetShape()->setFillColor(Color(0,128,0));// vert fonc�
		if (_index==1)
		{
			villagerList[_i]->GetVillagerInfoShape()->GetShape()->setFillColor(Color::Green);
		}
		if (_index==2)
		{
			villagerList[_i]->GetVillagerInfoShape()->GetShape()->setFillColor(Color::Red);
			_index = -1;
		}
		_index++;
	}
}

void VillagerInfoMenu::ComputeScroll(VillagerList* _data, const bool _scrollType)
{
	scrole += _scrollType ? -1 : 1;

	scrole = scrole < 0 ? 0 : scrole;

	if (scrole+2 >= _data->GetVillagerList().size())
	{
		scrole = scrole-1;
	}
	//cout << scrole << endl;
}

VillagerInfo::VillagerInfo(Human* _human)
{
	villagerInfoShape = nullptr;
	villagerInfoText = vector<TextWidget*>();
	Init(_human);
}


void VillagerInfo::Init(Human* _human)
{
	villagerInfoShape = new ShapeObject(ShapeData(Vector2f(WINDOW_SIZE.x / 100.0f * 7.5f, 0.0f), Vector2f(WINDOW_SIZE.x / 100.0f * 85.0f, WINDOW_SIZE.y / 100.0f * 20.0f)));

#pragma region textStat

	StatsHuman* stats = _human->GetStats();
	CreateTextStat(stats->strength, 50.0f);
	CreateTextStat(stats->perception, 50.0f);
	CreateTextStat(stats->endurance, 50.0f);
	CreateTextStat(stats->charism, 50.0f);
	CreateTextStat(stats->agility, 50.0f);
	CreateTextStat(stats->luck, 50.0f);

#pragma endregion
}

void VillagerInfo::CreateTextStat(const int& _state, const float& _positionX)
{
	TextWidget* _infoStat = new TextWidget(TextData(to_string(_state), Vector2f(WINDOW_SIZE.x/100.0f* _positionX, 0.0f)));
	villagerInfoText.push_back(_infoStat);
}

void VillagerInfo::SetPositionY(const float& _positionY)
{
	villagerInfoShape->SetShapePosition(Vector2f(villagerInfoShape->GetShapePosition().x, _positionY));

	for (TextWidget* _text : villagerInfoText)
	{
		_text->GetObject()->SetShapePosition(Vector2f(_text->GetObject()->GetShapePosition().x, _positionY));
	}
}
