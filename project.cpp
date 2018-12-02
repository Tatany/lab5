//В двумерном массиве хранятся результаты футбольных матчей. 
//Каждый элемент матрицы содержит информацию о результате игры i-й и j-й команд. 
//2 - i-я команда выиграла, 1 – ничья, 0 – i-я команда проиграла, -1 – команды не играли.
//Определить а) наиболее успешную команду; 
//б)вывести списки команд, которым еще предстоят игры.

#include "pch.h"
#include "stdio.h"
#include "locale.h"
#include "stdlib.h"
#include "time.h"

int GetSize(); //ввод размера массива
int Menu(); //вывод меню и выбор пункта меню
void InputResults(int** m, int s); //первый пункт меню - ввод результатов футбольных матчей с клавиатуры
void InputResultsRandom(int** m, int s); //второй пункт меню - ввод результатов футбольных матчей случайно
void FindTeamsDontPlay(int** m, int s); //четвертый пункт меню - вывод списков команд, которым еще предстоят игры
void OutputResults(int** m, int s); //пятый пункт меню - вывод результатов футбольных матчей
int Exit(); //шестой и седьмой пункт меню - повторный запуск программы и выход из программы

int main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));

	int prog = 0; //флаг выхода из программы
	do
	{
		int size = GetSize();
		int** massiv = NULL;
		massiv = new int*[size];
		for (int i = 0; i < size; i++)
		{
			massiv[i] = new int[size];
		}

		int wasEntered = 0; //флаг ввода элементов массива с клавиатуры
		int wasRandom = 0; //флаг заполнения массива случайными значениями

		int repeat = 0; //флаг повтора программы
		do
		{
			int menu = Menu();
			switch (menu)
			{
			case 1: //ввод результатов футбольных матчей с клавиатуры
				if (wasEntered == 1 || wasRandom == 1) //защита от ввода некорректного пункта меню
				{
					printf("\n\aОШИБКА! Результаты матчей уже введены.\nВыберите другой пункт меню.\n");
				}
				else
				{
					InputResults(massiv, size);
					printf("\nРезультаты матчей введены.\n");
					wasEntered = 1;
				}
				break;

			case 2: //ввод результатов футбольных матчей случайно
				if (wasEntered == 1 || wasRandom == 1) //защита от ввода некорректного пункта меню
				{
					printf("\n\aОШИБКА! Результаты матчей уже введены.\nВыберите другой пункт меню.\n");
				}
				else
				{
					InputResultsRandom(massiv, size);
					printf("\nРезультаты матчей введены случайно.\n");
					wasRandom = 1;
				}
				break;

			case 3: //определение наиболее успешной команды (определение строки с наибольшей суммой элементов)
				if (wasEntered == 0 && wasRandom == 0) //защита от ввода некорректного пункта меню
				{
					printf("\n\aОШИБКА! Сначала введите результаты футбольных матчей.\nВыберите другой пункт меню.\n");
				}
				else
				{
					//FindBestTeam(massiv, size);
				}
				break;

			case 4: //вывод списков команд, которым еще предстоят игры
				if (wasEntered == 0 && wasRandom == 0) //защита от ввода некорректного пункта меню
				{
					printf("\n\aОШИБКА! Сначала введите результаты футбольных матчей.\nВыберите другой пункт меню.\n");
				}
				else
				{
					FindTeamsDontPlay(massiv, size);
				}
				break;

			case 5: //вывод результатов футбольных матчей
				if (wasEntered == 0 && wasRandom == 0) //защита от ввода некорректного пункта меню
				{
					printf("\n\aОШИБКА! Сначала введите результаты футбольных матчей.\nВыберите другой пункт меню.\n");
				}
				else
				{
					OutputResults(massiv, size);
				}
				break;

			case 6: //повторный запуск программы
				printf("\nЗапустить программу повторно?\n(0) - нет, (1) - да\n");
				repeat = Exit();
				break;

			case 7: //выход из программы
				printf("\nВыйти из программы?\nВыберите: (0) - нет, (1) - да\n");
				prog = Exit();
				if (prog == 1)
				{
					printf("\nПрограмма завершена.\n");
					repeat = 1;
				}
				break;
			}

		} while (repeat != 1);

		for (int i = 0; i < size; i++)
		{
			delete[] massiv[i];
		}
		delete[] massiv;

	} while (prog != 1);

	return 0;
}


int GetSize()
{
	char c = '\0';
	int flag = 0; //флаг ввода некорректных значений
	int s;

	printf("\nЗапуск программы...\n\nВведите количество команд: ");
	do //защита от ввода некорректного значения количества команд
	{
		while (scanf_s("%d%c", &s, &c) != 2 || c != '\n')
		{
			printf("\n\aОШИБКА! Неверное значение!\nВведите количество команд: ");
			while (getchar() != '\n');
		}
		if (s <= 1 || s > 40)
		{
			printf("\n\aОШИБКА! Неверное значение!\nВведите количество команд: ");
		}
		else
		{
			flag = 1;
		}
	} while (flag != 1);

	return s;
}

int Menu()
{
	printf("\n+----------------------------------------------------------------+\n");
	printf("|                              Меню                              |\n");
	printf("+----------------------------------------------------------------+\n");
	printf("|      (1)  Ввести результаты футбольных матчей с клавиатуры     |\n");
	printf("|        (2)  Ввести результаты футбольных матчей случайно       |\n");
	printf("|             (3)  Определить наиболее успешную команду          |\n");
	printf("|     (4)  Вывести списки команд, которым еще предстоят игры     |\n");
	printf("|             (5)  Вывести результаты футбольных матчей          |\n");
	printf("|                 (6)  Запустить программу повторно              |\n");
	printf("|                           (7)  Выход                           |\n");
	printf("+----------------------------------------------------------------+\n\n");
	printf("Выберите пункт меню: ");

	int m;
	char c = '\0';
	int flag = 0; //флаг ввода некорректных значений

	do //защита от ввода некорректного пункта меню
	{
		while (scanf_s("%d%c", &m, &c) != 2 || c != '\n')
		{
			printf("\n\aОШИБКА! Неверный пункт меню.\nВыберите 1-6: ");
			while (getchar() != '\n');
		}
		if (m < 1 || m > 7)
		{
			printf("\n\aОШИБКА! Неверный пункт меню.\nВыберите 1-6: ");
		}
		else
		{
			flag = 1;
		}
	} while (flag != 1);

	return m;
}

void InputResults(int** m, int s)
{
	char c = '\0';
	int flag = 0; //флаг ввода некорректных значений

	printf("\n2 - команда выиграла, 1 – ничья, 0 – команда проиграла, -1 – команды не играли.\n\n");
	for (int i = 0; i < s - 1; i++)
	{
		for (int j = i + 1; j < s; j++)
		{
			printf("Введите результат матча между командами №%d и №%d: ", i + 1, j + 1);
			do
			{
				while (scanf_s("%d%c", &m[i][j], &c) != 2 || c != '\n') //защита от ввода некорректных значений элементов массива
				{
					printf("\n\aОШИБКА! Неверное значение!\n");
					while (getchar() != '\n');
					printf("Введите результат матча между командами №%d и №%d: ", i + 1, j + 1);
				}
				if (m[i][j] < -1 || m[i][j] > 2)
				{
					printf("\n\aОШИБКА! Неверное значение!\n");
					printf("Введите результат матча между командами №%d и №%d: ", i + 1, j + 1);
				}
				else
				{
					flag = 1;
				}
			} while (flag != 1);
		}
	}

	for (int i = 0; i < s - 1; i++)
	{
		for (int j = i + 1; j < s; j++)
		{
			if (m[i][j] == -1 || m[i][j] == 1)
			{
				m[j][i] = m[i][j];
			}
			if (m[i][j] == 0)
			{
				m[j][i] = 2;
			}
			if (m[i][j] == 2)
			{
				m[j][i] = 0;
			}
		}
	}
}

void InputResultsRandom(int** m, int s)
{
	for (int i = 0; i < s - 1; i++)
	{
		for (int j = i + 1; j < s; j++)
		{
			m[i][j] = rand() % 4 - 1;
		}
	}

	for (int i = 0; i < s - 1; i++)
	{
		for (int j = i + 1; j < s; j++)
		{
			if (m[i][j] == -1 || m[i][j] == 1)
			{
				m[j][i] = m[i][j];
			}
			if (m[i][j] == 0)
			{
				m[j][i] = 2;
			}
			if (m[i][j] == 2)
			{
				m[j][i] = 0;
			}
		}
	}
}

void FindTeamsDontPlay(int** m, int s)
{
	int flag = 0; //флаг ввода некорректных значений

	for (int i = 0; i < s - 1; i++)
	{
		for (int j = i + 1; j < s; j++)
		{
			if (m[i][j] == -1)
			{
				printf("\nКомандам №%d и №%d предстоит игра", i + 1, j + 1);
				flag = 1;
			}
		}
	}

	if (flag == 0)
	{
		printf("\nВсе команды сыграли.");
	}
	printf("\n");
}

void OutputResults(int** m, int s)
{
	printf("\nРезультаты матчей\n");
	printf("\n    ");
	for (int i = 0; i < s; i++)
	{
		if (i < 9)
		{
			printf("| %d  ", i + 1);
		}
		else
		{
			printf("| %d ", i + 1);
		}
	}
	printf("\n");
	for (int i = 0; i < s; i++)
	{
		printf("----+");
	}
	printf("----");

	for (int i = 0; i < s; i++)
	{
		if (i < 9)
		{
			printf("\n  %d ", i + 1);
		}
		else
		{
			printf("\n %d ", i + 1);
		}
		for (int j = 0; j < s; j++)
		{
			if (i == j)
			{
				printf("|    ");
			}
			else
			{
				if (m[i][j] != -1)
				{
					printf("| %d  ", m[i][j]);
				}
				else
				{
					printf("| %d ", m[i][j]);
				}
			}
		}
		printf("\n");
		for (int k = 0; k < s; k++)
		{
			printf("----+");
		}
		printf("----");
	}
	printf("\n");
}

int Exit()
{
	int r = 0;
	char c = '\0';
	int flag = 0; //флаг ввода некорректных значений

	do //защита от ввода некорректного пункта меню
	{
		while (scanf_s("%d%c", &r, &c) != 2 || c != '\n')
		{
			printf("\n\aОШИБКА! Неверное значение!\nВыберите: (0) - нет, (1) - да\n");
			while (getchar() != '\n');
		}
		if (r != 1 && r != 0)
		{
			printf("\n\aОШИБКА! Неверное значение!\nВыберите: (0) - нет, (1) - да\n");
		}
		else
		{
			flag = 1;
		}
	} while (flag != 1);

	return r;
}
