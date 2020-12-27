// lab1 Pashayan.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
#include <windows.h>
#include "GTS.h"
#include "utils.h"
using namespace std;

void PrintTitle(string title)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)((7 << 4) | 0));
	cout << '\n' << ' ' << title << ' ';
	SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
	cout << endl;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	GTS gtn = GTS();
	int edgeCount = 0;

	while (true)
	{
		PrintTitle("МЕНЮ");
		cout << "1 - Добавить трубу\n"
			<< "2 - Добавить КС\n"
			<< "3 - Просмотр всех объектов\n"
			<< "4 - Редактировать трубу\n"
			<< "5 - Редактировать КС\n"
			<< "6 - Удалить трубу\n"
			<< "7 - Удалить КС\n"
			<< "8 - Поиск труб\n"
			<< "9 - Поиск КС\n"
			<< "10 - Сохранить\n"
			<< "11 - Загрузить\n"
			<< "12 - Установить связь\n"
			<< "13 - Удалить связь\n"
			<< "14 - Вывести газотранспортную сеть\n"
			<< "15 - Выполнить топологическую сортировку\n"
			<< "16 - Найти кратчайшие пути\n"
			<< "17 - Найти максимальный поток\n"
			<< "0 и пр. - Выход\n";

		int inputMenu;
		CheckValue(inputMenu, "Что Вы хотите сделать: ");

		switch (inputMenu)
		{
		case 1:
		{
			PrintTitle("ДОБАВИТЬ ТРУБУ");
			gtn.AddPipe();
			break;
		}
		case 2:
		{
			PrintTitle("ДОБАВИТЬ КС");
			gtn.AddCs();
			break;
		}
		case 3:
		{
			PrintTitle("ПРОСМОТР ВСЕХ ОБЪЕКТОВ");
			cout << gtn;
			break;
		}
		case 4:
		{
			PrintTitle("РЕДАКТИРОВАТЬ ТРУБУ");
			if (gtn.HasPipe())
				gtn.EditPipe();
			else
				cout << "У Вас нет труб для редактирования.\n";
			break;
		}
		case 5:
		{
			PrintTitle("РЕДАКТИРОВАТЬ КС");
			if (gtn.HasCs())
				gtn.EditCs();
			else
				cout << "У Вас нет КС для редактирования.\n";
			break;
		}
		case 6:
		{
			PrintTitle("УДАЛИТЬ ТРУБУ");
			if (gtn.HasPipe())
				gtn.DeletePipe();
			else
				cout << "У Вас нет трубы для удаления.\n";
			break;
		}
		case 7:
		{
			PrintTitle("УДАЛИТЬ КС");
			if (gtn.HasCs())
				gtn.DeleteCs();
			else
				cout << "У Вас нет КС для удаления.\n";
			break;
		}
		case 8:
		{
			PrintTitle("ПОИСК ТРУБ");
			if (gtn.HasPipe())
				gtn.SearchPipes();
			else
				cout << "У Вас нет трубы для поиска.\n";
			break;
		}
		case 9:
		{
			PrintTitle("ПОИСК КС");
			if (gtn.HasCs())
				gtn.SearchCss();
			else
				cout << "У Вас нет КС для поиска.\n";
			break;
		}
		case 10:
		{
			PrintTitle("СОХРАНИТЬ");
			if (gtn.HasPipe() == false && gtn.HasCs() == false)
			{
				cout << "Внимание! У Вас ни одной трубы и КС. Вы действительно хотите сохранить данные?\n";
				int input;
				CheckValue(input, "(1 - да, 0 и пр. - нет): ");
				if (input != 1)
				{
					cout << "Отмена сохранения...\n";
					break;
				}
			}
			string filename;
			cout << "Введите имя файла сохранения (.txt): ";
			cin >> filename;
			ofstream fout;
			fout.open(filename + ".txt", ios::out);
			if (fout.is_open())
			{
				gtn.SaveToFile(fout);
				fout.close();
				cout << "Файл успешно сохранён!\n";
			}
			else
			{
				cout << "Ошибка сохранения файла!\n";
			}
			break;
		}
		case 11:
		{
			PrintTitle("ЗАГРУЗИТЬ");
			string filename;
			cout << "Введите имя файла загрузки (.txt): ";
			cin >> filename;
			ifstream fin;
			fin.open(filename + ".txt", ios::in);
			if (fin.is_open())
			{
				gtn = GTS(fin);
				fin.close();
				cout << "Файл успешно загружен!\n";
			}
			else
			{
				cout << "Ошибка сохранения файла!\n";
			}
			break;
		}
		case 12:
		{
			PrintTitle("УСТАНОВИТЬ СВЯЗЬ");
			if (gtn.HasPipe() && gtn.HasCs(2))
				gtn.ConnectPipe();
			else
				cout << "У Вас нет труб и КС для связи.\n";
			break;
		}
		case 13:
		{
			PrintTitle("УДАЛИТЬ СВЯЗЬ");
			if (gtn.HasPipe() && gtn.HasCs(2))
				gtn.ConnectPipe();
			else
				cout << "У Вас нет связей\n";
			break;
		}
		case 14:
		{
			PrintTitle("ГАЗОТРАНСПОРТНАЯ СЕТЬ");
			gtn.ShowNetwork();
			break;
		}
		case 15:
		{
			PrintTitle("ТОПОЛОГИЧЕСКАЯ СОРТИРОВКА");
			gtn.TopologicalSort();
			break;
		}
		case 16:
		{
			PrintTitle("НАЙТИ КРАТЧАЙШИЕ ПУТИ");
			gtn.FindShortestPath();
			break;
		}
		case 17:
		{
			PrintTitle("НАЙТИ МАКСИМАЛЬНЫЙ ПОТОК");
			gtn.FindMaxFlow();
			break;
		}
		default:
		{
			return 0;
		}
		}
	}
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
