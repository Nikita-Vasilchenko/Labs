/*
Васильченко Никита Сергеевич
Лабораторная работа №5.
Вариант №4
Задание:Написать программу, которая записывает с клавиатуры в файл структуру
согласно выданному варианту задания. В качестве разделителя полей структуры
использовать символ табуляции. В программе реализовать:
а) дополнение существующего массива структур новыми структурами;
б) вывод на экран содержимого массива структур;
в) упорядочение массива структур по заданному полю (элементу), например
государство по численности.
«Футбольная команда»: название, город, количество сыгранных игр, количество
очков (проигрыши, выигрыши, ничьи), количество игроков, фамилия тренера.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <cstring>
#include <algorithm>


struct Football
{
	char name[30];                //название 
	char city[30];                 //город
	int numberOfGamesPlayed; //количество сыгранных игр
	int points;                 // количество очков
	int numberOfPlayers;      // количество игроков
	char surnameOfTheTrainer[100]; // фамилия тренера
};

void printOutputMonitor(Football *play); 
void inputUser(Football *play); 
void outputToFile(Football *play);
void organizeStructuresPoints(Football *play);
void organizeStructuresGames(Football *play);
int cap = -1;
int main()
{
	Football play[1024];
	while (true) // бесконечный цикл
	{
		printf("vvedite 0 - dopolnit strukt, 1 - yporiadothit po ochkam, 2 - yporiadothit po igram, 3 - vivod v file, 4 - vivod na monitor, 5 - exit");
		int c = 0;
		scanf("%d", &c); // пользователь вводит номер операции 
		if (c == 0)
		{
			inputUser(play);
		}
		else if ((c == 1)&&(cap != -1))
		{
			organizeStructuresPoints(play);
		}
		else if ((c == 2) && (cap != -1))
		{
			organizeStructuresGames(play);
		}

		else if ((c == 3) && (cap != -1))
		{
			outputToFile(play);
		}
		else if ((c == 4) && (cap != -1))
		{
			printOutputMonitor(play);
		}
		else if (c == 5)
		{
			return 0;
		}

	}
}

void inputUser(Football *play)   // функция заполнения структуры пользователем
{
	cap++; // считает сколько раз пользователь заполнил структуру

		printf("\n enter all the data in turn\t"); //введите по очереди все данные 

		printf("\n enter name\t"); //название 
		scanf("%s", &play[cap].name);
		
		printf("\n enter city\t"); //город
		scanf("%s", &play[cap].city);

		printf("\n enter number of games played\t"); //количество сыгранных игр
		scanf("%d", &play[cap].numberOfGamesPlayed);

		printf("\n enter points\t"); //количество очков
		scanf("%d", &play[cap].points);

		printf("\n enter number of players\t"); // количество игроков
		scanf("%d", &play[cap].numberOfPlayers);

		printf("\n enter surname of the trainer\t"); //фамилия тренера
		scanf("%s", &play[cap].surnameOfTheTrainer);
		
}

void outputToFile(Football *play) // функция вывода в файл записанной структуры пользователем 
{
	FILE *Out = fopen("C:/Users/Никита/source/repos/LAB 5-4/Debug/output.txt", "w");
	for (int i = 0; i < cap + 1; i++) // выводим все элементы массива структур 
	{
		fprintf(Out, "%s\t", &play[i].name);   
		fprintf(Out, "%s\t", &play[i].city);
		fprintf(Out, "%d\t", &play[i].numberOfGamesPlayed);
		fprintf(Out, "%d\t", &play[i].points);
		fprintf(Out, "%d\t", &play[i].numberOfPlayers);
		fprintf(Out, "%s\t", &play[i].surnameOfTheTrainer);
	}
	fclose(Out);
}

void organizeStructuresPoints(Football *play) // функция упорядочевания 
{
	int c = 0;
	for (int i = 0; i < cap; i++) // пузырьком по колличеству очков сортируем       
	{
		for (int j = cap - 1; j >= i; j--) // кол-во элементов 
		{
			if (play[j].points < play[j + 1].points)
			{
				c = play[j].points;
				play[j].points = play[j + 1].points;
				play[j + 1].points = c;
				std::swap(play[j], play[j + 1]);

			}
		}
	}
}

void organizeStructuresGames(Football *play) // функция упорядочевания 
{
	int c = 0;
	for (int i = 0; i < cap; i++) // пузырьком по колличеству сыгранных игр сортируем       
	{
		for (int j = cap - 1; j >= i; j--)  
		{
			if (play[j].numberOfGamesPlayed < play[j + 1].numberOfGamesPlayed)
			{
				c = play[j].numberOfGamesPlayed;
				play[j].numberOfGamesPlayed = play[j + 1].numberOfGamesPlayed;
				play[j + 1].numberOfGamesPlayed = c;
				std::swap(play[j], play[j + 1]);

			}
		}
	}
}

void printOutputMonitor(Football *play)  // вывод на экран
{
	for (int i = 0; i < cap; i++) // выводим все элементы массива структур 
	{
		printf("%s\t", &play[i].name);
		printf("%s\t", &play[i].city);
		printf("%d\t", &play[i].numberOfGamesPlayed);
		printf("%d\t", &play[i].points);
		printf("%d\t", &play[i].numberOfPlayers);
		printf("%s\t", &play[i].surnameOfTheTrainer);
	}
}