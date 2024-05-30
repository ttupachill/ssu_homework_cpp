#include <iostream>//Библиотека ввода-вывода
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
using namespace std;//Использование стандартных имен
int main() {
	setlocale(LC_ALL, "RUS");//Использование русской клавиатуры
	int n;//Объявляем переменную n
	cout << "Введите кол-во элементов n: ";             //Запрос ввода кол-ва элементов массива
	cin >> n;//Ввод с клавиатуры
	int* a = new int[n];                //Выделение памяти под массив
	srand((unsigned int)time(NULL));   //Начальная точка генерации рандомного числа
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 15;          //Псевдослучайное число
		cout << "a[" << i << "]=";//Запрос ввода элементов по порядку
		cin >> a[i];//Ввод элементов
	}
	cout << endl;
	int imaxi;
	int imini;                     //Вводим переменные
	int max;
	int min;
	for (int i = 0; i < n; i++) {
		if (i == 0 || a[i] < min) {              //Условие для минимального числа
			min = a[i];
			imini = i;

		}

	}
	for (int i = 0; i < n; i++) {
		if (i == 0 || a[i] >= max) {            //Условие для максимального числа
			max = a[i];
			imaxi = i;

		}

	}
	swap(a[imini], a[imaxi]);                   //Меням максимум и минимум местами

	for (int i = 0; i < n; i++) {
		cout << a[i] << "  ";                //Выводим результат


	}
	return 0;//Завершение работы функции




}



