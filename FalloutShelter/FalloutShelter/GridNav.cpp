#include "GridNav.h"
#include"Nodes.h"
#include <iostream>
#include "Macro.h"

GridNav::GridNav(const int _size, const int _gap,const Vector2f& _offsetGrid)
{
    size = _size;
    gap = _gap;
    position = _offsetGrid;
    Generate();
}

GridNav::~GridNav()
{
    
}

void GridNav::RestCost()
{
    for (size_t i = 0; i < nodes.size(); i++)
    {
        nodes[i]->ResteNode();
    }
}

Nodes* GridNav::GetClosesNode(Vector2f _location)
{
    Nodes* _current = nullptr;
    float _max = std::numeric_limits<float>::max();
    for (size_t i = 0; i < nodes.size(); i++)
    {
        float _dist = Distance(nodes[i]->GetShapePosition(), _location);
        if (_dist < _max)
        {
            _max = _dist;
            _current = nodes[i];
        }
    }
    return _current;
}

void GridNav::Generate()
{
    nodes.clear();
    const Vector2f& _nodeSize = Vector2f(10, 10);
    for (int x = 0; x < size; x++)
    {
        for (int y = 0; y < size; y++)
        {
            const Vector2f& _pos = Vector2f(x * _nodeSize.x + x * gap, y * _nodeSize.y + y * gap) + position;
            Nodes* _n = new Nodes(ShapeData(_pos, _nodeSize),this);
            _n->GetShape()->setFillColor(Color::Transparent);
            nodes.push_back(_n);
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
            nodes[i]->AddSuccessor(i + 1);
        if (_canLeft)
            nodes[i]->AddSuccessor(i - 1);
        if (_canTop)
        {
            nodes[i]->AddSuccessor(i - size);
            if (_canRight)
                nodes[i]->AddSuccessor((i + 1 - size));
            if (_canLeft)
                nodes[i]->AddSuccessor((i - 1 - size));
        }
        if (_canDown)
        {
            nodes[i]->AddSuccessor(i + size);
            if (_canRight)
                nodes[i]->AddSuccessor((i + 1 + size));
            if (_canLeft)
                nodes[i]->AddSuccessor((i - 1 + size));
        }
    }
}


//for (int i = 0; i < size * size; i++)
//{
//    bool _canRight = i % size != size - 1,
//        _canTop = i >= size,
//        _canDown = i < (size * size) - size,
//        _canLeft = i % size != 0;
//    if (_canRight)
//        data->GetNodes()[i]->AddSuccessor(i + 1);
//    if (_canLeft)
//        data->GetNodes()[i]->AddSuccessor(i - 1);
//    if (_canTop)
//    {
//        data->GetNodes()[i]->AddSuccessor(i - size);
//        if (_canRight)
//            data->GetNodes()[i]->AddSuccessor((i + 1 - size));
//        if (_canLeft)
//            data->GetNodes()[i]->AddSuccessor((i - 1 - size));
//    }
//    if (_canDown)
//    {
//        data->GetNodes()[i]->AddSuccessor(i + size);
//        if (_canRight)
//            data->GetNodes()[i]->AddSuccessor((i + 1 + size));
//        if (_canLeft)
//            data->GetNodes()[i]->AddSuccessor((i - 1 + size));
//    }
//}