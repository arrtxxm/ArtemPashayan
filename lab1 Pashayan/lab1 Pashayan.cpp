// lab1 Pashayan.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include < iostream >
#include < string >
#include < fstream >
using namespace std;

	
struct Pipe
{
	int id = 1;
	double Length = 0.0;
	int Diameter = 0;
	bool Repair = false;
	};

struct CS
{
	int id = 1;
	string Name = "";
	int Shop = 0;
	int WorkShop = 0;
	int Efficiency = 0;
};

template <typename V>
V CheckValue(V min, V max)
{
	V x;
	cout << "Выберите от " << min << " до " << max << ":";
	cin >> x;
	while (cin.fail() || x<min || x>max)
	{
		cin.clear();
		cin.ignore(10000000, '\n');
		cout << "Ошибка:Введите значение от " << min << " до " << max << ":";
		cin >> x;
	}
	return x;
}

Pipe CreateNewPipe()
{
	Pipe newPipe;
	cout << "Характеристики трубы:" << endl;
	newPipe.id = 1;
	newPipe.Repair = false;
	cout << "Введите длину трубы в метрах:" << endl;
	newPipe.Length = CheckValue(0.0, 10000000.0);
	cout << "Введите диаметр трубы в миллиметрах: " << endl;
	newPipe.Diameter = CheckValue(0, 10000000);
	return newPipe;
}

CS CreateNewCS()
{
	CS newCS;
	cout << "\nХарактеристики компрессорной станции:" << endl;
	newCS.id = 1;
	cout << "Введите имя компрессорной станции:";
	cin.get();
	getline(cin, newCS.Name);
	cout << "Введите количество цехов:" << endl;
	newCS.Shop = CheckValue(0, 10000000);
	do
	{
		cout << "Введите количество цехов в работе:" << endl;
		newCS.WorkShop = CheckValue(0, 10000000);
	} while (newCS.Shop < newCS.WorkShop);
	cout << "Введите эффективность трубы (от 1 до 10):" << endl;
	newCS.Efficiency = CheckValue(1, 10);
	return newCS;
}
	
void ShowPipe(const Pipe& p)
{
	cout << "\nИдентификатор трубы id = " << p.id << endl;
	cout << "Длина трубы = " << p.Length << endl;
	cout << "Диаметр трубы = " << p.Diameter << endl;
	cout << (p.Repair ? "Труба в ремонте" : "Труба не в ремонте") << endl;
}

void ShowСS(const CS& c)
{
	cout << "\nИнтендификатор компрессорной станции (id) = " << c.id << endl;
	cout << "Название компрессорной станции= " << c.Name << endl;
	cout << "Количество цехов = " << c.Shop << endl;
	cout << "Количество рабочих цехов = " << c.WorkShop << endl;
	cout << "Продуктивность = " << c.Efficiency << endl;
}

void toFilePipe(const Pipe& p)
{
	ofstream fout;
	fout.open("file.txt", ios::out);
	if (fout.is_open())
	{
		fout << p.id  << endl << p.Length << endl << p.Diameter << endl << p.Repair << endl;
		fout.close();
	}
}

void toFileCS(const CS& c)
{
	ofstream fout;
	fout.open("file.txt", ios::app);
	if (fout.is_open())
	{
		fout << c.id << endl << c.Name << endl << c.Shop  << endl << c.WorkShop << endl << c.Efficiency << endl;
		fout.close();
	}
}

Pipe fromFilePipe(ifstream& fin)
{
	Pipe p;
	fin >> p.id; 
	fin >> p.Length;
	fin >> p.Diameter;
	fin >> p.Repair;
	return p;
}

CS fromFileCS(ifstream& fin)
{
	CS c;
	fin >> c.id;
	fin >> c.Name;
	fin >> c.Shop;
	fin >> c.WorkShop;
	fin >> c.Efficiency;
	return c;
}

void Menu()
{
	cout << "1. Создать трубу" << endl;
	cout << "2. Создать компрессорную станцию" << endl;
	cout << "3. Просмотреть все объекты" << endl;
	cout << "4. Изменить статус ремонта трубы" << endl;
	cout << "5. Запуск/остановка цеха" << endl;
	cout << "6. Сохранить данные в файл" << endl;
	cout << "7. Считать данные из файла" << endl;
	cout << "8. Очистить консоль" << endl;
	cout << "9. Выход" << endl;
}

void ChangeStatus(bool& status)
{
	status = !status;
}

void StopWork(CS& c) 
{
	if (c.WorkShop > 0)
		{
		c.WorkShop--;
		}
	else
		{
		cout << "Нет рабочих цехов" << endl;
		}
}

void StartWork(CS& c) 
{


	if (c.WorkShop < c.Shop)
		{
			c.WorkShop++;
		}
	else
		{
			cout << "Все цеха в работе" << endl;
		}	
}

int main()
{
	setlocale(LC_ALL, "Russian");
	Pipe p;
	CS c;
	while (true)
	{
		Menu();
		int i = CheckValue(1, 9);
		switch (i)
		{
		case 1:
		{
			p = CreateNewPipe();
			break;
		}
		case 2:
		{
			c = CreateNewCS();
			break;

		}
		case 3:
		{
			ShowPipe(p);
			ShowСS(c);
			break;
		}
		case 4:
		{
			ChangeStatus(p.Repair);
			break;
		}
		case 5:
		{
			cout << "\t Выберите действие:" << endl;
			cout << "\t 1. Запуск цеха" << endl;
			cout << "\t 2. Остановка цеха" << endl;
			switch (CheckValue(1, 2))
			{
				case 1:
				{
					StartWork(c);
				}
				break;
				case 2:

				{
					StopWork(c);
				}
				break;
			}
		}
		case 6:
		{
			toFilePipe(p);
			toFileCS(c);
			break;
		}
		case 7:
		{
			ifstream fin;
			fin.open("file.txt", ios::in);
			if (fin.is_open())
			{
				p = fromFilePipe(fin);
				c = fromFileCS(fin);
			}
			else cout << "Ошибка:файла не существует" << endl;
			fin.close();
			break;
		}
		case 8:
		{
			system("cls");
			break;
		}
		case 9: 
		{
			return 0;
			break;
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
