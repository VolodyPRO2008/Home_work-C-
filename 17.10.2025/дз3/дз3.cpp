
//

#include <iostream>
#include <ctime>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Ru");
    srand(time(NULL));
    //задание 1
    int level, num1, num2, answer;

    cout << "Введите уровень для проверки таблицы умножения: (1 - 5) "; cin >> level;

    switch (level) {
    case 1:
        num1 = 1 + (rand() % 5);
        num2 = 2 + (rand() % 6);
        cout << "Сколько будет " << num1 << " * " << num2 << endl; cin >> answer;
        if (answer == num1 * num2) {
            cout << "Ответ правильный" << endl;
        }
        else {
            cout << "Ответ не правильный." << "Правильным ответом является " << num1 * num2 << endl;
        }
        break;
    case 2:
        num1 = 4 + (rand() % 7);
        num2 = 5 + (rand() % 9);
        cout << "Сколько будет " << num1 << " * " << num2 << endl; cin >> answer;
        if (answer == num1 * num2) {
            cout << "Ответ правильный" << endl;
        }
        else {
            cout << "Ответ не правильный." << "Правильным ответом является " << num1 * num2 << endl;
        }
        break;
    case 3:
        num1 = 6 + (rand() % 16);
        num2 = 7 + (rand() % 11);
        cout << "Сколько будет " << num1 << " * " << num2 << endl; cin >> answer ;
        if (answer == num1 * num2) {
            cout << "Ответ правильный" << endl;
        }
        else {
            cout << "Ответ не правильный." << "Правильным ответом является " << num1 * num2 << endl;
        }
        break;
    case 4:
        num1 = 10 + (rand() % 20);
        num2 = 5 + (rand() % 18);
        cout << "Сколько будет " << num1 << " * " << num2 << endl; cin >> answer ;
        if (answer == num1 * num2) {
            cout << "Ответ правильный" << endl;
        }
        else {
            cout << "Ответ не правильный." << "Правильным ответом является " << num1 * num2 << endl;
        }
        break;
    case 5:
        num1 = 10 + (rand() % 34);
        num2 = 28 + (rand() % 43);
        cout << "Сколько будет " << num1 << " * " << num2 << endl; cin >> answer;
        if (answer == num1 * num2) {
            cout << "Ответ правильный" << endl;
        }
        else {
            cout << "Ответ не правильный." << "Правильным ответом является " << num1 * num2 << endl;
        }
        break;
    default:
        cout << "Вы ввели не правильный уровень" << endl;
    }
    //задание 2

    cout << "   *    " << endl << "  ***  " << endl << " ***** " << endl << "*******" << endl << " ***** " << endl << "  ***  " << endl << "   *   " << endl;





}


