#include <iostream>
using namespace std;



template <typename T>                           //Создаем шаблон и указываем параметры
void process(T** matrix, int n, int m, T* X) {
    T min = matrix[0][0];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (min > matrix[i][j]) {
                min = matrix[i][j]; //Поиск максимального и запись в переменную
            }
        }
    }

        for (int i = 0; i < n; ++i) {
        bool fl = false; //Устанавливаем флаг в false
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] == min) { //Если условие выполняется,
                fl = true;  //Флаг в true
                break; //Выход из цикла
            }
        }      
        if (fl) {         //Если нашли минимальный,
            for (int j = 0; j < m; ++j) {
                matrix[i][j] = X[j];  //Вставляем X
            }
        }
    }
}

int test_int() {
    setlocale(LC_ALL,"RUS");
    int m, n;
    cout << "n = "; cin>>n;
    cout<<"m = "; cin >> m;

    int** matrix = new int*[n]; //Выделение памяти для массива целых чисел
    for (int i = 0; i < n; ++i) {
        matrix[i] = new int[m]; //Выделение памяти для всех указателей
    }

    cout << "Введите матрицу (int): "<<endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) { 
           cin >> matrix[i][j];  //Считывание матрицы с клавиатуры
        }
    }

    int* X = new int[m];  //Определяем строку X для вставки
    cout << "Введите X: ";
    for (int i = 0; i < m; ++i) {
        cin >> X[i];        //Ввод строки X для вставки с клавиатуры
    }

    process(matrix, n, m, X);  //Вызов шаблона

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    delete[] X;

    for (int i = 0; i < n; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}

int test_double() { //Функция для вещественных чисел
    setlocale(LC_ALL,"RUS");
    int m, n;
    cout << "n = ";cin>>n;
    cout<<"m = ";cin>>m;
   

    double** matrix = new double*[n];   //выделение памяти для массива вещественных чисел
    for (int i = 0; i < n; ++i) {
        matrix[i] = new double[m];      //Выделение памяти для всех указателей
    } 

    cout << "Введите матрицу (double): "<<endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) { 
            cin >> matrix[i][j]; //Ввод матрицы вещественного типа
        }
    }

    double* X = new double[m];  //Выделение памяти для строки X вещественного типа
    cout << "X =  ";
    for (int i = 0; i < m; ++i) {
        cin >> X[i]; //Ввод строки X с клавиатуры
    }

    process(matrix, n, m, X);  //Вызов шаблона

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << matrix[i][j] << " ";  //Ввод матрицы
        }
        cout << "\n";
    }

    delete[] X;   //Освобождение памяти

    for (int i = 0; i < n; ++i) {
        delete[] matrix[i];  //Освбождение памяти
    }
    delete[] matrix;   //Освобождение памяти

    return 0;
}

int test_char() {
    int m, n;
    cout << "n =  ";cin>>n;
    cout<<"m = ";cin>>m;
    

    char** matrix = new char*[n];  //Выделение памяти для массива символьного типа
    for (int i = 0; i < n; ++i) {
        matrix[i] = new char[m];   //Выделение памяти для всех указателей
    }

    cout << "Введите матрицу (char): ";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) { 
            cin >> matrix[i][j];   //Ввод матрицы
        }
    }

    char* X = new char[m];   //Выделение памяти для строки X символьного типа
    cout << " X =  ";
    for (int i = 0; i < m; ++i) {
        cin >> X[i];   //Ввод строки X с клавиатуры
    }

    process(matrix, n, m, X);  //Вызов шаблона

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << matrix[i][j] << " ";   //Ввод матрицы
        }
        cout << "\n";
    }

    delete[] X;  //Освобождение памяти

    for (int i = 0; i < n; ++i) {
        delete[] matrix[i];   //Освобождение памяти
    }
    delete[] matrix;  //Освобождение памяти

    return 0;
}

int main() {

    test_int();
    test_double();
    test_char();

    return 0;
}
