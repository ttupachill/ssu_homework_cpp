#include <iostream>
using namespace std;

template <typename T>         //Создаем с шаблон и задаем его параметры
void process(T** matrix, int n, int m, T* X) {    //Параметры
    for (int i = 0; i < n; ++i) {
        bool yes = true; //Устанавливаем флаг в true
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] % 2 == 1) { //Если элемент нечетный
                yes = false; //Устанавливаем флаг в false
                break;   //Выход из цикла
            }
        }
        if (yes) {   //Если найден четный
            for (int j = 0; j < m; ++j) {
                matrix[i][j] = X[j]; //Вставляем строку X
            }
        }
    }
}

int test_int() {   //Функция для целых чисел
    setlocale(LC_ALL,"RUS");
    int m, n;
    cout << "n = "; cin>>n;
    cout<<"m = "; cin>>m;

    int** matrix = new int*[n];  //Выделения памяти для массива целочисленного типа
    for (int i = 0; i < n; ++i) {
        matrix[i] = new int[m]; //Выделение памяти для всех укзаателей
    }

    cout << "Введите матрицу (int): "<<endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) { 
            cin >> matrix[i][j];  //Ввод матрицы
        }
    }

    int* X = new int[m];  //Выделение памяти для строки X целочисленного типа
    cout << "X = ";
    for (int i = 0; i < m; ++i) {
        cin >> X[i];  //Ввод строки X
    }

    process(matrix, n, m, X);  //Вызов шаблона

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << matrix[i][j] << " ";  
        }
        cout << "\n";
    }

    delete[] X;  //Освобождение памяти

    for (int i = 0; i < n; ++i) {
        delete[] matrix[i];  //Освобождение памяти
    }
    delete[] matrix;  //Освобождение памяти

    return 0;
}

int test_char() {  //Функция для символьного типа
    setlocale(LC_ALL,"RUS");
    int m, n;    //Объявляем переменные для указания размерности матрицы
    cout << " n =  ";cin>>n; 
    cout<<" m = ";cin>>m;

    char** matrix = new char*[n];  //Выделение памяти для массива символьного типа
    for (int i = 0; i < n; ++i) {
        matrix[i] = new char[m];   //Выделение памяти для всех указателей
    }

    cout << "Введите матрицу(char): "<<endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) { 
            cin >> matrix[i][j];
        }
    }

    char* X = new char[m];   //Выделение памяти для строки вставки X символьного типа
    cout << " X = ";
    for (int i = 0; i < m; ++i) {
        cin >> X[i];   //Ввод строки X с клавиатуры
    }

    process(matrix, n, m, X);  //Вызов шаблона

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    delete[] X; //Освобождение памяти

    for (int i = 0; i < n; ++i) {
        delete[] matrix[i];  //Освобождение памяти
    } 
    delete[] matrix;   //Освобождение памяти

    return 0;
}

int main() {

    test_int();           //Вызов целочисленной функции
    test_char();           //Вызов символьной функции

    return 0;  //Завершение работы функции
}
