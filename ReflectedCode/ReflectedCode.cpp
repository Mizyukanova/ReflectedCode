// ReflectedCode.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<iomanip>
#include <string> 

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int q = 4;
	int numberToConvert;
	string convertedNumber;
	int reflectedZoneLength;
	int maxNumberToConvert;

	cout << "Введите число в 10 системе счисления, чтобы составить таблицу значений: ";
	cin >> maxNumberToConvert;

	int decadesCount = log(maxNumberToConvert)/log(4.0) + 1;

	for (numberToConvert = 0; numberToConvert < maxNumberToConvert; numberToConvert++)
	{
		int decadeNumber = 0;
		int reflectedZoneNumber;
		convertedNumber.clear();

		cout << setw(int(log(maxNumberToConvert))) << numberToConvert << setw(0) << " ";
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

		for (; decadeNumber < decadesCount; decadeNumber++)
		{
			convertedNumber.insert(decadeNumber, "0");
		}

		reverse(convertedNumber.begin(), convertedNumber.end());
		cout << convertedNumber << endl;
	}
	
	//cout << "Рефлексивный код с основанием " << q << ": ";
	//cout << convertedNumber;
}
