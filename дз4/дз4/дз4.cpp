
#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Ru");
    //задание 1
    int a,sum = 0;
    cout << "Введите число от которого будет делать отсчет "; cin >> a;

    for (int i = 0; a < 500; a++)
        sum++;
    cout << "Сумма = " << sum << endl;
    //задание 2

    int x, y;

    cout << "Введите число которые будем возводить в степень: "; cin >> x;
    cout << "Ввдеите степень: "; cin >> y;

    for (int i = 0; i <= y; i++)
        x *= y;
    cout << "Число в степени: " << x << endl;

    //задание 3

    double sum1 = 0;

    for (int i = 1; i < 1000; i++) 
        sum1 += i;
    cout << "Сред.Арифмет цифр от 1 до 20 = " << sum1 / 1000 << endl;

    //задание 4
    
    int sum2 = 1;

    for (int i = 1; i < 20; i++)
        sum2 *= i;
    cout << "Проиведение цифр от 1 до 20= " << sum2 << endl;

    //задание 5

    int num1;

    cout << "Ввдеите число для того чтобы ввывеси его таблицу умножения: ";  cin >> num1;
    for (int i = 1; i <= 10; i++)
        if (i < 10)
            cout << i << ".      " << num1 << " * " << i << " = " << num1 * i << endl;
        else 
            cout << i << ".     " << num1 << " * " << i << " = " << num1 * i << endl;

}

