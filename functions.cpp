#include "names_of_functions.h"
#include <iostream>
using std::cout;
using std::cin;
int** inic(int size)
{
	int** spiral = new int* [size];
	for (int i = 0; i < size; i++)
	{
		spiral[i] = new int[size];
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			spiral[i][j] = 0;
		}
	}
	return spiral;
}
void print(int** spiral, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << spiral[i][j] << '\t';
		}
		cout << '\n';
	}
}
void transponition(int**& spiral, int& size)
{
	int** a = new int* [size];
	for (int i = 0; i < size; i++)
	{
		a[i] = new int[size];

		for (int j = 0; j < size; j++)
		{
			a[i][j] = spiral[j][i];
		}
	}

	for (int i = 0; i < size; i++) {
		delete[] spiral[i];
	}
	delete[] spiral;
	spiral = new int* [size];
	for (int i = 0; i < size; i++)
	{
		spiral[i] = new int[size];
		for (int j = 0; j < size; j++)
		{
			spiral[i][j] = a[i][j];
		}
	}
	for (int i = 0; i < size; i++) {
		delete[] a[i];
	}
	delete[]a;
}
void reflection(int**& spiral, int& size)
{
	int** a = inic(size);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			a[i][j] = spiral[i][size - j - 1];
		}
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			spiral[i][j] = a[i][j];
		}
	}
}
void reflection_and_transponotion(int**& spiral, int size)
{
	reflection(spiral, size);
	transponition(spiral, size);
}
void fail(int& size)
{
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "ќшибка!¬ведите еще раз!\n->";
		cin >> size;
	}
}