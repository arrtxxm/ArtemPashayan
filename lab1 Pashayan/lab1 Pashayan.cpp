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

template <typename T>
T GetCorrectNumber(T min, T max)
{
	T x;
	cout << "Введите значение от " << min << " до " << max << ":";
	cin >> x;
	while (cin.fail() || x<min || x>max)
	{
		cin.clear();
		cin.ignore(1000000, '\n');
		cout << "Введите значение от " << min << " до " << max << ":";
		cin >> x;
	}
	return x;
}
Pipe CreateNewPipe()
{
	Pipe newPipe;
	cout << "Введите характеристики трубы:" << endl;
	newPipe.id = 0;
	newPipe.Repair = false;
	cout << "Введите длину трубы в метрах" << endl;
	newPipe.Length = GetCorrectNumber(0.0, 10000000.0);
	cout << "Введите диаметр трубы в миллиметрах (мм) " << endl;
	newPipe.Diameter = GetCorrectNumber(0, 999999999);
	return newPipe;
}
CS CreatNewCS()
{
	CS newCS;
	cout << "\nСчитайте данные для компрессарных станций: " << endl;
	newCS.id = 1;
	cout << "Введите имя компрессорной станции: ";
	cin.get();
	getline(cin, newCS.Name);
	cout << "Введите количество цехов " << endl;
	newCS.Shop = GetCorrectNumber(0, 999999999);
	do
	{
		cout << "Введите количество цехов в работе " << endl;
		newCS.WorkShop = GetCorrectNumber(0, 999999999);
	} while (newCS.Shop < newCS.WorkShop); // проверка количество рбочих заводов между общим количеством заводов
	cout << "Введите эффективность трубы (1-10) " << endl;
	newCS.Efficiency = GetCorrectNumber(1, 10);
	return newCS;
}




	int main()
{
	Pipe p;
	CS c;
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
