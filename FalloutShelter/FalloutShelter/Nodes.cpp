#include "Nodes.h"
#include "Macro.h"

Nodes::Nodes(const ShapeData& _data, GridNav* _grid) : Actor(STRING_ID("Nodes"),_data)
{
	F = G + H;
	gridNav = _grid;
}

Nodes::Nodes(const ShapeData& _data) : Actor(STRING_ID("Nodes"), _data)
{
	F = G + H;
}


void Nodes::ResteNode()
{
	G = std::numeric_limits<float>::max();
	H = std::numeric_limits<float>::max();
	parent = nullptr;
}
