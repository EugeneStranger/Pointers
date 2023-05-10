#include <iostream>
using namespace std;
void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

void main()
{
	setlocale(LC_ALL, "");
	int n=10;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);
	int even_counter = 0, odd_counter = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0)  even_counter++;
		else				  odd_counter++;
	}
	int* even = new int[even_counter];
	int* odd = new int[odd_counter];
	for (int i = 0, k = 0, j = 0; i < n; i++)
	{
		//if (arr[i] % 2 == 0)  even[k++] = arr[i]; 
		//else				  odd[j++] = arr[i]; 
		(arr[i] %2 ==0 ? even[k++] : odd[j++]) = arr[i];
	}
	Print(even, even_counter);
	Print(odd,odd_counter);
	delete[] arr, even, odd;
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

