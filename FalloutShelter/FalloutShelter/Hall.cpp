#include "Hall.h"
#include "PlayerBunker.h"
#include "GameWindow.h"
#include "Macro.h"
#include "HUD.h"
#include "TextureManager.h"

Hall::Hall(HallType _type)
{
	type = _type;
	hallSize = 1;
	hallLV = 1;
	humans = vector<Human*>();
	canvas = nullptr;
	timerRessource = nullptr;
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
}

void Hall::InitTimer()
{
	function<void()> _function = [&]()
	{
		cout << "Timer Begin" << endl;
		canvas->SetVisibilityStatus(true);
		timerRessource->Pause();
	};

	timerRessource = new Timer(_function, seconds(5), true, true);
}

void Hall::InitButton(Shape* _shape, Vector2f _size)
{
	canvas = new Canvas("ButtonRessource");
	Button* _buttonRessource = new Button(ShapeData(_shape->getPosition(), _size), ButtonData());
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
		break;
	default:
		break;
	}

	if (_index==-1)
	{
		cerr << "Ressource not found" << endl;
		return;
	}

	if (PLAYERBUNKER->GetAllRessource()[_index]->GetQuantity() + 1> PLAYERBUNKER->GetAllRessource()[_index]->GetMaxQuantity())
	{
		PLAYERBUNKER->GetAllRessource()[_index]->SetQuantity(PLAYERBUNKER->GetAllRessource()[_index]->GetMaxQuantity());
		return;
	}
	PLAYERBUNKER->GetAllRessource()[_index]->SetQuantity(PLAYERBUNKER->GetAllRessource()[_index]->GetQuantity()+1);

}
