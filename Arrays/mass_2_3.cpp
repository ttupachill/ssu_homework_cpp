#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "RUS");
	int n;
	cout << "Введите размер матрицы ";
	cin >> n;
	int** a = new int* [n];            //Двумерный динамический массив с n строками
	for (int i = 0; i < n; i++) {
		a[i] = new int[n];            //Выделение памяти для каждого указателя
	}
	cout << " Вводите числа построчно" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	cout << "Исхдоный массив\n";
	for (int i = 0; i < n; i++, cout << endl) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
	}
	int mn = a[0][0], mx = a[0][0];                 //mn 1-ый минимальный чёт эл заштрихов    mx 1-ый максимальный нечёт эл не заштрихов
	int i_mn, i_mx, j_mn, j_mx;                    //i-е mn и mx, j-е mn и mx
	int k1 = 0, k = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (a[i][j] % 2 == 0 and a[i][j] < mn) {                //Минимальные чёт элементы, заштрихованная область
				mn = a[i][j];
				i_mn = i;
				j_mn = j;
				k1++;                 //Счётчик
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i][j] % 2 != 0 and a[i][j] > mx) {               //Максимальные нечёт элементы, не заштрихованная область
				mx = a[i][j];
				i_mx = i;
				j_mx = j;
				k++;             //счётчик
			}
		}
	}
	if (k1 != 0 and k != 0) {                           //условие когда есть все нужные элементы в массиве
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				swap(a[i_mn][j_mn], a[i_mx][j_mx]);            //меняем их местами
			}
		}
	}
	else {                                                   //иначе
		if (k == 0) {
			cout << "Нечётного элемента нет в массиве\n ";
		}
		if (k1 == 0) {
			cout << "Чётного элемента нет в массиве\n ";
		}
	}
	cout << "Новый массив\n";
	for (int i = 0; i < n; i++, cout << endl) {                        //Вывод нового массива
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}

	}

}