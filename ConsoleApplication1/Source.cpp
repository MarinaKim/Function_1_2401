#include<stdio.h>
#include<locale.h>
#include<iostream>
#include<stdint.h>
#include<time.h>

float f(int h, int m, int s);
void findMax();
int isLeap(int year);
void getCountDaysInMonth_5(int year, int month, int day);
int GetCountDaysInMonth(int month, int year);
int Task9(char letter);


using namespace std;

void main()
{
	int n;
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	do
	{
		cout << "введите номер задания:";
		cin >> n;

		switch (n) {
			//1.	1.	Напишите функцию int f(int h, int m, int s), которая принимает три целых аргумента 
			//(часы h, минуты m и секунды s) и возвращает количество секунд, прошедших с начала дня
		case 1: {

			int difTime = f(9, 0, 0);
			cout << f(9, 0, 0);
			cout << endl;
		}break;

		case 2: {
			findMax();

		}break; \
			//	Дата некоторого дня характеризуется тремя натуральными числами : g(год), m(порядковый номер месяца)
				//и n (число). По заданным g, n и m определить 
				//(Определить функцию, подсчитывающую количество дней в том или ином месяце):
				//a.дату предыдущего дня;
				//b.дату следующего дня
				////6.	В обеих задачах рассмотреть два случая :
				//a.заданный год не является високосным;
				//b.заданный год может быть високосным
		case 3: {
			cout << "введите год: ";
			int year;
			cin >> year;
			cout << "введите месяц: ";
			int month;
			cin >> month;
			cout << "введите день: ";
			int day;
			cin >> day;

			getCountDaysInMonth_5(year, month, day);
		}break;
		case 4: {
			char letter;
			cout << "введите букву, которую необходимо посчитать: ";
			cin >> letter;

		int  countLetter=Task9(letter);
		cout << "кол-во: " << countLetter << endl;
		}break;
		}
	} while (n > 0);
}

//1.	1.	Напишите функцию int f(int h, int m, int s), которая принимает три целых аргумента 
//(часы h, минуты m и секунды s) и возвращает количество секунд, прошедших с начала дня

float f(int h, int m, int s)
{
	time_t rawtime;
	struct tm*timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);

	int startDayH = 6;
	int startDayM = 00;
	int startDayS = 00;

	float totalSeconds = (timeinfo->tm_hour - startDayH) * 3600;
	totalSeconds += (timeinfo->tm_min) * 60;

	return totalSeconds;
}

//2.	4.	Даны шесть различных чисел. 
//Определить максимальное из них.
//(Определить функцию, находящую максимум из двух различных чисел.)

void findMax()
{
	srand(time(NULL));

	int a[6];
	int max = 0;

	for (int i = 0; i < 6; i++)
	{
		a[i] = -1 + rand() % 50;
		if (max < a[i])
			max = a[i];
	}
	cout << "max= " << max << endl;
}

//5.	Дата некоторого дня характеризуется тремя натуральными числами: g (год), m (порядковый номер месяца) 
//и n (число). По заданным g, n и m определить 
//(Определить функцию, подсчитывающую количество дней в том или ином месяце):
//a.дату предыдущего дня;
//b.дату следующего дня

void getCountDaysInMonth_5(int year, int month, int day)
{
	int leap = isLeap(year);
	//дату предыдущего дня;
	if ((day < 1 && day>31)&&(month<1||month>12))
	{
		cout << "Введите правильную дату." << endl;
	}
	if (day == 1)
	{
		if (day == 1 && month == 1)
			year = year - 1;
		if (month == 1)
			month = 12;
		else
			month = month - 1;

		day = GetCountDaysInMonth(month, year);

	}
	else
		day = day - 1;
	cout << "дату предыдущего дня: " <<
		day << "." <<
		month << "." <<
		year << endl;
}

//Функция, определяющая високосный день или нет
int isLeap(int year)
{
	int isLeap = 0;
	if ((year % 4 == 0 && year % 100) || (year % 400 == 0))
		return 1;
	else
		return 0;
}

// Функция возвращающая кол-во дней в месяце
int GetCountDaysInMonth(int month, int year)
{

	if (month == 4 || month == 6 || month == 9 || month == 11)
		return 30;
	else if (month == 2)
	{
#pragma region MyRegion

		if (isLeap(year) == 1) //visokosnii
			return 29;
		else
			return 28;

		/* return isLeap(year)==1 ? 29:28*/ // 2-й вариант: использование тернального оператора
#pragma endregion;
	}
	else
		return 31;
}

//9.	Составить программу для нахождения общего количества заданной буквы  в трех заданных предложениях.
//(Определить функцию для расчета количества некоторой буквы в предложении.)

int Task9(char letter)
{
	char str1[20], str2[20], str3[20];

	cout << "введите предложение: " << endl;
	for (int i = 0; i < 20; i++)
	{
		//указатель на массив
		
		str1[i] = getchar();
	}
	int countLetter = 0;
	for (int i = 0; i < 20; i++)
	{
		if (letter == str1[i])
			countLetter++;
	}
	/*
	2-вариант с gets_s*/
	cout<<"введите вторую строку:";
	char *result;
		result=gets_s(str2);
	for (int i = 0; i < 20; i++)
	{
		if (letter == str2[i])
			countLetter++;
	}
	return countLetter;
}

