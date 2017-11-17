/*
Васильченко Никита Сергеевич
Лабораторная работа №3.
Вариант №4
Задание: Написать программу, которая во вводимом с клавиатуры тексте выберет слова, количество букв "М" в которых будет максимально, и выведет их на экран.
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
	printf("%s", WordM); // вывод слов с максимальным количеством м 
	system("pause");
}

int main()
{
	char *words; // указатель на массив 
	int TextLength = 0; // длина всего текста
	printf("Enter text length: "); // ввод ддлины текста
	scanf("%d", &TextLength); 
	words = (char*)malloc((TextLength+2) * sizeof(char)); // выделение памяти на массив
	printf("enter text: "); 
	getchar();
	fgets(words, TextLength + 2, stdin); // ввод текста
	SearchWords(words); // вызов функции
    return 0;
}

