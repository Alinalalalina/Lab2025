#include <iostream>

using namespace std;

// Функция обмена по значению
void obmen1(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}

// Функция обмена по указателям
void obmen2(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// Функция обмена по ссылкам
void obmen3(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
	int a = 2, b = 5;

	cout << "До обмена: a: " << a << ", b: " << b << endl;

	obmen1(a, b);
	cout << "После obmen1: a: " << a << ", b: " << b << endl;

	obmen2(&a, &b);
	cout << "После obmen2: a: " << a << ", b: " << b << endl;

	obmen3(a, b);
	cout << "После obmen3: a: " << a << ", b: " << b << endl;

	return 0;
}