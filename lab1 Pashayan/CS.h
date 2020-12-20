#pragma once
#include <string>
#include <fstream>

using namespace std;

class CS
{	int id;
	int workshops;
	int running_workshops;

	static int MaxID;

	string name;

	double efficiency;

public:
	CS();
	int getid() const;
	int getworkshops() const;
	int getrunning_workshops() const;
	static int getMaxID();

	string getname() const;

	void edit_CS();
	friend istream& operator >> (istream& in, CS& cs);
	friend ostream& operator << (ostream& out, const CS& cs);
	friend ifstream& operator >> (ifstream& in, CS& cs);
	friend ofstream& operator << (ofstream& out, const CS& cs);
};

