#include <iostream>
#include "CS.h"
#include "utils.h"

using namespace std;

int CS::MaxID = 0;

string CS::getname() const
{
	return name;
}

int CS::getMaxID()
{
	return MaxID;
}

int CS::getid() const
{
	return id;
}

int CS::getworkshops() const 
{
	return workshops;
}

int CS::getrunning_workshops() const
{
	return running_workshops;
}

double CS::getefficiency() const
{
	return efficiency;
}

void CS::edit_CS() {
	running_workshops = CheckValue("������� ���������� ����� � ������: ", 0, workshops);
}

void CS::stop_CS()
{
	if (running_workshops > 0) {
		running_workshops--;
	}
	else {
		cout << "��� ����� � ������" << endl;
	}	
}

void CS::run_CS()
{
	if (running_workshops < workshops) {
		running_workshops++;
	}
	else {
		cout << "��� ���� � ������" << endl;
	}
}


CS::CS() {
	id = ++MaxID;
	string name = "Unknown";
	workshops = 0;
	running_workshops = 0;
	efficiency = 0.0;
}


istream& operator >> (istream& in, CS& cs)
{
	cout << "������� ��� ��: " << endl;
	cin.get();
	getline(cin, cs.name);
	cs.workshops = CheckValue("������� ������� �����: ", 0, 100);
	cs.running_workshops = CheckValue("������� ������� � ������: ", 0, cs.workshops);
	cs.efficiency = CheckValue("������������� ��: ", 0.0, 1.0);
	return in;
}

ostream& operator << (ostream& out, const CS& cs)
{
	out << "\n������� ���������� � �� " << cs.id << "\n"
		<< "��� ��: " << cs.name << "\n"
		<< "���������� �������: " << cs.workshops << "\n"
		<< "���������� ������� � ������: " << cs.running_workshops << "\n"
		<< "������������� ��: " << cs.efficiency << endl;
	return out;
}

ifstream& operator>>(ifstream& fin, CS& cs)
{
	fin >> cs.id >> cs.name >> cs.workshops
		>> cs.running_workshops >> cs.efficiency;
	return fin;
}

ofstream& operator<<(ofstream& fout, const CS& cs)
{
	fout << cs.id << endl << cs.name << endl << cs.workshops
		<< endl << cs.running_workshops << endl << cs.efficiency << endl;
	return fout;
}
