#include <iostream>
using namespace std;

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);
int* push_back(int* arr, int& n, int value);
int* push_front(int* arr, int& n, int value);
int* insert(int* arr, int& n, int value, int index);
int* pop_back(int* arr, int& n, int value);
int* pop_front(int* arr, int& n, int value);
int* erase(int* arr, int& n, int index);


void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите количество элементов массива: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);
	int value, index;
	/*cout << "Введите добавляемое значение в конец массива: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);
	cout << "Введите добавляемое значение в начало массива: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);
	cout << "Введите добавляемое значение в массив  и индекс, добавляемого элемента: "; cin >> value >> index;
	arr = insert(arr, n, value, index);
	Print(arr, n);
	cout << "Массив после удаления последнего элемента: " << endl;
	arr = pop_back(arr, n, value);
	Print(arr, n);
	cout << "Массив после удаления первого элемента: " << endl;
	arr = pop_front(arr, n, value);
	Print(arr, n);*/
	cout << "Введите индекс элемента, который нужно удалить: "; cin >> index;
	arr = erase(arr, n, index);
	Print(arr, n);
	delete[] arr;
}
void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
	}
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << "\n";
}
int* push_back(int* arr, int& n, int value)
{	//1. Создаём буфферный массив нужного размера
	int* buffer = new  int[n + 1];
	//2. копируем все значения
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3. Удаляем исходный массив
	delete[] arr;
	//4. Подменяем адрес исходного массива адресом нового массива
	arr = buffer;
	buffer = nullptr;
	//5. И только после этого в массив arr можно добавить значение
	arr[n] = value;
	//6. После добавления элемента в массив, количество его элементов увеличивается на один
	n++;
	return arr;
}
int* push_front(int* arr, int& n, int value)
{
	int* buffer = new  int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i+1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	buffer = nullptr;
	arr[0] = value;
	n++;
	return arr;
}
int* insert(int* arr, int& n, int value, int index)
{
	if (index > n + 1) cout << "Введён некорректный индекс!\n";
	else
	{
		int* buffer = new  int[n + 1];
		for (int i = 0; i < index; i++)
		{
			buffer[i] = arr[i];
		}
		for (int i = index; i < n; i++)
		{
			buffer[i + 1] = arr[i];
		}
		delete[] arr;
		arr = buffer;
		buffer = nullptr;
		arr[index] = value;
		n++;
	}
	return arr;
}
int* pop_back(int* arr, int& n, int value)
{
	int* buffer = new  int[n - 1];
	for (int i = 0; i < n-1; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	buffer = nullptr;
	n--;
	return arr;
}
int* pop_front(int* arr, int& n, int value)
{
	int* buffer = new  int[n - 1];
	for (int i = 1; i < n; i++)
	{
		buffer[i-1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	buffer = nullptr;
	n--;
	return arr;
}
int* erase(int* arr, int& n, int index)
{
	if (index > n) cout << "Введён некорректный индекс!\n";
	else
	{
		int* buffer = new  int[n - 1];
		for (int i = 0; i < index; i++)
		{
			buffer[i] = arr[i];
		}
		for (int i = index; i < n-1; i++)
		{
			buffer[i] = arr[i+1];
		}
		delete[] arr;
		arr = buffer;
		buffer = nullptr;
		n--;
	}
	return arr;
}





