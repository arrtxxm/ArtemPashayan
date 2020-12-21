#pragma once
#include "Pipe.h"
#include "CS.h"
#include <unordered_set>
#include <unordered_map>
#include <vector>


using namespace std;

class GTS
{
	unordered_set<int> Edges; 
	unordered_set<int> Vertices; 

	unordered_map<int, int> IdIndexCS;
	unordered_map<int, int> IdIndexPipe;

	vector<vector<int>> AdjMatr;
	vector<vector<int>> IncMatr;

	bool Is_Changed;

public:
	int get_csindex(int) const;	
	
	int GetCsId(int) const;

	void add_cs(const unordered_map<int, CS>&, int);

	void add_pipe(const unordered_map<int, Pipe>&, int);

	void connect_vertices(unordered_map<int, CS>&, unordered_map<int, Pipe>&);

	void create_adjmatr(unordered_map<int, CS>&, unordered_map<int, Pipe>&);

	void delete_edge(int, unordered_map<int, Pipe>&);

	void delete_vertices(int);

	void topological_sort(int, vector<int>&, bool&, vector<int>&);

	void sort();

	void UpdateIndex();


};