#include <iostream>
#include<conio.h>
#include "names_of_functions.h"
using std::cout;
using std::cin;

int main()
{
	setlocale(LC_ALL, "ru");
	int size;
	while (true)
	{
		cout << "Enter N or -1 to exit\n->";
		cin >> size;
		fail(size);
		if (size == -1)
		{
			exit(0);
		}
		int** matr = inic(size);
		int sum = 1;
		int ind = 0;
		int start = 0, stop = size - 1;
		if (start == stop)
		{
			matr[0][0] = 1;
		}
		else if (size == 0)
		{
			cout << "\nN must be more than 0\n";
		}
		else
		{
			while (sum <= size * size)
			{
				for (int h = 0; h < 4; h++)
				{

					for (int i = start; i < stop; i++)
					{
						matr[ind][i] = sum;
						sum += 1;
					}
					reflection_and_transponotion(matr, size);
				}
				ind += 1;
				start += 1;
				stop -= 1;
				if (start == stop)
				{
					matr[start][stop] = sum;
					sum += 1;
				}
			}
		}
		print(matr, size);
		cout << '\n';
	}
	cout << "Рабоат программы успешно завершена!\n\nСпасибо за работу!";
	_getch();
	return 0;
}