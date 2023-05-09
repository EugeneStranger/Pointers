//POINTERS
#include <iostream>
using namespace std;

//#define POINTERS_BASICS
void main()
{
	setlocale(LC_ALL, "");
#ifdef POINTERS_BASICS
	int a = 2;
	int* pa = &a;
	cout << a << endl;		// Вывод переменной 'a' на экран
	cout << &a << endl;		// Взятие адреса переменной 'a' прямо при выводе
	cout << pa << endl;		// Вывод адреса переменной 'a', хранящегося в указателе 'pa'
	cout << *pa;			// Разыменование указателя 'pa' и вывод на экран значения по адресу
#endif;
	const int n = 10;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 20;
	}
	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i) << "\t";
	}
	cout << endl;
}

/*
& - (оператор взятия адреса - Adress-of operator) унарный оператор, который возвращает адрес своего операнда (оператор взятия адреса)
* - (оператор разыменования - Dereference operator) унарный оператор, который возвращает значение по адресу
*/