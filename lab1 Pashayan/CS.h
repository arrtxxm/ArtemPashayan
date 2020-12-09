#pragma once
#include <string>
#include <fstream>

using namespace std;
class CS
{	int id;
	static int MaxID;
	string name;
	int workshops;
	int running_workshops;
	double efficiency;
public:
	CS();
	int getid() const;
	static int getMaxID();
	string getname() const;
	int getworkshops() const;
	int getrunning_workshops() const;
	void edit_CS();
	friend istream& operator >> (istream& in, CS& cs);
	friend ostream& operator << (ostream& out, const CS& cs);
	friend ifstream& operator >> (ifstream& in, CS& cs);
	friend ofstream& operator << (ofstream& out, const CS& cs);
};

