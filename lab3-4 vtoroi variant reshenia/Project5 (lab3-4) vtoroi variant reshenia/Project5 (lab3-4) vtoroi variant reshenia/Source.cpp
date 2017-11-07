/*
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
int checkMax(int k, int max);
char checkWords(char a, char new_str, char text);

int main()
{
	char str[ARRAY_SIZE], a, new_str, text = " ";
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
	checkMax(K, max); // вызвали функцию 
	printf("%d \n", checkMax(K, max)); // и вывели (запомнили) значение которое получилось в функции int checkMax(int K, int max)
	checkWords(a, new_str, text); // вызвали функцию
	printf("%s \n", checkWords(a, new_str, text)); /* и вывели УЖЕ на экран ( так как это прописано в самой функции string checkWords(string a, string new_str, string text))
												   значение которое получилось в функции*/
	_getch();
	return 0; // вернули значение главной функции int main
}

int checkMax(int K, int max) // первая функция
{
	int i, max = 0;            // объявляем переменные
	for (i = 0; i < size; i++)
	{
		while (str[i] != '\0') // пока не конец строки делай 
		{
			K = 0; // обнуляем счётчик K при рассмотрении каждого слова
			while (str[i] != ' ') // пока не пробел ( то есть не закончилось слово) делай
			{
				if (str[i] == 'M') // если элемент слова = М, то его записываем в K
					K = K + 1;
				if (max < K) // если max < K, то в переменную max записываем значение K
					max = K; // количество букв М
			}
		}
	}
	return max; // возвращаем значение max, которая содежит максимальное число встречающихся в словах буквы M
}

char checkWords(char a, char new_str, char text) // вторая функция
{
	int i;                  // объявляем переменные
	char text = " ";
	for (i = 0; i < size; i++)
	{
		while (str[i] != '\0') // пока не конец строки делай 
		{
			a = " "; //  когда заканчивается слово мы обнуляем переменную а , чтобы снова составить слово
			while (str[i] != ' ') // пока не пробел ( то есть не закончилось слово) делай
			{
				{
					a = a + str[i]; // по буквам составляем слово
				}

				if (a == max) // если слово содержит максимальное количество букв М, то мы его записываем в new_str
				{
					new_str = a; // выводим слово
					text = text + " " + new_str; // записываем все слова new_str (с максимальным кол-ом буквы М)
				}
			}
		}
	}
	printf("words with the maximum number of M %s \n", text); // выводим слова с максимальным количеством M
	return text; // возвращаем значение переменной text, которая содержит все слова с максимальным кол-ом М
}
