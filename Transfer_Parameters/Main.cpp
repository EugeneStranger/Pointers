//Reference - переменная, которая содержит адрес другой переменной
#include <iostream>
using namespace std;

#define delimiter "\n-------------------------\n"

void Exchange(int& a, int& b);

void main()
{
	setlocale(LC_ALL, "");
	int a = 2, b = 3;
	cout << a << "\t\t" << b << endl;
	cout << &a << "\t" << &b << delimiter << "\n";
	Exchange(a , b);
	cout << a << "\t\t" << b << endl;
	cout << &a << "\t" << &b << delimiter << "\n";

}
void Exchange(int& a, int& b)
{
	int buffer = a;
	a = b;
	b = buffer;
	cout << a << "\t\t" << b << endl;
	cout << &a << "\t" << &b << delimiter << "\n";
}
