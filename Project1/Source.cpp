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
	cout << a << endl;		// ����� ���������� 'a' �� �����
	cout << &a << endl;		// ������ ������ ���������� 'a' ����� ��� ������
	cout << pa << endl;		// ����� ������ ���������� 'a', ����������� � ��������� 'pa'
	cout << *pa;			// ������������� ��������� 'pa' � ����� �� ����� �������� �� ������
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
& - (�������� ������ ������ - Adress-of operator) ������� ��������, ������� ���������� ����� ������ �������� (�������� ������ ������)
* - (�������� ������������� - Dereference operator) ������� ��������, ������� ���������� �������� �� ������
*/