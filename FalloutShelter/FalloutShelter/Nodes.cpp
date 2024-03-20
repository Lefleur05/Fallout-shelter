#include "Nodes.h"
#include "Macro.h"

Nodes::Nodes(const ShapeData& _data, GridPointData* _grid) : Actor(STRING_ID("Nodes"),_data)
{
	F = G + H;
	grid = _grid;
}

Nodes::~Nodes()
{
	delete parent;
}

void Nodes::ResteNode()
{
	G = std::numeric_limits<float>::max();
	H = std::numeric_limits<float>::max();
	parent = nullptr;
}
