//Дан набор целых чисел. Найти количество максимальных чисел.

#include <iostream> //Бибилотека ввода-вывода
#include <vector> //Библиотека для работы с веткорами
#include <algorithm> //Библиотека для работы с алгоритмами
using namespace std;

int main() {
    setlocale(LC_ALL,"RUS"); //Использование русской клавиатуры
    int n; // Количество чисел 
    cout << "Введите количество чисел: "; cin >> n; //Запрос и ввод количества чисел с клавиатуры

    vector<int> numbers(n); //Создаем вектор, хранящий в себе целые числа
    cout << "Введите " << n << " чисел: "; //Запрос ввода чисел
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i]; //ввод чисел
    }

    // Находим максимальное число
    int maxNumber = *max_element(numbers.begin(), numbers.end());

    // Считаем количество максимальных чисел
    int countMax = count(numbers.begin(), numbers.end(), maxNumber);

    cout << "Количество максимальных чисел: " << countMax <<endl;

    return 0;
}
