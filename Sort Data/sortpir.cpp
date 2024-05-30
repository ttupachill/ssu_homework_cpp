
#include <iostream> // Подключение стандартной библиотеки ввода/вывода
#include <string> // Подключение библиотеки для работы со строками
#include <vector> // Подключение библиотеки для работы с векторами
#include <fstream> // Подключение библиотеки для работы с файлами
#include <iomanip> // Подключение библиотеки для форматированного вывода

using namespace std; // Использование стандартного пространства имен

struct date { // Объявление структуры для хранения даты
    int dd, mm, yy; // Поля для дня, месяца и года
};

struct people { // Объявление структуры для хранения информации о людях
    string surname; // Фамилия
    string job; // Работа
    date birth; // Дата рождения
    int exp; // Опыт работы
    int salary; // Зарплата
};

bool iseqd(const date& a, const date& b) { // Функция для сравнения двух дат
    return a.dd == b.dd && a.mm == b.mm && a.yy == b.yy;
}

bool iseqp(const people& a, const people& b) { // Функция для сравнения двух людей
    return (
        a.surname == b.surname &&
        a.job == b.job &&
        iseqd(a.birth, b.birth) &&
        a.exp == b.exp &&
        a.salary == b.salary
    );
}

date str_to_date(const string& str) { // Функция для преобразования строки в дату
    date d;
    d.dd = atoi(str.substr(0, 2).c_str());
    d.mm = atoi(str.substr(3, 2).c_str());
    d.yy = atoi(str.substr(6, 4).c_str());
    return d;
}

string date_to_str(const date& d) { // Функция для преобразования даты в строку
    string s;
    s += to_string(d.dd);
    s += ".";
    s += to_string(d.mm);
    s += ".";
    s += to_string(d.yy);
    return s;
}

void show_person(ofstream& out, const people& person) { // Функция для вывода информации о человеке в файл
    out  << setw(15) << person.surname
         << setw(15) << person.job
         << setw(15) << date_to_str(person.birth)
         << setw(15) << person.exp
         << setw(15) << person.salary << "\n";
}

void dump_people(const vector<people>& data) { // Функция для записи информации о людях в файл
    ofstream out("output.txt"); // Открытие файла для записи
    for (const auto& p : data) {
        show_person(out, p); // Вызов функции для вывода информации о человеке в файл
    }
    out.close(); // Закрытие файла
}

void populate_data(vector<people>& data) { // Функция для заполнения информации о людях из файла
    data.clear(); 
    ifstream in("input.txt"); // Открытие файла для чтения
    people person; // Создание объекта структуры для информации о человеке
    string t; // Строка для временного хранения данных
    while (in.peek() != EOF) {
        in >> person.surname; // Чтение фамилии из файла
        in >> person.job; // Чтение работы из файла
        in >> t;
        person.birth = str_to_date(t); // Преобразование строки в дату
        in >> t;
        person.exp = atoi(t.c_str()); // Преобразование строки в целое число для опыта работы
        in >> t;
        person.salary = atoi(t.c_str()); // Преобразование строки в целое число для зарплаты
        data.push_back(person); // Добавление информации о человеке в вектор
    }
    in.close(); // Закрытие файла
}

// Функция для преобразования поддерева в двоичную кучу
void heapify(vector<people>& data, int n, int i) {
    int largest = i; 
    int left = 2 * i + 1; // левый ребенок
    int right = 2 * i + 2; // правый ребенок

    // Если левый дочерний элемент больше корня
    if (left < n && data[left].job > data[largest].job)
        largest = left;

    // Если правый дочерний элемент больше, чем самый большой элемент на данный момент
    if (right < n && data[right].job > data[largest].job)
        largest = right;

    // Если самый большой элемент не корень
    if (largest != i) {
        swap(data[i], data[largest]); // Поменять

       
        heapify(data, n, largest);
    }
}

// Основная функция, выполняющая пирамидальную сортировку
void Sort(vector<people>& data) {
    int n = data.size(); 

    // Построение кучи (перегруппировка массива)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(data, n, i);

    // Один за другим извлекаем элементы из кучи
    for (int i = n - 1; i >= 0; i--) {
        // Меняем местами
        swap(data[0], data[i]);
        heapify(data, i, 0);
    }
}

int main() {
    vector<people> data; // Создание вектора для хранения информации о людях

    populate_data(data); // Заполнение вектора данными из файла

    Sort(data); // Сортировка вектора

    dump_people(data); // Запись отсортированных данных в файл

    return 0; 
}
