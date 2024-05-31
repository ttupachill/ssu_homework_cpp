#include <iostream> //Бибилиотека ввода-вывода
using namespace std; //пространство стандартных имен

int from_bin_rec(int bin, int m = 1) { //Рекурсивная функция, для перевода в десятичную систему
    if (bin == 0){ 
        return 0;   //Условие для нуля
    }
    return bin % 10 * m + from_bin_rec(bin / 10, 2 * m); //Вызов функции
}

// from_bin_rec(101, 1) -> 1 * 1 + from_bin_rec(10, 2)
// from_bin_rec(10, 2) -> 0 * 2 + from_bin_rec(1, 4)
// from_bin_rec(1, 4) -> 1 * 4 + from_bin_rec(0, 8)
// from_bin_rec(0, 8) -> 0

int main() {

    int n;cout<<"Введите число:"; cin >> n;
    cout <<"Новое число:" << from_bin_rec(n);
    return 0;
}
