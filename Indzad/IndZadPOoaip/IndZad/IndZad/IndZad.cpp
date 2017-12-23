// IndZad.cpp: определяет точку входа для консольного приложения.
//
/*
Васильченко Никита Сергеевич
Индивидуальное задание
Задание:Перечислить ФИО клиентов,
пользовавшихся указанной услугой в
дневное время. Параметры: наименование услуги
*/
#include "stdafx.h"
#include "iostream"
#include <fstream> // работа с файлами
#include "string"
#include "vector" // массив
using namespace std;

vector<string> Params; // массив параметров
vector<string> InfoClient; // информ о клиентах
vector<string> ServiceName; // информ об услугах
vector<string> InfoServiceProvided; // о предоставленных услугах(какаими пользовался)
vector<string> ParamNumber; // записываем номер услуги
vector<string> ClientsNames; // ФИО пользователей которые подошли по заданию

void __ParamsRead__() // Считывает параметры из файла парам и записываем в массив
{
	string text = {};
	ifstream TextInput("C:/IndZadPOoaip/IndZad/Debug/Param.ini");
	while (!TextInput.eof()) // пока не конец файла
	{
		getline(TextInput, text, '\n'); // считываем текст
		Params.insert(Params.end(), text); // записать в конец  массива текст 
	}
	TextInput.close(); // прекращаем работу с файлом 
}
void __SearchParamNuber__() // поиск номера услуги которая содержится в параметрах (указаны пользователем)
{
	for (int i = 0; i < Params.size(); i++) // пока не конец массива
	{
		for (int m = 0; m < ServiceName.size()-1; m=m+2) // с шагом два для просмотра названий услуг  (лежат два параметра)
		{
			if (Params[i] == ServiceName[m]) // если совпали названия услуг
			{
				ParamNumber.insert(ParamNumber.end(), ServiceName[m+1]); // записываем номер услуги (к примеру 1 или 3)
			}
		}
	}
}
void __InfoClientRead__() // Считываем первые два элемента файла ФИО и номер телефона
{
	string text = {};
	int Count = 0;// кол-во элементов
	int pos = 0; // позицию запятой находит
	ifstream TextInput("C:/IndZadPOoaip/IndZad/Debug/ClientInfo.txt");
	while (!TextInput.eof()) // пока не конец файла
	{
		getline(TextInput, text, '\n');
		for (int i = 0; i < text.length(); i++)// цикл до конца строки
		{
			if ((text[i] == ',')||(i==text.length()-1))// если запятая или конец строки
			{
				Count += 1;
				if (Count < 3)
				{
					InfoClient.insert(InfoClient.end(), text.substr(pos, i - pos));// добовляет в массив элементы файла
					pos = i + 2;
				}
			}
		}
		Count = 0; // и так для каждой строки
		pos = 0;
	}
	TextInput.close();// прекращение работы с файлом
}
void __ServiceNameRead__() // Считывает названия услуг и их кода
{
	string text = {};
	int Count = 0; // кол-во элементов
	int pos = 0; // позицию запятой находит
	ifstream TextInput("C:/IndZadPOoaip/IndZad/Debug/ServiceName.txt");
	while (!TextInput.eof()) 
	{
	getline(TextInput, text, '\n');
	for (int i = 0; i < text.length(); i++) // цикл до конца строки
	{
		if ((text[i] == ',') || (i == text.length() - 1)) // если запятая или конец строки
		{
			Count += 1;
			if (Count < 3)
			{
				ServiceName.insert(ServiceName.end(), text.substr(pos, i - pos)); // добовляет в массив элементы файла
				pos = i + 2;
			}
		}
	}
	Count = 0;// и так для каждой строки
	pos = 0;
	}
	TextInput.close(); // прекращение работы с файлом
}
void __InfoServiceProvidedRead__() // считываем всю информ из файла о предоставленных услугах. Всё записываем в один массив.
{
	string text = {}; // текст одной строки файла
	int pos = 0;
	ifstream TextInput("C:/IndZadPOoaip/IndZad/Debug/ServiceProvided.txt");
	while (!TextInput.eof())
	{
		getline(TextInput, text, '\n');
		for (int i = 0; i < text.length(); i++)
		{
			if (text[i] == ',')
			{
				InfoServiceProvided.insert(InfoServiceProvided.end(), text.substr(pos, i - pos)); // записываем по элементам 
				pos = i + 2;
			}
			else if (i == text.length() - 1) // если уже нет запятой записываем последний элемент в массив
			{
				InfoServiceProvided.insert(InfoServiceProvided.end(), text.substr(pos, i - pos + 1));
			}
		}
		pos = 0;
	}
	TextInput.close();
}
void __TimeSort__() // Перевод времени в секунды (пользование услуги)
{
	int len = 0; // длина элемента 
	for (int i = 2; i < InfoServiceProvided.size() - 1; i = i + 4) // В цикле рассматриваем каждый второй элемент начиная с второго элемента и с шагом четыре
	{
		len = InfoServiceProvided[i].length(); // записал длину  второго элемента строки
		for (int m = 0; m < len - 1; m++)
		{
			string Hours;
			string Minutes;
			string Seconds;
			int Time = 0; //переменная хранящая время в секундах
			int Pos = 0;
			if (InfoServiceProvided[i][m] == ' ')
			{
				InfoServiceProvided[i] = InfoServiceProvided[i].substr(m + 1, len - m - 1); // оставляет только время и его уже рассматриваем
				Hours = InfoServiceProvided[i].substr(0, 2); // начинает с нуля и с шагом два и тд.
				Minutes = InfoServiceProvided[i].substr(3, 2);
				Seconds = InfoServiceProvided[i].substr(6, 2);
				InfoServiceProvided[i] = to_string(atoi(Hours.c_str()) * 3600 + atoi(Minutes.c_str()) * 60 + atoi(Seconds.c_str())); // (atoi перевод в число) Время переводим в секунды
			}
			len = InfoServiceProvided[i].length(); // записываем длину строки на данный момент с секундами
		}
	}
}
void __Search__() // поиск пользователей которые подходят (дневное время с 12 до 18)
{
	int AddTime = 0; // время пользования услугой
	int DayStart = 43200; // 12 часов в секундах 
	int DayFinist = 64800; //18 часов в секундах
	for (int i = 1; i < InfoServiceProvided.size(); i = i + 4) // рассматривает только номера услуг в предоставленных то есть все
	{
		if (InfoServiceProvided[i + 2] != "#") // если последний элемент не решётка(время пользования)
		{
			AddTime = atoi(InfoServiceProvided[i + 2].c_str()); // записать ввиде числа
		}
		for (int m = 0; m < ParamNumber.size(); m++) // только нужные номера услуг смотрит
		{
			if (InfoServiceProvided[i] == ParamNumber[m]) // если совпали номера
			{
				int SubTime = atoi(InfoServiceProvided[i + 1].c_str()); // записываем время начала пользования услугой в секундах(уже находили)
				if (((SubTime >= DayStart) && (SubTime <= DayFinist))||((SubTime<DayStart)&&(SubTime+AddTime>=DayStart)))// если попал в дневное время или какой-то промежуток попал в дневное время то
				{
					for (int n = 1; n < InfoClient.size(); n = n + 2) // поиск ФИО. Рассматривает только номер телефона
					{
						if (InfoClient[n] == InfoServiceProvided[i - 1]) // если номер клиента совпал с номером который пользовался услугой
						{
							ClientsNames.insert(ClientsNames.end(), InfoClient[n - 1]); // то записываем ФИО
						}
					}
				}
			}
		}
	}
	AddTime = 0;
}
void __OutInFile__() // Вывод в файл подходящих пользователей ФИО
{
	ofstream TextOut("C:/IndZadPOoaip/IndZad/Debug/Output.txt"); // открыть файл для записи
	for (int i = 0; i < ClientsNames.size(); i++)
	{
		TextOut << ClientsNames[i] << "\n"; // вывод в файл ФИО
	}
	TextOut.close();
}
int main()
{
	__ParamsRead__();
	__ServiceNameRead__();
	__SearchParamNuber__();
	__InfoClientRead__();
	__InfoServiceProvidedRead__();
	__TimeSort__();
	__Search__(); 
	__OutInFile__();
    return 0;
}

