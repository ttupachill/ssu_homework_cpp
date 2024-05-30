#include<iostream>//Бибилиотека ввода-вывода
#include<limits.h>
#include<math.h>//Бибилиотека математических функций

using namespace std;//Использование стандартных имен
int main() {
	setlocale(LC_ALL, "RUS");//Использование русской клавиатуры
	int n;
	cout << "Введите количество строк: " << endl;//Запрос ввода с клавиатуры
	cin >> n;//Ввод с клавиатуры
	int** mas = new int* [n];//Выделение памяти под массив
	for (int i = 0; i < n; i++) {
		mas[i] = new int[n];//Выделение памяти для каждого указателя

	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << "Введите числа по одному" << endl;//Ввод массива построчно
			cin >> mas[i][j];
		}
	}
	cout << "Массив: \n"; // Вывод исходного массива
	for (int i = 0; i < n; i++, cout << endl) {
		for (int j = 0; j < n; j++) {
			cout << mas[i][j] << " ";
		}
	}
	for (int j = 0; j < n - 1; j += 2) {
		for (int i = 0; i < n; i++) {
			swap(mas[i][j], mas[i][j + 1]);        //Замена 1 со 2, 3 с 4 
		}
	}
	cout << "Новый Массив:\n";                     //Вывод нового массива
	for (int i = 0; i < n; i++, cout << endl) {
		for (int j = 0; j < n; j++) {
			cout << mas[i][j] << " ";
		}
	}
	return 0;//Завершение работы функции
}

		

