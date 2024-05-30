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
void insertionSort(vector<int>& arr) { // Функция для сортировки вектора работников методом вставок
    for (int i = 1; i < arr.size(); ++i) { // Проходим по всем элементам вектора, начиная со второго
        int key = arr[i]; // Запоминаем текущий элемент как ключ
        int j = i - 1; 

        while (j >= 0 && key < arr[j]) { // Пока не достигнут начало вектора и ключ меньше предыдущего элемента
            arr[j + 1] = arr[j]; // Перемещаем элементы вправо
            j--;
        }

        arr[j + 1] = key; // Вставляем ключ на правильное место
    }
}

void side_diagonal(vector<vector<int> > &data, int n){
    for(int k = 0; k < 2*n-2; k++){
        vector<int> tmp;

        for(int i = 0; i < n; i++){
            if(k - i < n && k - i >= 0)
                tmp.push_back(data[i][k - i]);
        }
        insertionSort(tmp);
        int l = 0;
        for(int i = 0; i < n; i++){
            if(k - i < n && k - i >= 0){
                data[i][k - i] = tmp[l];
                l++;
            }
        }
    }
}

int main(){
    int n = r();
    vector<vector<int> > data(n);
    fill(data, n);
    side_diagonal(data, n);
    out_file(data);
    cout << "Отсортированный массив сохранён в файл output.txt" << endl;
    return 0;
}