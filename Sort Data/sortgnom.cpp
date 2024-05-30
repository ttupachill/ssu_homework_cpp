#include <iostream>     // Подключение стандартной библиотеки ввода/вывода
#include <string>       // Подключение стандартной библиотеки для работы со строками
#include <fstream>      // Подключение стандартной библиотеки для работы с файлами
#include <vector>       // Подключение стандартной библиотеки для работы с векторами
#include <algorithm>    // Подключение стандартной библиотеки для использования алгоритма сортировки
#include <iomanip>      // Подключение стандартной библиотеки для использования манипулятора вывода setw

using namespace std;    // Пространство стандартных имен

struct people {           // Структура для хранения информации о людях
    string surname, post, date; // Поля: фамилия, должность, дата рождения
    int birth, experience, salary; // Поля: год рождения, опыт работы, зарплата
};

void fill(vector<people>& staff) {    // Функция для заполнения вектора структур данными из файла
    ifstream in("input.txt");       // Открываем файл "input.txt" для чтения
    while (in >> ws) {              // Цикл чтения из файла (учитывая пробелы и пустые строки)
        people elem;                  // Создаем временную структуру для хранения данных о человеке
        in >> elem.surname >> elem.post >> elem.date >> elem.experience >> elem.salary; // Считываем данные из файла в поля структуры
        staff.push_back(elem);      // Добавляем структуру в вектор
    }
}

bool sravn(const people& a, const people& b) {       // Функция сравнения людей по должности, затем по зарплате
    if (a.post != b.post) {         // Если должности разные
        return a.post < b.post;     // Сравниваем по должности
    }
    return a.salary < b.salary;     // Если должности одинаковы, сравниваем по зарплате
}

void gnomeSort(vector<people>& staff) {   // Функция гномьей сортировки
    int pos = 0;                        
    while (pos < staff.size()) {        // Пока не достигли конца вектора
        if (pos == 0 || sravn(staff[pos], staff[pos - 1])) {  // Если текущий элемент найден в правильном месте
            pos++;                      // Переходим к следующему элементу
        } else {                        // Если текущий элемент нужно поменять местами с предыдущим
            swap(staff[pos], staff[pos - 1]);   // Меняем элементы местами
            pos--;                      // Возвращаемся назад
        }
    }
}

int main() {                            
    ofstream out("output.txt");         // Открываем файл "output.txt" для записи
    vector<people> staff;                 // Создаем вектор структур для хранения информации о людях
    fill(staff);                        // Заполняем вектор данными из файла

    gnomeSort(staff);                   // Сортируем вектор с помощью гномьей сортировки

    out << setw(10) << "|surname|" << setw(15) << "|post|" << setw(15) << "|birthday|" << setw(13) << "|experience|" << setw(10) << "|salary|" << endl; // Вывод заголовков столбцов
    for (int i = 0; i < staff.size(); i++) {  // Цикл вывода информации о людях
        out << setw(10) << staff[i].surname << setw(15) << staff[i].post << setw(15) << staff[i].date << setw(7) << staff[i].experience << setw(16) << staff[i].salary << endl; // Вывод данных о каждом человеке
    }

    return 0;                       
}


