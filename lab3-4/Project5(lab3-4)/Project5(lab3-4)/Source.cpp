﻿/*
Васильченко Никита Сергеевич
Лабораторная работа №3.
Вариант №4
Задание: Написать программу, которая во вводимом с клавиатуры тексте выберет слова, количество букв "М" в которых будет максимально, и выведет их на экран.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <string.h>
#define ARRAY_SIZE 100
int main()
{
	char str[ARRAY_SIZE], a, new_str, text;
	int i, size, K, max;
	printf("enter text\n"); //введите текст
	fgets(str, 100, stdin); // ввели способ ввода клавиатура 
	size = strlen(str); // размер текста, который получился после ввода в массиве символов str
	if (size > ARRAY_SIZE || size < 1);
	{
		printf("invalid input");
		_getch();
		return 0;
	}
	for (i = 0; i < size; i++)
	{
		while (str[i] != '\0') // пока не конец строки делай 
		{
			while (str[i] != ' ') // пока не пробел ( то есть не закончилось слово) делай
			{
				K = 0; // обнуляем счётчик K
				if (str[i] == 'M') // если элемент слова = М, то его записываем в K
					K = K + 1;
				if (max < K) // если max < K, то в переменную max записываем значение K
					max = K; // количество букв М
			}
		}

		while (str[i] != '\0') // пока не конец строки делай 
		{
			while (str[i] != ' ') // пока не пробел ( то есть не закончилось слово) делай
			{
				{
					a = ' ';
					a = a + str[i]; // по буквам составляем слово
				}
				text = ' ';
				if (a = max) // если слово содержит максимальное количество букв М, то мы его записываем в new_str
					new_str = a; // выводим слово
				text = text + ' ' + new_str; // записываем все слова new_str (с максимальным кол-ом буквы М) 
			}
		}
	}
	printf("words with the maximum number of M %s \n", text); // слова с максимальным числом M
	_getch();
	return 0;
}
