/*
Васильченко Никита Сергеевич
Лабораторная работа №2.
Вариант №4
Задание: Написать программу, которая вычисляет сумму всех положительных элементов массива. Массив и его длина вводятся пользователем.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>

#include <stdlib.h> 
#include <malloc.h>
#define ARRAY_SIZE 100 
int main()
{
	int i, n, count = 0;
	printf("enter the number of elements in the array \n");
	scanf("%d", &n);
	int *a = malloc(sizeof(int) * n);

	if (n > ARRAY_SIZE || n < 1)
	{
		printf("invalid input");
		_getch();
		return 0;
	}
	for (i = 0; i < n; i++)
	{
		int check = 0;
		while (!check)
		{
			while (getchar() != '\n');
			printf("a[%d] = ", i);
			check = scanf("%d", &a[i]);
			if (check)
			{

				if (a[i] > 0)
				{
					count = count + a[i];
				}

			}
			else
			{
				printf("invalid input, enter again please \n");
			}
		}
	}
	printf("\n sum of positive numbers %d \n", count);
	_getch();
	return 0;
}
