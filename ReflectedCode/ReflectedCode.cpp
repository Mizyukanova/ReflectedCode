// ReflectedCode.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string> 

using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");
	int q = 4;
	int numberToConvert;
	string convertedNumber;
	int reflectedZoneLength;
	int decadeNumber = 0;
	int reflectedZoneNumber;
	
	cout << "Введите число в 10 системе счисления: ";
	cin >> numberToConvert;
	
	do 
	{
		int decade;
		int decadeStep = pow(q, decadeNumber);

		reflectedZoneLength = pow(q, (decadeNumber + 1));
		reflectedZoneNumber = numberToConvert / reflectedZoneLength;
		if (reflectedZoneNumber % 2)
		{
			decade = q - 1 - (numberToConvert % reflectedZoneLength) / decadeStep;
		}
		else
		{
			decade = (numberToConvert % reflectedZoneLength) / decadeStep;
		}
		convertedNumber.insert(decadeNumber, to_string(decade));
		decadeNumber++;
	} while (reflectedZoneNumber);
	
	reverse(convertedNumber.begin(), convertedNumber.end());

	cout << "Рефлексивный код с основанием " << q << ": ";
	cout << convertedNumber;
}
