﻿// laba 4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
#include <fstream>
#include <string>
int main()
{

	setlocale(LC_ALL, "ru");
	//1)
	ifstream File;
	File.open("Text.txt");
	string S;
	while (!File.eof())
	{
		getline(File, S);
		cout << S;


	}
	File.close();
	
	//2)
	//string S;
	//cout << "Введите строку:";
	//getline(cin, S);
	int k = 0;
	for (int i = 0; i < S.length(); i++)
	{
		if (S[i] == ' ')
		{
			for (int j = 1; j < S.length() - 1; j++)
			{
				if (S[i + j] == ' ' )
					k++;
				if (S[i + j] != ' ')
					break;
			}
			S.erase(i + 1, k);
		}
		k = 0;
	}
	//cout << S<<endl;

	for (int i = 0; i < S.length(); i++)
	{
		if (!(isalnum(S[i])) and S[i] != ' ' and i!= S.length()-1 )
		{
			for (int j = 1; j < S.length() - 1; j++)
			{
				if (S[i] == '.' and S[i + 1] == '.' and S[i + 2] == '.' )
				{
					i += 3;
					if (i + 2 != S.length() - 1)
						i -=1;
					break;
				}
				if (!(isalnum(S[i + j])) and S[i + j] != ' ' )
				{
					k++;
				}
				if (isalnum(S[i + j]) or S[i+j]==' ') {
					break;
				}
			}
			S.erase(i + 1, k);
		}
		k = 0;
	}
	//cout << S;

	for (int i = 1; i < S.length(); i++)
	{
		S[i] = tolower(S[i]);
	}
	cout <<"\n2)Исправленный текст:"<< S << "\n\n";

	//3)
	string S1;
	S1 = S;
	cout << "3)Слова последовательности в обратном порядке:";
	int l;
	while (S1.length() > S1.find(' '))
	{
		l = S1.rfind(' ');
		for (int j = l + 1; j < S1.length(); j++)
		{
			cout << S1[j];
		}
		cout << " ";
		S1 = S1.erase(l);
	}
	cout << S1<<"\n\n";

	//4)
	cout << "4)Все слова с заглавной буквы: ";
	string S2;
	S2 = S;
	int n;
	S2[0] = toupper(S2[0]);
	for (int i = 0; i < S2.length(); i++)
	{
		if (S2[i] ==' ')
			S2[i+1] = toupper(S2[i+1]);
		cout << S2[i];
	}
	cout << "\n\n";

	//5)
	string str;
	cout << "5)Введите подстроку ";
	getline(cin, str);
	int count = 0;
	int c = 0;
	for (int i = 0; i < (S.length() - (str.length() - 1)); i++)
	{
		if (S[i] == str[0])
		{
			count++;
			for (int j = 1; j < str.length(); j++)
			{
				if (S[i + j] == str[j])
				{
					count++;
				}
				if (S[i + j] != str[j])
					break;
			}
		}
		if (count == str.length())
			c++;
		count = 0;
	}
	if (c == 0)
		cout << "Подстрока не найдена";
	else
		cout << "Количество вхождений " << c;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
