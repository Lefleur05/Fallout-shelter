#include "VillagerInfoMenu.h"
#include "Macro.h"
#include "GameWindow.h"
#include "PlayerBunker.h"
#include "InputManager.h"
#include "TextureManager.h"
#include "HUD.h"

#define VILLAGER_HEAD_PATH "VillagerHead.png"

VillagerInfo::VillagerInfo(Human* _human)
{
	villagerInfoShape = nullptr;
	villagerHead = nullptr;
	villagerInfoText = vector<TextWidget*>();
	human = _human;
	Init();
}

void VillagerInfo::Init()
{

	villagerInfoShape = new Button(ShapeData(Vector2f(WINDOW_SIZE.x / 2.0f, -10000.0f), Vector2f(WINDOW_SIZE.x / 100.0f * 85.0f, WINDOW_SIZE.y / 100.0f * 20.0f)));


	InitStats();
	InitVillagerHead();
}

void VillagerInfo::InitStats()
{
	StatsHuman* _stats = human->GetStats();
	CreateTextStat(to_string(_stats->strength), 35.0f);
	CreateTextStat(to_string(_stats->perception), 40.0f);
	CreateTextStat(to_string(_stats->endurance), 45.0f);
	CreateTextStat(to_string(_stats->charism), 50.0f);
	CreateTextStat(to_string(_stats->agility), 55.0f);
	CreateTextStat(to_string(_stats->luck), 60.0f);
	CreateTextStat(to_string(_stats->mentalHealth) + "%", 75.0f);
}

void VillagerInfo::InitVillagerHead()
{
	villagerHead = new ShapeObject(ShapeData(Vector2f(WINDOW_SIZE.x / 100.0f *10.0f, 0.0f), Vector2f(WINDOW_SIZE.x / 100.0f * 10.0f, WINDOW_SIZE.y / 100.0f * 10.0f), VILLAGER_HEAD_PATH));
}

void VillagerInfo::CreateTextStat(const string& _text, const float& _positionX)
{
	TextWidget* _infoStat = new TextWidget(TextData(_text, Vector2f(WINDOW_SIZE.x / 100.0f * _positionX, 0.0f), "Overseer_Italic.otf", 50));
	villagerInfoText.push_back(_infoStat);
}

void VillagerInfo::SetPositionY(const float& _positionY)
{
	villagerInfoShape->SetShapePosition(Vector2f(villagerInfoShape->GetShapePosition().x, _positionY + WINDOW_SIZE.y / 100.0f * 10.0f));
	villagerHead->SetShapePosition(Vector2f(villagerHead->GetShapePosition().x, _positionY+ WINDOW_SIZE.y / 100.0f * 5.5f));

	for (TextWidget* _text : villagerInfoText)
	{
		_text->GetObject()->SetShapePosition(Vector2f(_text->GetObject()->GetShapePosition().x, _positionY+ WINDOW_SIZE.y / 100.0f * 5.5f));
	}
}



VillagerList::VillagerList()
{
	villagerList = vector<VillagerInfo*>();
	Init();
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
	Init();
}

void VillagerList::Init()
{
	for (int _i = 0; _i < PLAYERBUNKER->GetAllHuman().size(); _i++)
	{
		if (villagerList.size()<= _i)
		{
			villagerList.push_back(new VillagerInfo(PLAYERBUNKER->GetAllHuman()[_i]));
			villagerList[_i]->GetVillagerInfoShape()->GetObject()->GetShape()->setFillColor(Color(0, 128, 0));// vert foncé
			if (_i%2 == 0)
			{
				villagerList[_i]->GetVillagerInfoShape()->GetObject()->GetShape()->setFillColor(Color::Green);
			}
			continue;
		}
		villagerList[_i]->SetvillagerInfoText(vector<TextWidget*>());
		villagerList[_i]->InitStats();
	}
}

VillagerInfoMenu::VillagerInfoMenu()
{
	handle = nullptr;
	backGround = vector<Drawable*>();
	villagerInfo = new VillagerList();
	frameMenu = nullptr;
	frameStatName = nullptr;
	canvas = nullptr;
	currentHuman = nullptr;
	closedBuildMEnu = false;
	scrole = 0;

	Init();
}

VillagerInfoMenu::~VillagerInfoMenu()
{
}

void VillagerInfoMenu::Init()
{
	canvas = new Canvas("BuildMenu");
	InitBackGround();
	InitButtons();
	InitScrollBar();
	InitStatsName();


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

void VillagerInfoMenu::InitStatsName()
{

	vector<float> _positionX = {
		WINDOW_SIZE.x / 100.0f * 35.0f,
		WINDOW_SIZE.x / 100.0f * 40.0f,
		WINDOW_SIZE.x / 100.0f * 45.0f,
		WINDOW_SIZE.x / 100.0f * 50.0f,
		WINDOW_SIZE.x / 100.0f * 55.0f,
		WINDOW_SIZE.x / 100.0f * 60.0f,
	};

	vector<string> _name = { "S", "P", "E", "C", "A", "L" };

	TextWidget* _infoStat;

	for (int _i = 0; _i < 6; _i++)
	{
		_infoStat = new TextWidget(TextData(_name[_i], Vector2f(_positionX[_i], WINDOW_SIZE.y / 100.0f * 10.0f), "Overseer_Italic.otf", 50));
		canvas->AddWidget(_infoStat);
	}

	frameStatName = new ShapeObject(ShapeData(Vector2f(WINDOW_SIZE.x / 100.0f * 48.5f, WINDOW_SIZE.y / 100.0f*14.0f), Vector2f(WINDOW_SIZE.x / 100.0f * 30.0f, WINDOW_SIZE.y / 100.0f * 5.0f)));
	SetOriginAtMiddle(frameStatName->GetShape());
	frameStatName->GetShape()->setFillColor(Color::Black);
	frameStatName->GetShape()->setOutlineThickness(5.0f);
	frameStatName->GetShape()->setOutlineColor(Color::Green);

}

void VillagerInfoMenu::InitButtons()
{
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

Human* VillagerInfoMenu::Update()
{
	UpdateInit();

	while (WINDOW->isOpen())
	{
		InputManager::GetInstance().Update(*WINDOW);

		if (closedBuildMEnu)
		{
			canvas->SetVisibilityStatus(false);
			return currentHuman;
		}

		UpdateWindow();
	}
}

void VillagerInfoMenu::UpdateInit()
{
	closedBuildMEnu = false;
	villagerInfo->UpdateVillagerList();
	handle->SetScrollAmount(PLAYERBUNKER->GetAllHuman().size() - 2);
	int _index=0;

	for (VillagerInfo* _villagerInfo : villagerInfo->GetVillagerList())
	{
		if (!_villagerInfo->GetVillagerInfoShape()->GetData().releasedCallback)
		{
			canvas->AddWidget(_villagerInfo->GetVillagerInfoShape());

			_villagerInfo->GetVillagerInfoShape()->GetData().releasedCallback = [&]()
			{
				/*cout << villagerInfo->GetVillagerList()[0] << endl;

				currentHuman = villagerInfo->GetVillagerList()[_index]->human;

				closedBuildMEnu = true;*/
			};
			_index++;
		}
	}
	canvas->SetVisibilityStatus(true);
}

void VillagerInfoMenu::UpdateWindow()
{
	WINDOW->clear(Color(104, 197, 254));

	for (Drawable* _drawable : backGround)
	{
		WINDOW->draw(*_drawable);
	}
	WINDOW->draw(*frameMenu->GetShape());
	WINDOW->draw(*frameStatName->GetShape());

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
	}

	WINDOW->display();
}

void VillagerInfoMenu::ComputeScroll(VillagerList* _data, const bool _scrollType)
{
	scrole += _scrollType ? -1 : 1;

	scrole = scrole < 0 ? 0 : scrole;

	if (scrole+2 >= _data->GetVillagerList().size())
	{
		scrole = scrole-1;
	}
}
