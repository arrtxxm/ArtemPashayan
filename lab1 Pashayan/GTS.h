#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include "Pipe.h"
#include "CS.h"
#include <unordered_map>
#include "utils.h"
#include <set>
using namespace std;

class GTS
{
    unordered_map<int, Pipe> pGroup;
    unordered_map<int, CS> csGroup;

    vector<vector<int>> GetEdgesAndVertexes(unordered_map<int, int>& indexVertexes, int& n);

public:
    GTS();
    GTS(ifstream& fin);
    friend ostream& operator << (ostream& out, const GTS& gtn);
    void SaveToFile(ofstream& fout);
    void AddPipe();
    void AddCs();
    bool HasPipe() const;
    bool HasCs(int count = 1) const;
    void EditPipe();
    void EditCs();
    void DeletePipe();
    void DeleteCs();
    void SearchPipes();
    void SearchCss();
    void ConnectPipe();
    void DisonnectPipe();
    bool CanBeUsed(const Pipe& p) const;
    void ShowNetwork();
    void TopologicalSort();
    void FindMaxFlow();
    void FindShortestPath();
};