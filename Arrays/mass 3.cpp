#include<iostream>
#include<math.h>
#include<limits.h>
using namespace std;

int main() {
    int n; // Объявляем переменную n
    setlocale(LC_ALL, "RUS");//Использование русской клавиатуры
    cout << "Введите кол-во элементов n: ";
    cin >> n;//Ввод n с клавиатуры
    int* a = new int[n]; // Выделение памяти для массива
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "]=";//Запрос ввода каждого элемента массива
        cin >> a[i]; // ввод элементов массива
    }

    int min = INT_MAX; // Поиск минимального нечетного элемента
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 != 0 && a[i] < min) { // Проверка на нечетность и поиск минимального значения
            min = a[i];
        }
    }

    if (min == INT_MAX) { // если минимального нечетного значения нет
        cout << "Нечетных элементов нет\n";//То выводим сообщение
    }
    else {
        for (int i = 0; i < n; i++) {
            if (a[i] == min) {
                cout << i << " "; // Если есть, то выводим
            }
        }

        cout << endl;
        return 0;
    }
