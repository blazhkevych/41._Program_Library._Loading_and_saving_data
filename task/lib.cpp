#include <windows.h>
#include <iostream>
#include <conio.h>
#include <iomanip>
#include "lib.h"
using std::cout;
using std::endl;
using std::cin;
using std::setw;

// Меню
void Menu(char ptr[][50], int row)
{
	for (int i = 0; i < row; i++)
	{
		cout << ptr[i];
		cout << endl;
	}
}

// Критерий
void MenuCriterion(char ptr[][50], int row)
{
	for (int i = 0; i < row; i++)
	{
		cout << ptr[i];
		cout << endl;
	}
}

// Ввод данных о книге
void InputData(Book* book)
{
	cout << "Введите название книги: ";
	cin.getline(book->title, 100);
	cout << "Введите автора книги: ";
	cin.getline(book->author, 100);
	cout << "Введите издателя книги: ";
	cin.getline(book->publishingHouse, 100);
	cout << "Введите год издания книги: ";
	cin >> book->yearOfPublishing;
	cin.get();
	cout << "Введите жанр книги: ";
	cin.getline(book->genre, 100);
}

// Добавление книги в массив
void AddBooks(ArrayBooks& b)
{
	system("cls");
	int number;
	cout << "Сколько книг добавить? ";
	cin >> number;
	cin.get();
	if (number <= 0)
		return;
	int new_num = b.Count + number;
	if (b.Size < new_num)
	{
		b.Size = new_num + b.Block - new_num % b.Block;
		Book** temp = new Book * [b.Size];
		for (int i = 0; i < b.Count; i++)
			temp[i] = b.PtrBook[i];
		delete[]b.PtrBook;
		b.PtrBook = temp;
	}
	for (int i = 0; i < number; i++)
	{
		Book* book = new Book;
		cout << "Введите данные ";
		cout << i + 1;
		cout << " книги\n";
		InputData(book);
		b.PtrBook[b.Count++] = book;
	}
	cout << "\nВ список добавлены новые книги!";
	_getch();
}

// Удаление книги по указанному критерию
void RemoveBookBySpecCriteria(ArrayBooks& b)
{
	//2,53,20
	system("cls");
	char criterion[][50] =
	{
		"\n1. Название",
		"2. Автор",
		"3. Издатель",
		"4. Год",
		"5. Жанр"
	};
	cout << "Выберите критерий для удаления книги: ";
	MenuCriterion(criterion, 5);
	int choice = _getch();
	char crit[50];
	switch (choice)
	{
	case '1': // удаление по названию
		cout << "Введите название книги: ";
		cin.getline(crit, 100);
		for (int i = 0; i < b.Count; i++)
		{
			if (!strcmp(crit, b.PtrBook[i]->title))
			{
				delete b.PtrBook[i];
				for (int j = i; j < b.Count - 1; j++)
					b.PtrBook[j] = b.PtrBook[j + 1];
				b.PtrBook[--b.Count] = nullptr;
				cout << "Книга удалена!";
				_getch();
				return;
			}
		}
		cout << "Книга не найдена!";
		_getch();
		break;
	case '2': // удаление по автору
		cout << "Введите автора книги: ";
		cin.getline(crit, 100);
		for (int i = 0; i < b.Count; i++)
		{
			if (!strcmp(crit, b.PtrBook[i]->author))
			{
				delete b.PtrBook[i];
				for (int j = i; j < b.Count - 1; j++)
					b.PtrBook[j] = b.PtrBook[j + 1];
				b.PtrBook[--b.Count] = nullptr;
				cout << "Книга удалена!";
				_getch();
				return;
			}
		}
		cout << "Книга не найдена!";
		_getch();
		break;
	case '3': // удаление по издателю
		cout << "Введите издателя книги: ";
		cin.getline(crit, 100);
		for (int i = 0; i < b.Count; i++)
		{
			if (!strcmp(crit, b.PtrBook[i]->publishingHouse))
			{
				delete b.PtrBook[i];
				for (int j = i; j < b.Count - 1; j++)
					b.PtrBook[j] = b.PtrBook[j + 1];
				b.PtrBook[--b.Count] = nullptr;
				cout << "Книга удалена!";
				_getch();
				return;
			}
		}
		cout << "Книга не найдена!";
		_getch();
		break;
	case '4': // удаление по году
		cout << "Введите год издания книги: ";
		int y;
		cin >> y;
		for (int i = 0; i < b.Count; i++)
		{
			if (y == b.PtrBook[i]->yearOfPublishing)
			{
				delete b.PtrBook[i];
				for (int j = i; j < b.Count - 1; j++)
					b.PtrBook[j] = b.PtrBook[j + 1];
				b.PtrBook[--b.Count] = nullptr;
				cout << "Книга удалена!";
				_getch();
				return;
			}
		}
		cout << "Книга не найдена!";
		_getch();
		break;
	case '5':  // удаление по жанру
		cout << "Введите жанр книги: ";
		cin.getline(crit, 100);
		for (int i = 0; i < b.Count; i++)
		{
			if (!strcmp(crit, b.PtrBook[i]->genre))
			{
				delete b.PtrBook[i];
				for (int j = i; j < b.Count - 1; j++)
					b.PtrBook[j] = b.PtrBook[j + 1];
				b.PtrBook[--b.Count] = nullptr;
				cout << "Книга удалена!";
				_getch();
				return;
			}
		}
		cout << "Книга не найдена!";
		_getch();
		break;
	}
}

// Редактирование книги
void EditBook(ArrayBooks& b)
{
	system("cls");
	char Title[100], Author[100];
	cout << "Введите название книги: ";
	cin.getline(Title, 100);
	cout << "Введите автора книги: ";
	cin.getline(Author, 100);
	for (int i = 0; i < b.Count; i++)
	{
		if (!strcmp(Title, b.PtrBook[i]->title) && !strcmp(Author, b.PtrBook[i]->author))
		{
			cout << "Введите новые данные!\n";
			InputData(b.PtrBook[i]);
			cout << "\nДанные книги изменены!";
			_getch();
			return;
		}
	}
	cout << "Книга не найдена!";
	_getch();
}

// Вывод хедера списка книг на экран
void PrintHeaderBooks()
{
	system("cls");
	cout << setw(25);
	cout << "Название";
	cout << setw(25);
	cout << "Автор";
	cout << setw(25);
	cout << "Издатель";
	cout << setw(20);
	cout << "Год издания";
	cout << setw(15);
	cout << "Жанр";
	cout << endl << endl;
}

// Вывод списка книг на экран 
void PrintBooks(ArrayBooks& b)
{
	for (int i = 0; i < b.Count; i++)
	{
		cout << setw(25) << (*b.PtrBook[i]).title
			<< setw(25) << (*b.PtrBook[i]).author
			<< setw(25) << (*b.PtrBook[i]).publishingHouse
			<< setw(20) << (*b.PtrBook[i]).yearOfPublishing
			<< setw(15) << (*b.PtrBook[i]).genre
			<< endl;
	}
	_getch();
}

// Вывод 1 книги на экран 
void Print1Book(ArrayBooks& b, int i)
{
	cout << setw(25) << (*b.PtrBook[i]).title
		<< setw(25) << (*b.PtrBook[i]).author
		<< setw(25) << (*b.PtrBook[i]).publishingHouse
		<< setw(20) << (*b.PtrBook[i]).yearOfPublishing
		<< setw(15) << (*b.PtrBook[i]).genre
		<< endl;
}

// Удаление книги
void Destroy(ArrayBooks& b)
{
	for (int i = 0; i < b.Count; i++)
		delete b.PtrBook[i];
	delete[] b.PtrBook;
	memset(&b, 0, sizeof(ArrayBooks));
}

// Поиск книг по автору
void SearchBookByAuthor(ArrayBooks& b)
{
	system("cls");
	char Author[100];
	cout << "Введите автора книги: ";
	cin.getline(Author, 100);
	bool flag{ false };
	int headerFlag{ 0 };
	for (int i = 0; i < b.Count; i++)
	{
		if (!strcmp(Author, b.PtrBook[i]->author))
		{
			headerFlag++;
			if (headerFlag == 1)
				PrintHeaderBooks();
			flag = true;
			Print1Book(b, i);
		}
	}
	if (flag == false)
	{
		cout << "Книга не найдена!";
		_getch();
	}
	_getch();
	return;
}

// Поиск книги по названию
void BookSearchByTitle(ArrayBooks& b)
{
	system("cls");
	char Author[100];
	cout << "Введите название книги: ";
	cin.getline(Author, 100);
	bool flag{ false };
	int headerFlag{ 0 };
	for (int i = 0; i < b.Count; i++)
	{
		if (!strcmp(Author, b.PtrBook[i]->title))
		{
			headerFlag++;
			if (headerFlag == 1)
				PrintHeaderBooks();
			flag = true;
			Print1Book(b, i);
		}
	}
	if (flag == false)
	{
		cout << "Книга не найдена!";
		_getch();
	}
	_getch();
	return;
}

// Сортировка книг по названию
void SortBooksByTitle(ArrayBooks& b)
{
	system("cls");
	for (int startIndex = 0; startIndex < b.Count; ++startIndex)
	{
		int biggerIndex = startIndex;

		for (int currentIndex = startIndex + 1; currentIndex < b.Count; ++currentIndex)
		{
			if (strcmp(b.PtrBook[currentIndex]->title, b.PtrBook[biggerIndex]->title) < 0) // Сортировка по убыванию
				biggerIndex = currentIndex;
		}

		Book* temp = b.PtrBook[startIndex];
		b.PtrBook[startIndex] = b.PtrBook[biggerIndex];
		b.PtrBook[biggerIndex] = temp;
	}

	cout << "Список отсортирован!\n ";
	_getch();
}

// Сортировка книг по автору
void SortBooksByAuthor(ArrayBooks& b)
{
	system("cls");
	for (int startIndex = 0; startIndex < b.Count; ++startIndex)
	{
		int biggerIndex = startIndex;

		for (int currentIndex = startIndex + 1; currentIndex < b.Count; ++currentIndex)
		{
			if (strcmp(b.PtrBook[currentIndex]->author, b.PtrBook[biggerIndex]->author) < 0) // Сортировка по убыванию
				biggerIndex = currentIndex;
		}

		Book* temp = b.PtrBook[startIndex];
		b.PtrBook[startIndex] = b.PtrBook[biggerIndex];
		b.PtrBook[biggerIndex] = temp;
	}

	cout << "Список отсортирован!\n ";
	_getch();
}

// Сортировка книг по издательству
void SortBooksByPublisher(ArrayBooks& b)
{
	system("cls");
	for (int startIndex = 0; startIndex < b.Count; ++startIndex)
	{
		int biggerIndex = startIndex;

		for (int currentIndex = startIndex + 1; currentIndex < b.Count; ++currentIndex)
		{
			if (strcmp(b.PtrBook[currentIndex]->publishingHouse, b.PtrBook[biggerIndex]->publishingHouse) < 0) // Сортировка по убыванию
				biggerIndex = currentIndex;
		}

		Book* temp = b.PtrBook[startIndex];
		b.PtrBook[startIndex] = b.PtrBook[biggerIndex];
		b.PtrBook[biggerIndex] = temp;
	}

	cout << "Список отсортирован!\n ";
	_getch();
}