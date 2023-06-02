#include <iostream>
using namespace std;

void FillRand(int arr[], const int n);
void FillRand(int** arr, const int rows, const int cols);
void Print(int arr[], const int n);
void Print(int** arr, const int rows, const int cols);
int** Allocate(const int rows, const int cols);
void Clear(int** arr, int rows);
int* push_back(int* arr, int& n, int value);
int* push_front(int* arr, int& n, int value);
int* insert(int* arr, int& n, int value, int index);
int* pop_back(int* arr, int& n, int value);
int* pop_front(int* arr, int& n, int value);
int* erase(int* arr, int& n, int index);

int** push_row_back(int** arr, int& rows,const int cols);
int** push_row_front(int** arr, int& rows, const int cols);
int** insert_row(int** arr, int& rows, const int cols, const int index);

void push_col_back(int** arr, const int rows, int& cols);
void push_col_front(int** arr, const int rows, int& cols);
void insert_col(int** arr, const int rows, int& cols, const int index);

int** pop_row_back(int** arr, int& rows,const int cols);
int** pop_row_front(int** arr, int& rows, const int cols);
int** erase_row(int** arr, int& rows, const int cols, const int index);

void pop_col_back(int** arr, const int rows, int& cols);
void pop_col_front(int** arr, const int rows, int& cols);
void erase_col(int** arr, const int rows, int& cols, const int index);

//#define DYNAMIC_ARR1
#define DYNAMIC_ARR2
#define delimeter "\n---------------------------------------------------------------\n\n"

void main()
{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_ARR1
	int n;
	cout << "Введите количество элементов массива: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);
	int value, index;
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
	arr = pop_back(arr, n, value);
	Print(arr, n);
	cout << "Массив после удаления первого элемента: " << endl;
	arr = pop_front(arr, n, value);
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
	int** arr = Allocate(rows, cols);
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimeter;
	/*arr = push_row_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimeter;
	arr = push_row_front(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "Введите индекс по которому нужно вставить пустую строку: "; cin >> index;
	cout << delimeter;
	if ((index>=0)&(index<=rows))
	{
		arr = insert_row(arr, rows, cols, index);
		Print(arr, rows, cols);
	}
	else cout << "Введён некорректный индекс!\n";
	cout << delimeter;
	push_col_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimeter;
	push_col_front(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimeter;
	cout << "Введите индекс по которому нужно вставить пустой столбец: "; cin >> index;
	if ((index >= 0) & (index <= cols))
	{
		insert_col(arr, rows, cols, index);
		Print(arr, rows, cols);
	}
	else cout << "Введён некорректный индекс!\n";
	cout << delimeter;*/
	arr = pop_row_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimeter;
	/*arr = pop_row_front(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "Введите индекс по которому нужно удалить строку: "; cin >> index;
	cout << delimeter;
	if ((index >= 0) & (index < rows))
	{
		arr = erase_row(arr, rows, cols, index);
		Print(arr, rows, cols);
	}
	else cout << "Введён некорректный индекс!\n";
	cout << delimeter;
	pop_col_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimeter;
	pop_col_front(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "Введите индекс по которому нужно удалить столбец: "; cin >> index;
	cout << delimeter;
	if ((index >= 0) & (index < cols))
	{
		erase_col(arr, rows, cols, index);
		Print(arr, rows, cols);
	}
	else cout << "Введён некорректный индекс!\n";*/
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
void FillRand(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)

			arr[i][j] = rand() % 100;
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
void Print(int** arr, const int rows, const int cols)
{
	
	/*for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << "\n";
	}
	cout << delimeter;*/
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << *(arr[i] + j) << "\t";
		}
		cout << "\n";
	}
}

int** Allocate(const int rows, const int cols)
{
	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}
	return arr;
}
void Clear(int** arr, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
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

int** push_row_back(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows + 1];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[rows] = new int[cols] {};
	rows++;
	return arr;
}
int** push_row_front(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows + 1];
	for (int i = 0; i < rows; i++)
	{
		buffer[i+1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[0] = new int[cols] {};
	rows++;
	return arr;
}
int** insert_row(int** arr, int& rows, const int cols, const int index)
{   
	int** buffer = new int* [rows + 1];
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
	arr[index] = new int[cols] {};
	rows++;
	return arr;
}

void push_col_back(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1] {};
		for (int j = 0; j < cols; j++)
		{
			buffer[j] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
void push_col_front(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1] {};
		for (int j = 0; j < cols; j++)
		{
			buffer[j+1] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
void insert_col(int** arr, const int rows, int& cols, const int index)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1] {};
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

int** pop_row_back(int** arr, int& rows, const int cols)
{
	delete[] arr[rows - 1];
	int** buffer = new int* [--rows];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	return buffer;
}
int** pop_row_front(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows - 1];
	for (int i = 0; i < rows - 1; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	rows--;
	return arr;
}
int** erase_row(int** arr, int& rows, const int cols, const int index)
{
	int** buffer = new int* [rows - 1];
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

void pop_col_back(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1];
		for (int j = 0; j < cols-1; j++)
		{
			buffer[j] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}
void pop_col_front(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols -1];
		for (int j = 0; j < cols; j++)
		{
			buffer[j] = arr[i][j+1];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}
void erase_col(int** arr, const int rows, int& cols, const int index)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols -1];
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