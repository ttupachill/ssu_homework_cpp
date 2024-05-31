#include <iostream>
using namespace std;
int fact_rec(int n) //Рекурсивная функция
{
    if (n==0)
        return 1;
    return n*fact_rec(n-1);
}

int fact(int n)//Функция
{
    int p = 1;
    for (int i = 1; i <= n; ++i) {
        p = p * i;
    }    
    return p;
} 



int main()
{
    setlocale(LC_ALL,"RUS");
    int a; cout<<"Введите число:";cin>>a;
    cout<<"Факториал числа(рекурсия):"<<fact_rec(a)<<endl;
    cout<<"Факториал числа:"<<fact(a)<<endl;
    return 0;
}
