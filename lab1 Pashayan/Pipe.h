#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Pipe
{int id;
	static int MaxID;
	bool broken;
public:
	double length;
	int diameter;
	Pipe();
	int getid() const;
	static int getMaxID();
	bool getbroken() const;
	friend istream& operator >> (istream& in, Pipe& p);
	friend ostream& operator << (ostream& out, const Pipe& p);
	friend ifstream& operator >> (ifstream& in, Pipe& p);
	friend ofstream& operator << (ofstream& out, const Pipe& p);
	void Pipe_status_change();
};