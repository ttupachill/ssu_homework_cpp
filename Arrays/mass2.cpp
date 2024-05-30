#include <iostream>//Бибилиотека ввода-вывода
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;//Пространство стандартных имен
int main() {
	setlocale(LC_ALL, "RUS");//Использование русского языка
	int n;//Объявляем N
	cout << "Введите кол-во элементов:  ";             //размер массива
	cin >> n;//Ввод с клавиатуры
	int *mass = new int[n];                //Выделяем память под массив
	srand((unsigned int)time(NULL));   //Генерация рандомного числа
	for (int i = 0; i < n; i++) {
		mass[i] = rand() % 15;          //Псевдослучайное число
		cout << mass[i] << "  ";

	}
	int s = 0;  //Создаем счетчик
	int min = mass[0]
	for (int i = 0; i < n; i++) {
		if (mass[i] % 2 != 0 && mass[i] % 3 != 0) {      //Основное условие
			cout << i << "  ";
			s += 1;
		}
	}
	for (int i = 0; i < n; i++) {
		if (mass[i] % 2 == 0 && mass[i] % 3 == 0 && s == 0) {         //Если таких элементов нет, то выводим "
			cout << "Таких элементов нет ";//Вывод сообщения "Таких элементов нет"
		
	}


	return 0;//Завершение работы функции
}
