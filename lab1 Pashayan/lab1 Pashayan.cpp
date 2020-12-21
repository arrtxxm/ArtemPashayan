// lab1 Pashayan.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#pragma once
#include <math.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include "Pipe.h"
#include "CS.h"
#include "utils.h"
#include "GTS.h"

using namespace std;

void Print_second_menu(string clause1, string clause2);

template<class T, typename T_param>
using Filter = bool(*)(const T& obj, T_param param);

template<class T, typename T_param>
vector<int> FindObjectsByFilter(const unordered_map<int, T>& m, Filter<T, T_param> f, T_param param) {
	vector <int> res;
	for (auto& obj : m) {
		if (f(obj.second, param))
			res.push_back(obj.first);
	}
	return res;
}

template <class T>

bool CheckByID(const T& p, unsigned int param) {
	return p.getid() == param;
}

bool CheckByBroken(const Pipe& p, bool param) {
	return p.getbroken() == param;
}

bool CheckByName(const CS& cs, string param) {
	return cs.getname() == param;
}

bool CheckByPercentOfWorkshops(const CS& cs, double param) {
	double percent_workshops = 1.0 - cs.getrunning_workshops() / (double)cs.getworkshops();
	return (abs(percent_workshops - param / 100.0) < 0.0001);
}

template<class T>

void DeletePipeCS(unordered_map <int, T>& m) 
{
	unsigned int id = CheckValue("Введите ID: ", 0, 10000);
	int n = 0;
	bool is_finded = false;
	if (m.count(id) == 1) m.erase(id);
	else cout << "Такого ID не существует" << endl;
}

void EditingPipes(unordered_map<int, Pipe>& m, vector<int> EditedPipes) 
{
	int answer;
	while (true) {
		Print_second_menu("All found", "Поиск по индексу");
		answer = CheckValue("Your choice (0-2): ", 0, 2);
		if (answer == 1) {
			for (auto& i : EditedPipes) {
				m[i].Pipe_status_change();
			}
			break;
		}
		else if (answer == 2) {
			int from = CheckValue("Введите начальный индекс: ", 0, Pipe::getMaxID());
			int to = CheckValue("Введите конечный индекс: ", from, Pipe::getMaxID());
			int n = 0;
			for (auto& p : m) {
				if (p.second.getid() >= from && p.second.getid() <= to) {
					p.second.Pipe_status_change();
				}
				n++;
			}
		}
		else 
		{
			break;
		}
	}
}

void PrintMenu()
{
	cout << "-------------------\n"
		<< "1. Создание трубы или КС" << "\n"
		<< "2. Вывод всех объектов" << "\n"
		<< "3. Редактирование трубы или КС" << "\n"
		<< "4. Удаление трубы или КС" << "\n"
		<< "5. Поиск труб по заданному фильтру" << "\n"
		<< "6. Поиск КС по заданному фильтру" << "\n"
		<< "7. Пакетное редактирование труб" << "\n"
		<< "8. Сохранение в файл" << "\n"
		<< "9. Загрузка из файла" << "\n"
		<< "10. Очистить консоль" << "\n"
		<< "11. Добавить КС в ГТС" << "\n"
		<< "12. Добавить трубу в ГТС" <<"\n"
	    << "13. Соединить станции" <<"\n"
		<< "14. Топологическая сортировка" << "\n"
		<< "0. Выход" << "\n"
		<< "-------------------" << endl;
}

void Print_second_menu(string clause1, string clause2)
{
	cout << "-------------------\n"
		<< "0. Назад" << "\n"
		<< "1. " << clause1 << "\n"
		<< "2. " << clause2 << "\n"
		<< "-------------------" << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	unordered_map <int, Pipe> Pipes;
	unordered_map <int, CS> CSs;
	GTS GTS;
	vector <int> EditedPipes;
	while (true)
	{
		PrintMenu();
		int i = CheckValue("Выберите от 0 до 14: ", 0, 14);
		cout << '\n';
		switch (i)
		{
		case 1:
		{
			while (true)
			{
				Print_second_menu("Труба", "КС");
				int i1 = CheckValue("Выберите от 0 до 2: ", 0, 2);
				if (i1 == 1)
				{
					Pipe pipe;
					cin >> pipe;
					Pipes.emplace(pipe.getid(), pipe);
				}
				else if (i1 == 2)
				{
					CS cs;
					cin >> cs;
					CSs.emplace(cs.getid(), cs);
				}
				else if (i1 == 0)
				{
					break;
				}
				else
				{
					cout << "Ошибка: выберите от 0 до 2" << endl;
				}
			}
			break;
		}
		case 2:
		{
			if (Pipes.size() != 0) {
				for (auto& p : Pipes)
				{
					cout << p.second << endl;
				}
			}
			else {
				cout << "Вы еще не создавали трубы" << endl;
			}
			if (CSs.size() != 0) {
				for (auto& cs : CSs) {
					cout << cs.second << endl;
				}
			}
			else {
				cout << "Вы еще не создавали КС" << endl;
			}
			break;
		}
		case 3: {
			while (true) {
				Print_second_menu("Труба", "КС");
				int i2 = CheckValue("Выберите от 0 до 2: ", 0, 2);
				if (i2 == 1) {
					int ID = CheckValue("Введите ID: ", 1u, Pipes.size());
					if (Pipes.size() != 0) {
						if (Pipes.count(ID))
							Pipes[ID].Pipe_status_change();
						else cout << " Такого ID не существует " << endl;
					}
					else {
						cout << "Вы еще не создавали трубы" << endl;
					}
				}
				else if (i2 == 2) {
					int ID = CheckValue("Введите ID:", 1u, CSs.size());
					if (CSs.size() != 0) {
						CSs[ID].edit_CS();
					}
					else {
						cout << "Вы еще не создавали КС" << endl;
					}
				}
				else if (i2 == 0) {
					cout << '\n';
					break;
				}
				else {
					cout << "Ошибка, выберите от 0 до 2" << endl;
				}
			}
			break;
		}
		case 4: {
			while (true) {
				Print_second_menu("Труба", "КС");
				int i3 = CheckValue("Выберите от 0 до 2: ", 0, 2);
				if (i3 == 1) {
					if (Pipes.size() != 0) {
						DeletePipeCS(Pipes);
					}
					else {
						cout << "Вы еще не создавали трубы" << endl;
					}
				}
				else if (i3 == 2) {
					if (CSs.size() != 0) {
						DeletePipeCS(CSs);
					}
					else {
						cout << "Вы еще не создавали КС" << endl;
					}
				}
				else if (i3 == 0) {
					cout << '\n';
					break;
				}
				else {
					cout << "Ошибка: выберите от 0 до 2" << endl;
				}
			}
			break;
		}
		case 5: {
			while (true) {
				Print_second_menu("Поиск по ID", "Поиск по статусу в ремонте ");
				int i4 = CheckValue("Выберите от 0 до 2: ", 0, 2);
				if (i4 == 1) {
					unsigned int id_to_find;
					id_to_find = CheckValue("Введите ID: ", 0u, 10000u);
					for (int i : FindObjectsByFilter(Pipes, CheckByID, id_to_find)) {
						cout << Pipes[i] << endl;
						EditedPipes.push_back(i);
					}
				}
				else if (i4 == 2) {
					bool is_broken_status_to_find;
					is_broken_status_to_find = CheckValue("В ремонте? [да-1/нет-0]: ", false, true);
					for (int i : FindObjectsByFilter(Pipes, CheckByBroken, is_broken_status_to_find)) {
						cout << Pipes[i] << endl;
						EditedPipes.push_back(i);
					}
				}
				else if (i4 == 0) {
					break;
				}
				else {
					cout << "Ошибка: выберите от 0 до 2" << endl;
				}
			}
			break;
		}
		case 6:
		{
			while (true)
			{
				Print_second_menu("Поиск по имени", "Поиск по проценту незадействованных цехов");
				int i5 = CheckValue("Выберите от 0 до 2: ", 0, 2);
				if (i5 == 1) {
					string name_to_find;
					cout << "Введите имя КС: ";
					cin.get();
					getline(cin, name_to_find);
					for (int i : FindObjectsByFilter(CSs, CheckByName, name_to_find)) {
						cout << CSs[i] << endl;
					}
				}
				else if (i5 == 2) {
					double percentage_to_find;
					percentage_to_find = CheckValue("Введите значение в процентах (0-100%): ", 0.0, 100.0);
					for (int i : FindObjectsByFilter(CSs, CheckByPercentOfWorkshops, percentage_to_find)) {
						cout << CSs[i] << endl;
					}
				}
				else if (i5 == 0) {
					break;
				}
				else {
					cout << "Ошибка: выберите от 0 до 2 " << endl;
				}
			}
			break;
		}
		case 7: {
			if (Pipes.size() != 0) {
				EditingPipes(Pipes, EditedPipes);
			}
			else {
				cout << "Вы еще не создавали трубы" << endl;
			}
			break;
		}
		case 8: {
			ofstream fout;
			string filename;
			cout << "Введите название файла: ";
			cin.ignore();
			getline(cin, filename);
			fout.open(filename, ios::out);
			if (fout.is_open())
			{
				fout << Pipes.size() << endl;
				fout << CSs.size() << endl;
				for (auto p : Pipes)
					fout << p.second;
				for (auto cs : CSs)
					fout << cs.second;
				fout.close();
			}
			else cout << "Файл не открывается" << endl;
			break;
		}
		case 9: {
			ifstream fin;
			string filename;
			cout << "Введите название файла: ";
			cin.ignore();
			getline(cin, filename);
			fin.open(filename, ios::in);
			if (fin.is_open()) {
				int number_of_pipes;
				int number_of_CSs;
				fin >> number_of_pipes;
				fin >> number_of_CSs;
				while (number_of_pipes--) {
					Pipe p;
					fin >> p;
					Pipes.emplace(p.getid(), p);
				}
				while (number_of_CSs--) {
					CS c;
					fin >> c;
					CSs.emplace(c.getid(), c);
				}
				fin.close();
			}
			else cout << "Файл не открывается" << endl;
			break;
		}
		case 10:
		{
			system("cls");
			break;
		}
		case 11:
		{
			GTS.add_cs(CSs, CheckValue("Введите ID КС: ", 0, CS::getMaxID()));
			break;
		}
		case 12:
		{
			GTS.add_pipe(Pipes, CheckValue("Введите ID трубы:", 0, Pipe::getMaxID()));
			break;
		}
		case 13:
		{
			GTS.connect_vertices(CSs, Pipes);
			break;
		}
		case 14:
		{
			GTS.create_adjmatr(CSs, Pipes);
			GTS.sort();
			break;
		}
		case 0:\
		{
			return 0;
		}
		default:
		{
			cout << "Ошибка: введите значение 0 до 10" << endl;
		}
		}
	}
		return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
