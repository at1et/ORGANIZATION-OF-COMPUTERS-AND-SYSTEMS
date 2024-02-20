#include <iostream>
#include <string>
#include  <cmath>

using namespace std;

int hexCharToInt(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	} else if (c >= 'A' && c <= 'F') {
		return 10 + (c - 'A');
	}
	else if (c >= 'a' && c <= 'f') {
		return 10 + (c - 'a');
	}
	return -1; // недопустимый символ
}

double hexToDec(string hexFraction) {
	double decimalFraction = 0.0;
	int length = hexFraction.length();
	int dotIndex = hexFraction.find('.');

	for (int i = 0; i < dotIndex; ++i) {
		if (hexFraction[i] != '.') {
			int digitValue = hexCharToInt(hexFraction[i]);
			decimalFraction += digitValue * pow(16, dotIndex - i - 1);
		}
	}
	// Преобразвоание дробной части
	for (int i = dotIndex +1; i < length ; ++i) {
		int digitValue = hexCharToInt(hexFraction[i]);
		decimalFraction += digitValue * pow(16, dotIndex - i);
	}
	return decimalFraction;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	string hexFraction;
	cout << "Введите шестнадцатеричное дробное число: ";
	cin >> hexFraction;

	double decimalFraction = hexToDec(hexFraction);
	cout << "Десятичное представление: " << decimalFraction << endl;
	return 0;
}
