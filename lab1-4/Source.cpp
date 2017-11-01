/*
Васильченко Никита Сергеевич
Лабораторная работа №1.
Вариант №4
Задание: перевести дюймы в метры и выразить в аршинах.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#define INCHES_TO_METERS 39.3701
#define METERS_TO_ARSHINS 1.40607424072
int main()

{
	float meters, inches, arshins;
	printf("Inches and meters should be positive \n");
	printf("Please enter not an integer number of inches \n");
	int check = scanf("%f", &inches);

	if (check == 1 && inches >= 0)
	{
		meters = inches / INCHES_TO_METERS;
		printf("received meters %f \n", meters);

		arshins = meters * METERS_TO_ARSHINS;
		printf("received arshins %f \n", arshins);
	}
	else
	{
		printf("invalid input \n");
	}

	_getch();
	return 0;
}
