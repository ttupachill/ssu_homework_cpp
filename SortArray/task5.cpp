#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

void fill(vector<vector<int> > &data, int n){ 
    ifstream in("input.txt");
    int tmp;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            in >> tmp;
            data[i].push_back(tmp);
        }
    }
}
void out_file(vector< vector<int> > data){
    ofstream out("output1.txt");
    for (int i = 0; i < data.size(); i++){
        for (int j = 0; j < data[i].size(); j++)
            out << data[i][j] << " ";
        out << endl;
    }
}
int r(){
    int n;
    cout << "Введите размерность массива: ";
    cin >> n;
    return n;
}
// Функция для преобразования поддерева в двоичную кучу
void heapify(vector<int>& data, int n, int i) {
    int largest = i; 
    int left = 2 * i + 1; // левый ребенок
    int right = 2 * i + 2; // правый ребенок

    // Если левый дочерний элемент больше корня
    if (left < n && data[left] > data[largest])
        largest = left;

    // Если правый дочерний элемент больше, чем самый большой элемент на данный момент
    if (right < n && data[right] > data[largest])
        largest = right;

    // Если самый большой элемент не корень
    if (largest != i) {
        swap(data[i], data[largest]); // Поменять

       
        heapify(data, n, largest);
    }
}

// Основная функция, выполняющая пирамидальную сортировку
void Sort(vector<int>& data) {
    int n = data.size(); 

    // Построение кучи (перегруппировка массива)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(data, n, i);

    // Один за другим извлекаем элементы из кучи
    for (int i = n - 1; i >= 0; i--) {
        // Меняем местами
        swap(data[0], data[i]);
        heapify(data, i, 0);
    }
}
int main(){
    int n = r();
    vector<vector<int> > data(n);
    fill(data, n);
    for(int j = 0; j < data.size(); j++){
        vector<int> tmp;
        for(int i = 0; i < data.size(); i++){
            tmp.push_back(data[i][j]);
        }
        Sort(tmp);
        for(int i = 0; i < data.size(); i++){
            data[i][j] = tmp[i];
        }
    }
    out_file(data);
    cout << "Отсортированный массив сохранён в файл output.txt" << endl;
    return 0;
}