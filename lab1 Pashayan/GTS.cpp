#pragma once
#include "GTS.h"
#include "utils.h"

int GTS::get_csindex(int id) const
{
	return IdIndexCS.find(id)->second;
}

void GTS::add_cs(const unordered_map<int, CS>& map, int id) 
{
	Edges.insert(map.find(id)->first);
	IdIndexCS.insert({ id, Edges.size() - 1 });
	cout << "CS added ID: " << IdIndexCS.find(id)->first << " Index: " << IdIndexCS.find(id)->second << endl;
	Is_Changed = true;

}

void GTS::add_pipe(const unordered_map<int, Pipe>& map, int id)
{

	Vertices.insert(map.find(id)->first);
	IdIndexPipe.insert({ id, Vertices.size() - 1 });
	cout << "Pipe added ID: " << IdIndexPipe.find(id)->first << " Index: " << IdIndexPipe.find(id)->second << endl;
	Is_Changed = true;
}


void GTS::connect_vertices(unordered_map<int, CS>& mapCS, unordered_map<int, Pipe>& mapPipe)
{
	int CSId1 = CheckValue("Выберите начальную КС", 0, CS::getMaxID());
	int pipeId = CheckValue("Выберите трубу: ", 0, Pipe::getMaxID()); 
	int CSId2 = CheckValue("Выберите конечную КС: ", 0, CS::getMaxID());
	mapPipe.find(pipeId)->second.setstart(CSId1);
	mapPipe.find(pipeId)->second.setend(CSId2);
	cout << "КС: " << CSId1 << " была соединена с КС : " << CSId2 << "трубой с ID: " << pipeId << endl;
	Is_Changed = true;
}

void GTS::create_adjmatr(unordered_map<int, CS>& mapCS, unordered_map<int, Pipe>& mapPipe)
{
	int n = Edges.size();
	AdjMatr.resize(n);
	if (Is_Changed) {
		AdjMatr.clear();
		AdjMatr.resize(n);
		for (int i = 0; i < n; i++) {
			AdjMatr[i].resize(n);
			Is_Changed = false;
		}
	}
	for (auto itr = mapPipe.begin(); itr != mapPipe.end(); itr++) {
		if (itr->second.getstart() != -1) {
			AdjMatr[get_csindex(itr->second.getstart())][get_csindex(itr->second.getend())] = 1;
		}
	}
	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {
			cout << AdjMatr[i][j] << " ";
		}	
		cout << endl;
	}
}

void GTS::delete_edge(int id, unordered_map<int, Pipe>& mapPipe)
{
	Is_Changed = true;
	Edges.erase(id);
	IdIndexCS.erase(id);

	for (auto iter = mapPipe.begin(); iter != mapPipe.end(); iter++) {
		if (iter->second.getstart() == id || iter->second.getend() == id) {
			delete_vertices(iter->first);
		}
	}
}

void GTS::delete_vertices(int id)
{
	Is_Changed = true;
	Vertices.erase(Vertices.find(id));
	IdIndexPipe.erase(id);

}