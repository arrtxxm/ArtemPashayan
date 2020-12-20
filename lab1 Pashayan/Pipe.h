#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Pipe
{	int id;
	int diameter;
	int start;
	int end;

	static int MaxID;

	bool broken;
	bool used;

	double weight;
	double length;
	
public:	
	int getid() const;
	int getweight() const;
	int getlength() const;
	int getdiameter() const;
	int getstart() const;
	int getend() const;

	static int getMaxID();

	bool getbroken() const;

	friend istream& operator >> (istream& in, Pipe& p);
	friend ostream& operator << (ostream& out, const Pipe& p);
	friend ifstream& operator >> (ifstream& in, Pipe& p);
	friend ofstream& operator << (ofstream& out, const Pipe& p);

	void setstart(int);
	void setend(int);

	void used_status_change();
	void Pipe_status_change();
	Pipe();
};