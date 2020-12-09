#include "Pipe.h"
#include "utils.h"
using namespace std;

int Pipe::MaxID = 0;

Pipe::Pipe() {
	id = MaxID++;
	length = 0;
	diameter = 0;
	broken = false;
}


int Pipe::getid() const
{
	return id;
}

int Pipe::getMaxID()
{
	return MaxID;
}

bool Pipe::getbroken() const
{
	return broken;
}

void Pipe::Pipe_status_change()
{
	broken = !broken;
}

istream& operator >> (istream& in, Pipe& p)
{
	p.length = CheckValue("Введите длину трубы: ", 0.0, 1000.0);
	p.diameter = CheckValue("Введите диаметр трубы: ", 0, 2500);
	p.broken = false;
	return in;
}


ostream& operator << (ostream& out, const Pipe& p)
{
	out << "\nВывести информацию о трубе " << p.id << "\n"
		<< "Длина трубы: " << p.length << "\n"
		<< "Диаметр трубы: " << p.diameter << "\n"
		<< "Статус трубы: " << p.broken
		<< endl;
	return out;
}

ifstream& operator>>(ifstream& fin, Pipe& p)
{
	fin >> p.id >> p.length >> p.diameter >> p.broken;
	return fin;
}

ofstream& operator<<(ofstream& fout, const Pipe& p)
{
	fout << p.id << endl << p.length << endl
		<< p.diameter << endl << p.broken << endl;
	return fout;
}
