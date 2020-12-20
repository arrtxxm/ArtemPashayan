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
	running_workshops = CheckValue("Введите количество цехов в работе: ", 0, workshops);
}

void CS::stop_CS()
{
	if (running_workshops > 0) {
		running_workshops--;
	}
	else {
		cout << "Нет цехов в работе" << endl;
	}	
}

void CS::run_CS()
{
	if (running_workshops < workshops) {
		running_workshops++;
	}
	else {
		cout << "Все цеха в работе" << endl;
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
	cout << "Введите имя КС: " << endl;
	cin.get();
	getline(cin, cs.name);
	cs.workshops = CheckValue("Сколько заводов всего: ", 0, 100);
	cs.running_workshops = CheckValue("Сколько заводов в работе: ", 0, cs.workshops);
	cs.efficiency = CheckValue("Эффективность КС: ", 0.0, 1.0);
	return in;
}

ostream& operator << (ostream& out, const CS& cs)
{
	out << "\nВывести информацию о КС " << cs.id << "\n"
		<< "Имя КС: " << cs.name << "\n"
		<< "Количество заводов: " << cs.workshops << "\n"
		<< "Количество заводов в работе: " << cs.running_workshops << "\n"
		<< "Эффективность КС: " << cs.efficiency << endl;
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
