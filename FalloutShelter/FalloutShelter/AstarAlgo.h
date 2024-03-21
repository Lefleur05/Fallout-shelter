#pragma once
#include"Nodes.h"
#include<vector>
#include"Macro.h"

using namespace std;

class AstarAlgo
{
	vector<Nodes*> correctPath;
	Vertex* line;
public:
	AstarAlgo();
	~AstarAlgo();
	void ComputePath(Nodes* _start,Nodes* _end);
	vector<Nodes*> GetFinalPath(Nodes* _start,Nodes* _end);

	vector<Nodes*>& GetPathList()
	{
		return correctPath;
	}
};

