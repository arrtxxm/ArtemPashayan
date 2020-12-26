#include "CS.h"

int CS::csMaxId = 0;
std::string Name;
int ShopsCount;
int WorkingShopsCount;
float Efficiency;


CS::CS(std::ifstream& fin)
{
	fin.ignore();
	std::getline(fin, Name);
	fin >> ShopsCount
		>> WorkingShopsCount
		>> Efficiency;
}

std::string CS::GetName() const
{
	return Name;
}

float CS::GetPercentUnusedShops() const
{
	return (1 - (WorkingShopsCount * 1.0f / ShopsCount)) * 100;
}

void CS::RecountShopsCount()
{
	std::cout << "Сейчас в КС есть " << ShopsCount << " цехов.\n";
	std::cout << "1 - Увеличить количество цехов\n"
		<< "2 - Уменьшить количество цехов\n"
		<< "0 и пр. - Отмена\n";
	int input;
	CheckValue(input, "Введите: ");
	switch (input)
	{
	case 1:
		ShopsCount++;
		std::cout << "Количество цехов успешно увеличено до " << ShopsCount << "\n";
		break;
	case 2:
		ShopsCount--;
		if (WorkingShopsCount > ShopsCount)
			WorkingShopsCount = ShopsCount;
		std::cout << "Количество цехов успешно уменьшено до " << ShopsCount << "\n";
	default:
		std::cout << "Вы вышли из режима редактирования.";
		break;
	}
}

void CS::RecountWorkingShopsCount()
{
	std::cout << "Сейчас в КС работают " << WorkingShopsCount << "/" << ShopsCount << " цехов\n";
	int workingShopsCount;
	CheckValue(workingShopsCount, "Введите новое количество работающих цехов: ");
	while (workingShopsCount > ShopsCount)
	{
		std::cout << "Ошибка! Количество работающих цехов не может быть больше общего количества цехов\n";
		CheckValue(workingShopsCount, "Введите новое количество работающих цехов: ");
	}
	WorkingShopsCount = workingShopsCount;
}

void CS::SaveToFile(std::ofstream& fout)
{
	fout << Name << '\n'
		<< ShopsCount << '\n'
		<< WorkingShopsCount << '\n'
		<< Efficiency << '\n';
}

std::ostream& operator << (std::ostream& out, const CS& cs)
{
	std::cout << "    Имя: " << cs.Name << "\n"
		<< "    Работает " << cs.WorkingShopsCount << "/" << cs.ShopsCount << " цехов" "\n"
		<< "    Эффективность: " << cs.Efficiency << "\n";
	return out;
}

std::istream& operator>>(std::istream& in, CS& cs)
{
	std::cout << "Введите имя компрессорной станции: ";
	std::cin.ignore();
	std::getline(std::cin, cs.Name);
	CheckValue(cs.ShopsCount, "Введите общее кол-во цехов: ");
	CheckValue(cs.WorkingShopsCount, "Введите кол-во работающих цехов: ");
	while (cs.WorkingShopsCount > cs.ShopsCount) {
		std::cout << "Ошибка! Кол-во работающих цехов не может быть больше общего кол-ва цехов\n";
		CheckValue(cs.WorkingShopsCount, "Пожалуйста, введите корректное кол-во работающих цехов: ");
	}
	CheckValue(cs.Efficiency, "Введите эффетивность компрессорной станции: ");
	return in;
}

CS::CS()
{
}
