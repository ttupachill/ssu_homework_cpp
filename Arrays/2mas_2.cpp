#include<iostream> //Бибилотека ввода-вывода
#include<limits.h> // Предельные значения INT_MIN и INT_MAX
#include<math.h> //Библиотека математических функий

using namespace std;//Использование стандартных имен
int main() {
	setlocale(LC_ALL, "RUS");//Использование русской клавиатуры
	int n, max_i, min_i, raznica;
	int minim = INT_MAX;//Минимально предельное значение
	int maxim = INT_MIN;//М
	cout << "Введите число n ="; cin >> n;//Запрос ввода числа с клавиатуры
	int** mas = new int* [n];                //Выделение памяти под массив указателей
	for (int i = 0; i < n; i++) {
		mas[i] = new int[n];                //Выделение памяти для каждого указателя
	}
	cout << " Вводите числа по одному (записываются строчно) " << endl; //Запрос ввоад чисел с клавиатуры построчно
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mas[i][j]; //Ввод с клавиатуры
		}
	}
	cout << "Массив: \n";                             // Исходный массив 
	for (int i = 0; i < n; i++, cout << endl) {
		for (int j = 0; j < n; j++) {
			cout << mas[i][j] << " ";
		}
	}
	for (int i = 0; i < n; i++) {                       // Поиск минимального
		for (int j = 0; j < n; j++) {
			if (mas[i][j] < minim) {
				minim = mas[i][j];
				min_i = i;
			}
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		for (int j = n - 1; j >= 0; j--) {
			if (mas[i][j] > maxim) {                      // Поиск максимального
				maxim = mas[i][j];
				max_i = i;
			}
		}
	}
	raznica = abs(max_i - min_i);
	cout << min_i << " " << max_i;
	for (int i = min_i; i <= min_i; i++) {                     // замена минимума на максимум и обратная
		for (int j = 0; j < n; j++) {
			swap(mas[i][j], mas[i + raznica][j]);
		}
	}
	cout << "Новый Массив: \n";                            //выводим новый массив
	for (int i = 0; i < n; i++, cout << endl) {
		for (int j = 0; j < n; j++) {
			cout << mas[i][j] << " ";
		}
	}
}