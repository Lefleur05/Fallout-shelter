#include "AstarAlgo.h"
#include"GridPointData.h"
#include"Macro.h"

AstarAlgo::AstarAlgo()
{

}


AstarAlgo::~AstarAlgo()
{

}

void AstarAlgo::ComputePath(Nodes* _start, Nodes* _end)
{
	_start->GetGridNav()->RestCost();
	correctPath.clear();

	vector<Nodes*> _openList = vector<Nodes*>();
	vector<Nodes*> _closeList = vector<Nodes*>();

	_start->SetG(0);
	_start->SetH(0);

	_openList.push_back(_start);

	while (_openList.size() > 0)
	{
		Nodes* _current = _openList[0];
		_closeList.push_back(_current);
		if (_current == _end)
		{
			correctPath = GetFinalPath(_start, _end);
			return;
		}
		for (int i = 0; i < _current->GetSuccessors().size(); i++)
		{
			Nodes* _next = _current->GetGridNav()->GetNodes()[_current->GetSuccessors()[i]];
			if (find(_closeList.begin(), _closeList.end(), _next) != _closeList.end() || !_next->GetIsOpen())
				continue;
			float _hCost = Distance(_current->GetShapePosition(), _end->GetShapePosition());
			float _gCost = _current->GetG() + _hCost;

			if (_gCost < _next->GetG())
			{
				_next->SetG(_gCost);
				_next->SetH(_hCost);
				_next->SetParent(_current);
				_openList.push_back(_next);
			}
		}
	}

}

vector<Nodes*> AstarAlgo::GetFinalPath(Nodes* _start, Nodes* _end)
{
	vector<Nodes*> _path = vector<Nodes*>();
	Nodes* _current = _end;
	_path.push_back(_end);

	while (_current != _end)
	{
		_path.push_back(_current->GetParent());
		_current = _current->GetParent();
	}
	return _path;
}