#pragma once
#include "Pipe.h"
#include "CS.h"
#include <unordered_set>
#include <unordered_map>
#include <vector>


using namespace std;

class GTS
{
	unordered_set<int> edges; //id ребер
	unordered_set<int> vertices; //id вершины

	unordered_map<int, int> IdIndexCS;
	unordered_map<int, int> IdIndexPipe;

	vector<vector<int>> AdjMatr;
	vector<vector<int>> IncMatr;
	bool is_changed;

public:
	int GetCsIndex(int) const;

	void AddCS(const unordered_map<int, CS>&, int);

	void AddPipe(const unordered_map<int, Pipe>&, int);

	void ConnectEdges(unordered_map<int, CS>&, unordered_map<int, Pipe>&);


	void CreateAdjacencyMatrix(unordered_map<int, CS>&, unordered_map<int, Pipe>&);


	void DeleteEdge(int, unordered_map<int, Pipe>&);

	void DeleteVertex(int);

	void TopologicalSort(int, vector<int>&, bool&, vector<int>&);

	void TopSort();

};