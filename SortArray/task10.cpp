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

void gnomeSort(vector<int>& arr) {   // Функция гномьей сортировки
    int pos = 0;                        
    while (pos < arr.size()) {        // Пока не достигли конца вектора
        if (pos == 0 || arr[pos] >= arr[pos - 1]) {  // Если текущий элемент найден в правильном месте
            pos++;                      // Переходим к следующему элементу
        } else {                        // Если текущий элемент нужно поменять местами с предыдущим
            swap(arr[pos], arr[pos - 1]);   // Меняем элементы местами
            pos--;                      // Возвращаемся назад
        }
    }
}
int main(){
    int n = r();
    vector<vector<int> > data(n);
    fill(data, n);
    for(int i = 0; i < data.size(); i++){
        gnomeSort(data[i]);
        cout << "+";
        if(i % 2 == 0) 
            reverse(data[i].begin(), data[i].end());
    }
    out_file(data);
    cout << "Отсортированный массив сохранён в файл output.txt" << endl;
    return 0;
}