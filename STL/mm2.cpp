#include <iostream>  // Подключение библиотеки  ввода/вывода
#include <vector>  // Подключение векторов
#include <algorithm>  // Подключение библиотеки для стандартных алгоритмов

using namespace std;  // Пространство стандартных имен

bool odd(int x){
    return x%2==0; //Функция для удаления четных элементов
}
bool three(int y){
    return y%3==0;
}

int main() {
    setlocale(LC_ALL,"RUS");   //Использование русской клавиатуры
    int n; cout<<" Введите n:"; cin>>n;
    vector<int>vec1;   //1 вектор
    int x;
    for(int i = 0; i<n; i++){ //Создание 1 вектора
        cout<<"a[" <<i<< "] ="; //Ввод элементов 1-ой последовательности
        cin>>x;
        vec1.push_back(x);
    }
    for(vector<int>::iterator iter1 = vec1.begin();iter1 !=vec1.end(); iter1++)
    cout<<*iter1<<endl;   //Вывод вектора
     
    vector<int>vec2;   //2 вектор
    int x1; 
    for(int i = 0; i<n; i++){ //Создание 2 вектора
        cout<< "b[" <<i<< "] =";   //Ввод элементов 2-ой последовательности
        cin>>x1;
        vec2.push_back(x1);
        }
    for(vector<int>::iterator iter2 = vec2.begin();iter2 !=vec2.end(); iter2++)
    cout<<*iter2<<" "<<endl;  //Вывод вектора

    cout<<"Удаление четных элементов:\n";
    vector<int>::iterator it = remove_if(vec1.begin(), vec1.end(), odd);
    vec1.erase(it, vec1.end());

    for(vector<int>::iterator iter1 = vec1.begin(); iter1!=vec1.end(); iter1++)
    cout<<*iter1<< " "<<endl;  //Вывод вектора с удалением четных элементов

    cout<<"Замена всех чисел кратных 3 на минимальное число\n";
    int M = *min_element(vec2.begin(),vec2.end());
        replace_if(vec2.begin(),vec2.end(),three,M);

        for(vector<int>::iterator iter2 = vec2.begin(); iter2 !=vec2.end(); iter2++)
        cout<<*iter2<<" "<<endl;
        

        sort(vec1.begin(), vec1.end());
        sort(vec2.begin(),vec2.end());               //Сортировка двух последовательностей

        vector<int> result(vec1.size()+vec2.size());
        merge(vec1.begin(),vec1.end(),vec2.begin(),vec2.end(),result.begin());  //Объединение двух последовательностей

        cout <<"Объединенная и отсортированная последовательность:\n";
        for (vector<int>::iterator it2 = result.begin(); it2!=result.end(); ++it2){
            cout<<*it2<<" "<<endl;        //Вывод объединенной и отсортированной последовательности
        }
        cout<<"Удаление дубликатов:\n";
        result.erase(unique(result.begin(),result.end()));
        for(vector<int>::iterator it3 = result.begin(); it3!= result.end(); it3++)
        cout << *it3<< " ";
        return 0;

    }

