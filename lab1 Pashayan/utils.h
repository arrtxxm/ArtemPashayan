#pragma once
#pragma once
#include <iostream>
#include <string>

using namespace std;

template <typename T>
T CheckValue(string text, T min, T max)
{
	T value;
	cout << text;
	while (!(std::cin >> value) || value < min || value > max) {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << text;
	}
	return value;
}