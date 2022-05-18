struct Book
{
	char title[100]; // название книги
	char author[100]; // автор книги
	char publishingHouse[100]; // издательство книги
	int yearOfPublishing; // год издания книги
	char genre[100]; // жанр книги
};

struct ArrayBooks
{
	Book** PtrBook;
	int Size; // Реальный размер массива (заполненные ячейки и пустые ячейки), кратен размеру блока
	int Count; // Фактическое количество ячеек с добавленными данными
	int Block; // Размер добавляемого блока
};

// Меню
void Menu(char ptr[][50], int row);

// Критерий
void MenuCriterion(char ptr[][50], int row);

// Ввод данных о книге
void InputData(Book* st);

// Добавление книги в массив
void AddBooks(ArrayBooks& b);

// Удаление книги
void RemoveBookBySpecCriteria(ArrayBooks& b);

// Редактирование книги
void EditBook(ArrayBooks& b);

// Вывод хедера списка книг на экран
void PrintHeaderBooks();

// Вывод списка книг на экран 
void PrintBooks(ArrayBooks& b);

// Вывод 1 книги на экран 
void Print1Book(ArrayBooks& b, int i);

// Удаление книги
void Destroy(ArrayBooks& b);

// Поиск книг по автору
void SearchBookByAuthor(ArrayBooks& b);

// Поиск книги по названию
void BookSearchByTitle(ArrayBooks& b);

// Сортировка книг по названию
void SortBooksByTitle(ArrayBooks& b);

// Сортировка книг по автору
void SortBooksByAuthor(ArrayBooks& b);

// Сортировка книг по издательству
void SortBooksByPublisher(ArrayBooks& b);

// Загрузка списка книг из файла
void LoadFromFile(ArrayBooks& b);

// Сохранение списка книг в файл
void SaveToFile(ArrayBooks b);