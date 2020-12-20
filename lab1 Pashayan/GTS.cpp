#pragma once
#include "GTS.h"
#include "utils.h"

int GTS::GetCsIndex(int id) const
{
	return IdIndexCS.find(id)->second;
}

void GTS::AddCS(const unordered_map<int, CS>& map, int id) 
{
	edges.insert(map.find(id)->first);
	IdIndexCS.insert({ id, edges.size() - 1 });
	cout << "CS added ID: " << IdIndexCS.find(id)->first << " Index: " << IdIndexCS.find(id)->second << endl;
	is_changed = true;

}

void GTS::AddPipe(const unordered_map<int, Pipe>& map, int id)
{

	vertices.insert(map.find(id)->first);
	IdIndexPipe.insert({ id, vertices.size() - 1 });
	cout << "Pipe added ID: " << IdIndexPipe.find(id)->first << " Index: " << IdIndexPipe.find(id)->second << endl;
	is_changed = true;
}


void GTS::ConnectEdges(unordered_map<int, CS>& mapCS, unordered_map<int, Pipe>& mapPipe)
{
	cout << "Enter start CS: " << endl;
	int CSId1 = CheckValue("Enter start CS", 0, CS::getMaxID());
	int pipeId = CheckValue("Enter Pipe: ", 0, Pipe::getMaxID()); 
	int CSId2 = CheckValue("Enter final CS: ", 0, CS::getMaxID());
	mapPipe.find(pipeId)->second.setstart(CSId1);
	mapPipe.find(pipeId)->second.setend(CSId2);
	cout << "CS: " << CSId1 << " was connected with CS: " << CSId2 << "by Pipe with id: " << pipeId << endl;

	is_changed = true;
}

