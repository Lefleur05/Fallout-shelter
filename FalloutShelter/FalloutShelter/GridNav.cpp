#include "GridNav.h"
#include"GridPointData.h"
#include <iostream>

GridNav::GridNav(const int _size, const int _gap,const Vector2f& _offsetGrid)
{
	data = new GridPointData();
    size = _size;
    gap = _gap;
    position = _offsetGrid;
    Generate();
}

GridNav::~GridNav()
{
    delete data;
}

void GridNav::Generate()
{
	if (!data)
		return;
    vector<Nodes*>& _nodes = data->GetNodes();
    _nodes.clear();
    system("cls");
    const Vector2f& _nodeSize = Vector2f(10, 10);
	for (int x = 0; x < size; x++)
	{
		for (int y = 0; y < size; y++)
		{
			const Vector2f& _pos = Vector2f(x * _nodeSize.x + x * gap, y * _nodeSize.y + y * gap) + position;
			Nodes* _n = new Nodes(ShapeData(_pos, _nodeSize), data);
            _nodes.push_back(_n);
		}
	}
	SetSuccessors();
}

void GridNav::SetSuccessors()
{
    for (int i = 0; i < size * size; i++)
    {
        bool _canRight = i % size != size - 1,
            _canTop = i >= size,
            _canDown = i < (size * size) - size,
            _canLeft = i % size != 0;
        if (_canRight)
            data->GetNodes()[i]->AddSuccessor(i + 1);
        if (_canLeft)
            data->GetNodes()[i]->AddSuccessor(i - 1);
        if (_canTop)
        {
            data->GetNodes()[i]->AddSuccessor(i - size);
            if (_canRight)
                data->GetNodes()[i]->AddSuccessor((i + 1 - size));
            if (_canLeft)
                data->GetNodes()[i]->AddSuccessor((i - 1 - size));
        }
        if (_canDown)
        {
            data->GetNodes()[i]->AddSuccessor(i + size);
            if (_canRight)
                data->GetNodes()[i]->AddSuccessor((i + 1 + size));
            if (_canLeft)
                data->GetNodes()[i]->AddSuccessor((i - 1 + size));
        }
    }
}