// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Ru");
    //задание 3

    int a = 0, days, b = 0, c = 0;


    cout << "Ввдеите сколько дней улитка ползла: " << endl; cin >> days;

    for (int i = 0; i < days; i++) {
        a = 15 + b;
        b += 2;
        c += a;
    }
    cout << c;

    //задание 4

    int a, b = 0;

    for (int i = 1; i <= 9; i++) {
        cout << "Введите что выпол орел - 0 или решка - 1: "; cin >> a;
        cout << "Введино чисел " << i << " из 9" << endl;
        if (a == 1) {
            b += 1;
        }
        else if (a == 0) {
            b += 0;
        }
        else {
            cout << "Вы не ввели 0 или 1" << endl;
            break;
        }
    }
    if (b % 2 == 0) {
        cout << "Учиник проходит" << endl;
    }
    else {
        cout << "Учиник не проходит" << endl;
    }

    //задание 5


    int month_number;
    int number_day_of_week;
    int a3 = 0;


    cout << "Введите месяц (1 - 12): ";  cin >> month_number;
    cout << "Введите день недели с которого стартует ваш месяц(1 - 7): "; cin >> number_day_of_week; cout << endl << endl << endl;


    switch (month_number) {
    case 1:
        cout << "                   Январь            " << endl;
        break;                 
    case 2:                     
        cout << "                   Февраль           " << endl;
        break;                 
    case 3:                     
        cout << "                    Март             " << endl;
        break;                 
    case 4:                     
        cout << "                   Апрель            " << endl;
        break;                 
    case 5:                     
        cout << "                    Май              " << endl;
        break;                 
    case 6:                     
        cout << "                   Июнь              " << endl;
        break;                 
    case 7:                     
        cout << "                   Июль              " << endl;
        break;             
    case 8:                     
        cout << "                   Август            " << endl;
        break;                 
    case 9:                     
        cout << "                   Сентябрь          " << endl;
        break;
    case 10:                    
        cout << "                   Октябрь           " << endl;
        break;                 
    case 11:                    
        cout << "                   Ноябрь            " << endl;
        break;                 
    case 12:                    
        cout << "                   Декабрь           " << endl;
        break;                  
    default:
        cout << "Ввдеите пожалуйста число в заданном диапозоне";
        return 1;
    }
    cout << "   Пн  " << "   Вт  " << "   Ср  " << "   Чт  " << "   Пт  " << "   Сб  " << "   Вс  " << endl;
    if (number_day_of_week <= 7 && number_day_of_week) {
        for (int i = 1; i < number_day_of_week; i++) {
            cout << "   -   ";
        }
        for (int j = 1; j <= 31; j++) {
            if (number_day_of_week < 7) {
                if (j < 10) {
                    cout << "   " << j << "   ";
                    number_day_of_week += 1;
                    if (number_day_of_week == 6)
                        a3++;
                }
                else {
                    cout << "   " << j << "  ";
                    number_day_of_week += 1;
                    if (number_day_of_week == 6)
                        a3++;
                }
            }
            else {
                cout << "   " << j << "   " << endl;
                number_day_of_week = 1;
                a3++;
            }
        }

    }
    cout << endl << "   В месяце " << a3 << " Дней" << endl;




    return 0;
}

