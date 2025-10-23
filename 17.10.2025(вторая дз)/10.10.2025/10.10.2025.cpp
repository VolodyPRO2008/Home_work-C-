

#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");
    //Задание 1
    int number1;
    int number2;

    cout << "Введите число откуда пойдет отсчет: "; cin >> number1; cout << "Введите число до куда пойдет отсчет: "; cin >> number2;


    for (int i = number1; i <= number2; i++) {
        cout << "Делители для числа " << i << " ";
        for (int j = 1; j <= i; j++) {
            if (i % j == 0)
                cout << j << " ";
        }
        cout << endl;
    }
    //Задание 2

        
    for (int i = 2; i <= 1000; i++) {
        int num = 0;
        for (int j = 2; j <= i; j++) {
            if (i % j == 0) {
                num += 1;
            }
        }
        if (num == 1) {
            cout << "число простое " << i <<  endl;
        }
    }
    //Задание 3

    int width, height, a = 0;
    cout << "Введите ширину фигуры: "; cin >> width; cout << "Введите высоту фигуры: "; cin >> height;
    int b = (width / 2), c = (width / 2) + 2;


    if ((width % 2 == 0 || height % 2 == 0) || (width < 0 || height < 0)) {
        cout << "Ошибка, введите нечетное число ";
    }
    else {
        for (int i = 1; i < height; i++) {
            if (i == (height / 2) + 1) {
                for (int el = 1; el <= width; el++)
                    cout << "*";
                cout << endl;
            }
            for (int j = 1; j <= width; j++) {
            if (i >= (height / 2) + 1) {
                if (j == c) {
                    cout << "*";
                }
                else if (j == (width / 2) + 1) {
                    cout << "*";
                }
                else if (j == b) {
                    cout << "*";
                    b -= 1;
                }
                else
                    cout << " ";
            }
                else if (j == (width / 2) + 1) {
                    cout << "*";
                }

                else if (j == i)
                cout << "*";
                else if (j == width - a) {
                    cout << "*";
                    a++;
                }
                else
                    cout << " ";
            }
        cout << endl;
        if (i >= (height / 2) + 1) {
             c++;
            }
        }
    }

    //задание 4

    int time = 0;

    for (int i = 1; i <= 9; i++) {
        for (int j = 0; j <= 8; j++) {
           for (int el = 0; el <= 9; el++) {
                time += 3;
                if (i != j && i != el && el != j)
                    cout << i << j << el << endl;
            }
        }

    }
    cout << "Вот сколько времени человек будет открывать чемодан в худем случае: " << time  << " секунд" << endl;

    //задание 5

    int all_workers = 0;
    for (int i = 1; i <= 12; i++) {
        int march, april, may, summa = 0;
        cout << "Введите сколько получил " << i << " работник за Март: "; cin >> march; cout << "Введите сколько получил этот же работник за Апрель: "; cin >> april; cout << "Введите сколько получит за Май: "; cin >> may;
        summa = march + april + may;
        cout << "Работник " << i << " получит " << summa << " за квартал" << endl;
        all_workers += summa;
    }
    cout << "Зарплата всех работников за квартал: " << all_workers;
}

