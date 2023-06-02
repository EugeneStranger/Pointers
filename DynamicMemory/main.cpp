#include <iostream>
using namespace std;

void FillRand(int arr[], const int n);
void FillRand(double arr[], const int n);
void FillRand(char arr[], const int n);

void FillRand(int** arr, const int rows, const int cols);
void FillRand(double** arr, const int rows, const int cols);
void FillRand(char** arr, const int rows, const int cols);

template <typename T>void Print(T arr[], const int n);
template <typename T>void Print(T** arr, const int rows, const int cols);

template <typename T>T** Allocate(const int rows, const int cols);

template <typename T>void Clear(T** arr, int rows);

template <typename T>T* push_back(T* arr, int& n, T value);
template <typename T>T* push_front(T* arr, int& n, T value);
template <typename T>T* insert(T* arr, int& n, T value, int index);
template <typename T>T* pop_back(T* arr, int& n);
template <typename T>T* pop_front(T* arr, int& n);
template <typename T>T* erase(T* arr, int& n, int index);

template <typename T>T** push_row_back(T** arr, int& rows,const int cols);
template <typename T>T** push_row_front(T** arr, int& rows, const int cols);
template <typename T>T** insert_row(T** arr, int& rows, const int cols, const int index);

template <typename T>void push_col_back(T** arr, const int rows, int& cols);
template <typename T>void push_col_front(T** arr, const int rows, int& cols);
template <typename T>void insert_col(T** arr, const int rows, int& cols, const int index);

template <typename T>T** pop_row_back(T** arr, int& rows,const int cols);
template <typename T>T** pop_row_front(T** arr, int& rows, const int cols);
template <typename T>T** erase_row(T** arr, int& rows, const int cols, const int index);

template <typename T>void pop_col_back(T** arr, const int rows, int& cols);
template <typename T>void pop_col_front(T** arr, const int rows, int& cols);
template <typename T>void erase_col(T** arr, const int rows, int& cols, const int index);

//#define DYNAMIC_ARR1
#define DYNAMIC_ARR2
#define delimeter "\n---------------------------------------------------------------\n\n"

void main()
{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_ARR1
	int n;
	cout << "Введите количество элементов массива: "; cin >> n;
	typedef char DataType;
	DataType* arr = new DataType[n];
	FillRand(arr, n);
	Print(arr, n);
	int index;
	DataType value;
	cout << "Введите добавляемое значение в конец массива: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);
	cout << "Введите добавляемое значение в начало массива: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);
	cout << "Введите добавляемое значение в массив  и индекс, добавляемого элемента: "; cin >> value >> index;
	arr = insert(arr, n, value, index);
	Print(arr, n);
	cout << "Массив после удаления последнего элемента: " << endl;
	arr = pop_back(arr, n);
	Print(arr, n);
	cout << "Массив после удаления первого элемента: " << endl;
	arr = pop_front(arr, n);
	Print(arr, n);
	cout << "Введите индекс элемента, который нужно удалить: "; cin >> index;
	arr = erase(arr, n, index);
	Print(arr, n);
	delete[] arr;
#endif;
#ifdef DYNAMIC_ARR2
	int rows, cols, index;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество столбцов: "; cin >> cols;
	typedef double DataType;
	DataType** arr = Allocate<DataType>(rows, cols);
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimeter;
	arr = push_row_back(arr, rows, cols);
	cout << "Массив после добавления пустой строки в конец массива: " << endl;
	Print(arr, rows, cols);
	cout << delimeter;
	arr = push_row_front(arr, rows, cols);
	cout << "Массив после добавления пустой строки в начало массива: " << endl;
	Print(arr, rows, cols);
	cout << "Введите индекс по которому нужно вставить пустую строку: "; cin >> index;
	cout << delimeter;
	if ((index>=0)&(index<=rows))
	{
		arr = insert_row(arr, rows, cols, index);
		cout << "Массив после добавления пустой по индексу: " << endl;
		Print(arr, rows, cols);
	}
	else cout << "Введён некорректный индекс!\n";
	cout << delimeter;
	push_col_back(arr, rows, cols);
	cout << "Массив после добавления пустого столбца в конец массива: " << endl;
	Print(arr, rows, cols);
	cout << delimeter;
	push_col_front(arr, rows, cols);
	cout << "Массив после добавления пустого столбца в начало массива: " << endl;
	Print(arr, rows, cols);
	cout << delimeter;
	cout << "Введите индекс по которому нужно вставить пустой столбец: "; cin >> index;
	if ((index >= 0) & (index <= cols))
	{
		insert_col(arr, rows, cols, index);
		cout << "Массив после добавления пустого столбца по индексу: " << endl;
		Print(arr, rows, cols);
	}
	else cout << "Введён некорректный индекс!\n";
	cout << delimeter;
	arr = pop_row_back(arr, rows, cols);
	cout << "Массив после удаления пустой строки в конце массива: " << endl;
	Print(arr, rows, cols);
	cout << delimeter;
	arr = pop_row_front(arr, rows, cols);
	cout << "Массив после удаления пустой строки в начале массива: " << endl;
	Print(arr, rows, cols);
	cout << "Введите индекс по которому нужно удалить строку: "; cin >> index;
	cout << delimeter;
	if ((index >= 0) & (index < rows))
	{
		arr = erase_row(arr, rows, cols, index);
		cout << "Массив после удаления строки по индексу: " << endl;
		Print(arr, rows, cols);
	}
	else cout << "Введён некорректный индекс!\n";
	cout << delimeter;
	pop_col_back(arr, rows, cols);
	cout << "Массив после удаления пустого столбца в конце массива: " << endl;
	Print(arr, rows, cols);
	cout << delimeter;
	pop_col_front(arr, rows, cols);
	cout << "Массив после удаления пустого столбца в начале массива: " << endl;
	Print(arr, rows, cols);
	cout << "Введите индекс по которому нужно удалить столбец: "; cin >> index;
	cout << delimeter;
	if ((index >= 0) & (index < cols))
	{
		erase_col(arr, rows, cols, index);
		cout << "Массив после удаления пустого столбца по индексу: " << endl;
		Print(arr, rows, cols);
	}
	else cout << "Введён некорректный индекс!\n";
	Clear(arr, rows);
#endif;
}
void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
	}
}
void FillRand(double arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 10000;
		arr[i] /= 100;
	}
}
void FillRand(char arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 256;
	}
}
void FillRand(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)

			arr[i][j] = rand() % 100;
	}
}
void FillRand(double** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = double((rand() % 1000000)) / 1000;
		}
	}
}
void FillRand(char** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand();
		}
	}
}

template <typename T>void Print(T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << "\n";
}
template <typename T>void Print(T** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << *(arr[i] + j) << "\t";
		}
		cout << "\n";
	}
}

template <typename T>T** Allocate(const int rows, const int cols)
{
	T** arr = new T* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new T[cols];
	}
	return arr;
}
template <typename T>void Clear(T** arr, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}


template <typename T>T* push_back(T* arr, int& n, T value)
{	//1. Создаём буфферный массив нужного размера
	T* buffer = new  T[n + 1];
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
template <typename T>T* push_front(T* arr, int& n, T value)
{
	T* buffer = new  T[n + 1];
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
template <typename T>T* insert(T* arr, int& n, T value, int index)
{
	if (index > n + 1) cout << "Введён некорректный индекс!\n";
	else
	{
		T* buffer = new  T[n + 1];
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
template <typename T>T* pop_back(T* arr, int& n)
{
	T* buffer = new  T[n - 1];
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
template <typename T>T* pop_front(T* arr, int& n)
{
	T* buffer = new  T[n - 1];
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
template <typename T>T* erase(T* arr, int& n, int index)
{
	if (index > n) cout << "Введён некорректный индекс!\n";
	else
	{
		T* buffer = new  T[n - 1];
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

template <typename T>T** push_row_back(T** arr, int& rows, const int cols)
{
	T** buffer = new T* [rows + 1];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[rows] = new T[cols] {};
	rows++;
	return arr;
}
template <typename T>T** push_row_front(T** arr, int& rows, const int cols)
{
	T** buffer = new T* [rows + 1];
	for (int i = 0; i < rows; i++)
	{
		buffer[i+1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[0] = new T[cols] {};
	rows++;
	return arr;
}
template <typename T>T** insert_row(T** arr, int& rows, const int cols, const int index)
{   
	T** buffer = new T* [rows + 1];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < rows; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[index] = new T[cols] {};
	rows++;
	return arr;
}

template <typename T>void push_col_back(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1] {};
		for (int j = 0; j < cols; j++)
		{
			buffer[j] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
template <typename T>void push_col_front(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1] {};
		for (int j = 0; j < cols; j++)
		{
			buffer[j+1] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
template <typename T>void insert_col(T** arr, const int rows, int& cols, const int index)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1] {};
		for (int j = 0; j < index; j++)
		{
			buffer[j] = arr[i][j];
		}
		for (int j = index; j < cols; j++)
		{
			buffer[j + 1] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}

template <typename T>T** pop_row_back(T** arr, int& rows, const int cols)
{
	T** buffer = new T* [rows -1];
	for (int i = 0; i < rows-1; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	rows--;
	return arr;
}
template <typename T>T** pop_row_front(T** arr, int& rows, const int cols)
{
	T** buffer = new T* [rows - 1];
	for (int i = 1; i < rows; i++)
	{
		buffer[i-1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	rows--;
	return arr;
}
template <typename T>T** erase_row(T** arr, int& rows, const int cols, const int index)
{
	T** buffer = new T* [rows - 1];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < rows - 1; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
	rows--;
	return arr;
}

template <typename T>void pop_col_back(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols - 1];
		for (int j = 0; j < cols-1; j++)
		{
			buffer[j] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}
template <typename T>void pop_col_front(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols -1];
		for (int j = 0; j < cols; j++)
		{
			buffer[j] = arr[i][j+1];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}
template <typename T>void erase_col(T** arr, const int rows, int& cols, const int index)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols -1];
		for (int j = 0; j < index; j++)
		{
			buffer[j] = arr[i][j];
		}
		for (int j = index; j < cols-1; j++)
		{
			buffer[j] = arr[i][j+1];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}