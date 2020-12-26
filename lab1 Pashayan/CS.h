#pragma once
#include <string>
#include <iostream>
#include "utils.h"
#include <fstream>

class CS
{
	std::string Name;
	int ShopsCount;
	int WorkingShopsCount;
	float Efficiency;
public:
	static int csMaxId;
	friend std::ostream& operator << (std::ostream& out, const CS& cs);
	friend std::istream& operator >> (std::istream& in, CS& cs);
	CS();
	CS(std::ifstream& fin);
	std::string GetName() const;
	float GetPercentUnusedShops() const;
	void RecountShopsCount();
	void RecountWorkingShopsCount();
	void SaveToFile(std::ofstream& fout);
};