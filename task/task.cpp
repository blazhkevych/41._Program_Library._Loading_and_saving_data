/*
	Работа с бинарным файлом. Программа Библиотека. Загрузка и сохранение данных.
Дополнить программу «Библиотека» следующей функциональностью.
	 При старте программы книги должны загружаться из файла.
	 При завершении работы программы книги должны сохраняться в файл.
	При загрузке и сохранении книг рекомендуется применять бинарный режим работы с
файлом
*/

#include <iostream>
#include <windows.h>
#include "lib.h"
#include <conio.h>
using namespace std;

int main()
{
	SetConsoleCP(1251);
	/*
	Задает кодовую страницу ввода, используемую консолью, связанной с вызывающим процессом.
	Консоль использует страницу входного кода для преобразования ввода с клавиатуры
	в соответствующее символьное значение.
	*/
	SetConsoleOutputCP(1251);
	/*
	Задает выходную кодовую страницу, используемую консолью, связанной с вызывающим процессом.
	Консоль использует свою кодовую страницу вывода для преобразования символьных значений,
	записанных различными функциями вывода, в изображения, отображаемые в окне консоли.
	*/
	ArrayBooks b;
	memset(&b, 0, sizeof(ArrayBooks));
	b.Block = 10;
	char menu[][50] = {
		"1. Добавление книг",
		"2. Печать всех книг",
		"3. Удаление книги по указанному критерию",
		"4. Редактирование книги",
		"5. Поиск книг по автору" ,
		"6. Поиск книги по названию" ,
		"7. Сортировка книг по названию" ,
		"8. Сортировка книг по автору" ,
		"9. Сортировка книг по издательству",
		"10. Выход" };
	LoadFromFile(b);
	while (true)
	{
		system("cls");
		Menu(menu, 10);
		int choice{ 0 };
		cout << "\n   >>> ";
		cin >> choice;
		cin.get();
		switch (choice)
		{
		case 1:
			AddBooks(b);
			break;
		case 2:
			if (b.Count < 1)
			{
				system("cls");
				cout << "Список пустой !" << endl;
				_getch();
			}
			else
			{
				PrintHeaderBooks();
				PrintBooks(b);
			}
			break;
		case 3:
			if (b.Count < 1)
			{
				system("cls");
				cout << "Список пустой !" << endl;
				_getch();
			}
			else
				RemoveBookBySpecCriteria(b);
			break;
		case 4:
			if (b.Count < 1)
			{
				system("cls");
				cout << "Список пустой !" << endl;
				_getch();
			}
			else
				EditBook(b);
			break;
		case 5:
			if (b.Count < 1)
			{
				system("cls");
				cout << "Список пустой !" << endl;
				_getch();
			}
			else
				SearchBookByAuthor(b);
			break;
		case 6:
			if (b.Count < 1)
			{
				system("cls");
				cout << "Список пустой !" << endl;
				_getch();
			}
			else
				BookSearchByTitle(b);
			break;
		case 7:
			if (b.Count < 1)
			{
				system("cls");
				cout << "Список пустой !" << endl;
				_getch();
			}
			else
				SortBooksByTitle(b);
			break;
		case 8:
			if (b.Count < 1)
			{
				system("cls");
				cout << "Список пустой !" << endl;
				_getch();
			}
			else
				SortBooksByAuthor(b);
			break;
		case 9:
			if (b.Count < 1)
			{
				system("cls");
				cout << "Список пустой !" << endl;
				_getch();
			}
			else
				SortBooksByPublisher(b);
			break;
		case 10:
			SaveToFile(b);
			Destroy(b);
			return 0;
			break;
		}
	}

	return 0;
}