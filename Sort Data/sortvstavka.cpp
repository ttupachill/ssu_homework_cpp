#include <iostream> // Подключаем заголовочный файл для работы с вводом/выводом
#include <string> // Подключаем заголовочный файл для работы со строками
#include <fstream> // Подключаем заголовочный файл для работы с файлами
#include <vector> // Подключаем заголовочный файл для работы с векторами
#include <algorithm> // Подключаем заголовочный файл для работы с алгоритмами
#include <iomanip> // Подключаем заголовочный файл для управления форматированием вывода

using namespace std; // Используем пространство имен стандартной библиотеки

struct people { // Объявляем структуру с именем people для хранения информации о работнике
    string surname, post, date; // Объявляем строки для фамилии, должности и даты
    int birth, experience, salary; // Объявляем целочисленные переменные для года рождения, стажа и зарплаты
};

void fill(vector<people> &staff) { // Функция для заполнения вектора работников из файла
    ifstream in("input.txt"); // Открываем файл для чтения
    while (in.peek() != EOF) { // Пока не достигнут конец файла
        people elem; // Создаем экземпляр структуры people
        string one, two, three, four, five; // Объявляем строки для данных
        in >> one >> two >> three >> four >> five; // Считываем данные из файла
        elem.surname = one; // Присваиваем фамилию работника
        elem.post = two; // Присваиваем должность
        elem.date = three; // Присваиваем дату рождения

        string str1 = three.substr(6, 4); // Получаем подстроку из даты рождения
        int yy = stoi(str1); // Преобразуем подстроку в целое число
        elem.birth = yy; // Присваиваем год рождения

        elem.experience = stoi(four); // Преобразуем строку в целое число и присваиваем стаж
        elem.salary = stoi(five); // Преобразуем строку в целое число и присваиваем зарплату
        staff.push_back(elem); // Добавляем информацию о работнике в вектор
    }
}

bool sravn(people &a, people &b) { // Функция для сравнения двух работников при сортировке
    if (a.surname != b.surname) { // Если фамилии разные
        return a.surname < b.surname; // Возвращаем результат сравнения фамилий
    } else if (a.experience != b.experience) { // В противном случае, если стаж разный
        return a.experience < b.experience; // Возвращаем результат сравнения стажа
    } else { // Иначе
        return a.birth < b.birth; // Возвращаем результат сравнения года рождения
    }
}

void insertionSort(vector<people>& arr) { // Функция для сортировки вектора работников методом вставок
    for (int i = 1; i < arr.size(); ++i) { // Проходим по всем элементам вектора, начиная со второго
        people key = arr[i]; // Запоминаем текущий элемент как ключ
        int j = i - 1; 

        while (j >= 0 && sravn(key, arr[j])) { // Пока не достигнут начало вектора и ключ меньше предыдущего элемента
            arr[j + 1] = arr[j]; // Перемещаем элементы вправо
            j--;
        }

        arr[j + 1] = key; // Вставляем ключ на правильное место
    }
}

int main() {
    ofstream out("output1.txt"); // Открываем файл для записи отсортированных данных
    vector<people> staff; // Объявляем вектор для хранения информации о работниках
    fill(staff); // Заполняем вектор из файла
    
    insertionSort(staff); // Сортируем работников методом вставок

    out << setw(10) << "|surname|" << setw(15) << "|post|" << setw(15) << "|birthday|" << setw(13) << "|experience|" << setw(10) << "|salary|" << endl; // Выводим заголовок таблицы в файл
    for (int i = 0; i < staff.size(); i++)
        out << setw(10) << staff[i].surname << setw(15) << staff[i].post << setw(15) << staff[i].date << setw(7) << staff[i].experience << setw(16) << staff[i].salary << endl;

    return 0;
}
