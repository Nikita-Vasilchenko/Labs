/*
Васильченко Никита Сергеевич
Лабораторная работа №4.
Вариант №4
Задание: Написать программу, которая считывает текст из файла и выберет слова,количество букв "М" в которых будет максимально, и выводит их в другой файл.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <conio.h>
#include <cstring>

void SearchWords(char *words) // получение указателя на массив
{
	char *p; // указатель на массив
	for (int i = 0; i<strlen(words); i++)	// в цикле рассматривает все слова		
	{											
		if (words[i] == '\n') 		// проверят по строкам 
		{										
			words[i]=' ';		// если встречаем символ перехода на новую строку (\n) заменяем на пробел. 			
		}						// То есть все слова из разных строк записываются в одну 
	}
	p = strtok(words, " ");  // разделение на слова, слово из массива записали в (p)
	int MaxM = 0; // каксимальное к-во "М"
	char WordM[100] = {}; // слова с каксимальным к-вом "М"
	while (p != NULL) // пока не законяатся слова
	{
		int count = 0; // колличество M в слове
		for (int i = 0; i<strlen(p); i++)			//поиск в слове "М"
		{											//
			if ((p[i] == 'm') || (p[i] == 'M'))		//
			{										//
				count += 1;							// если найдено м, то увеличить счётчик
			}										//
		}											//
		if (count != 0)
		{
			if (count > MaxM)		//
			{						//
				MaxM = count;		//если колличество м в слове больше максимального, то сделать его максимальным и записать это слово
				*WordM = {};		// обнулили массив
				strcat(WordM, p);	//
				strcat(WordM, " ");	//
			}
			else if (count == MaxM) // если колличество м совпадает с максимальным то добавить слово к существующему
			{
				strcat(WordM, p);
				strcat(WordM, " ");
			}
		}
		p = strtok(NULL, " "); // перейти к следующему слову
	}
	FILE *Output = fopen("C:/Users/Никита/source/repos/LAB 4 - 4/Debug/output.txt", "w"); // создали указатель и открыли файл на запись
	fprintf(Output, "%s", WordM); // записали в файл слова с максимальным кол-ом М
	fclose(Output); // закрыли указатель 
}

int main()
{
	char *words; // указатель на массив 
	int TextLength = 0; // длина всего текста(кол-во символов)
	FILE *Inp = fopen("C:/Users/Никита/source/repos/LAB 4 - 4/Debug/input.txt", "r"); // создали указатель и открыли файл для чтения
	if (Inp == NULL) // если в файле ничего нет, то выдаст сообщение "нет данных"
	{
		printf("No data!");
		_getch();
		return 0;
	}
	fscanf(Inp, "%d", &TextLength); // считывает количество символов из файла
	words = (char*)malloc((TextLength) * sizeof(char)); // выделение памяти на массив
	fread(words, sizeof(char), TextLength, Inp); // считывает все слова из файла
	fclose(Inp); //закрывает указатель 
	SearchWords(words); // вызов функции
	return 0;
}

