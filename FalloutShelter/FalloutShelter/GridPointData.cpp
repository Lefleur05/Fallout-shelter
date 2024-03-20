#include "GridPointData.h"
#include"Macro.h"

GridPointData::GridPointData()
{

}

//GridPointData::~GridPointData()
//{
//	for (size_t i = 0; i < nodes.size(); i++)
//	{
//		delete nodes[i];
//	}
//}

void GridPointData::RestCost()
{
	for (size_t i = 0; i < nodes.size(); i++)
	{
		nodes[i]->ResteNode();
	}
}

Nodes* GridPointData::GetClosesNode(Vector2f _location)
{
	Nodes* _current = nullptr;
	float _max = std::numeric_limits<float>::max();
	for (size_t i = 0; i < nodes.size(); i++)
	{
		float _dist = Distance(nodes[i]->GetShapePosition(),_location);
		if (_dist < _max)
		{
			_max = _dist;
			_current = nodes[i];
		}
	}
	return _current;
}
