#include "Hall.h"
#include "PlayerBunker.h"
#include "GameWindow.h"
#include "Macro.h"
#include "HUD.h"
#include "TextureManager.h"
#include "MapManager.h"

Hall::Hall(HallType _type)
{
	type = _type;
	hallSize = 1;
	hallLV = 1;
	humans = vector<Human*>();
	canvas = nullptr;
	timerRessource = nullptr;
	quantity = 0;
}

void Hall::Init(Shape* _shape, Vector2f _size)
{
	switch (type)
	{
	case HALL_DOOR:
		return;
	case HALL_ELEVATOR:
		return;
	default:
		break;
	}

	InitButton(_shape, _size);
	InitTimer();
	InitQuantity();
}

void Hall::InitQuantity()
{
	quantity = humans.size() * 2;

	int _index = -1;
	switch (type)
	{
	case HALL_GENERATOR:
		_index = 0;
		break;
	case HALL_FAST_FOOD:
		_index = 1;
		break;
	case HALL_TRAITEMENT_DES_EAUX:
		_index = 2;
		break;
	default:
		break;
	}
	if (_index > -1)
	{
		PLAYERBUNKER->GetAllRessource()[_index]->SetMaxQuantity(PLAYERBUNKER->GetAllRessource()[_index]->GetMaxQuantity() + 25);
	}
}

void Hall::InitTimer()
{
	function<void()> _function = [&]()
	{
		cout << "Timer Begin" << endl;
		cout << quantity << endl << endl;
		DrawButton();
		timerRessource->Pause();
	};

	timerRessource = new Timer(_function, seconds(5), true, true);
}

void Hall::InitButton(Shape* _shape, Vector2f _size)
{
	canvas = new Canvas("ButtonRessource");
	Vector2f _position = Vector2f(_shape->getPosition().x+ _size.x/2.0f, _shape->getPosition().y + _size.y / 2.0f);
	Button* _buttonRessource = new Button(ShapeData(_position, _size*0.75f), ButtonData());
	_buttonRessource->GetData().pressedCallback = [&]()
	{
		cout << "Ressource" << endl;
		AddRessourceType();
		canvas->SetVisibilityStatus(false);
		timerRessource->Start();
	};

	_buttonRessource->GetObject()->GetShape()->setFillColor(Color::Green);


	string _path;
	switch (type)
	{
	case HALL_GENERATOR:
		_path = "Assets/Texture/Icon/Electicity_Icon.png";
		break;
	case HALL_FAST_FOOD:
		_path = "Assets/Texture/Icon/Food_Icon.png";
		break;
	case HALL_TRAITEMENT_DES_EAUX:
		_path = "Assets/Texture/Icon/Water_Icon.png";
		break;
	case HALL_DORTOIR:
		_path = "Assets/Texture/Icon/Baby_Icon.png";
		break;
	default:
		break;
	}

	TextureManager::GetInstance().Load(_buttonRessource->GetObject()->GetShape(), _path);


	canvas->AddWidget(_buttonRessource);
	canvas->SetVisibilityStatus(false);
}

void Hall::DrawButton()
{
	if (humans.size() >= 2 && type == HALL_DORTOIR)
	{
		canvas->SetVisibilityStatus(true);
	}
	else if (humans.size() >= 1 && type != HALL_DORTOIR)
	{
		canvas->SetVisibilityStatus(true);
	}
}

void Hall::AddRessourceType()
{
	int _index=-1;
	switch (type)
	{
	case HALL_GENERATOR:
		_index = 0;
		break;
	case HALL_FAST_FOOD:
		_index = 1;
		break;
	case HALL_TRAITEMENT_DES_EAUX:
		_index = 2;
		break;
	case HALL_DORTOIR:
		_index = 3;
		break;
	default:
		break;
	}

	if (_index==-1)
	{
		cerr << "Ressource not found" << endl;
		return;
	}
	
	if (_index==3)
	{
		Vector2f _offset = Vector2f(20, 50);
		Vector2f _sizeHuman = Vector2f(20, 50);
		Vector2f _position = MapManager::GetInstance().GetCurrent()->GetGrid()->GetAllTiles()[0][3]->GetShape()->getPosition() + _offset;
		Human* _h = new Human(ShapeData(_position, _sizeHuman));
		_h->Init();
		return;
	}

	

	if (PLAYERBUNKER->GetAllRessource()[_index]->GetQuantity() + 1> PLAYERBUNKER->GetAllRessource()[_index]->GetMaxQuantity())
	{
		PLAYERBUNKER->GetAllRessource()[_index]->SetQuantity(PLAYERBUNKER->GetAllRessource()[_index]->GetMaxQuantity());
		return;
	}
	PLAYERBUNKER->GetAllRessource()[_index]->SetQuantity(PLAYERBUNKER->GetAllRessource()[_index]->GetQuantity()+ quantity);
	quantity = humans.size() * 2;

}

void Hall::AddHumanInHall(Human* _human)
{
	humans.push_back(_human);
}
