

#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Ru");
    //Задание 1
    int grade,grade1, grade2, grade3, grade4, grade5;

    cout << "Введите оценки которые получил студент: " << endl; cin >> grade1; cin >> grade2; cin >> grade3; cin >> grade4; cin >> grade5;

    grade = (grade1 + grade2 + grade3 + grade4 + grade5) / 5;


    switch (grade) {
    case 0:
        cout << "Студент не прошел" << endl;
        break;
    case 1:
        cout << "Студент не прошел" << endl;
        break;
    case 2:
        cout << "Студент не прошел" << endl;
        break;
    case 3:
        cout << "Студент не прошел" << endl;
        break;
    case 4:
        cout << "Студент прошел" << endl;
        break;
    case 5:
        cout << "Студент прошел" << endl;
        break;
    default:
        cout << "Студент прошел" << endl;
        break;
    }
    //Задание 2

    int number;

    cout << "Введите число: " << endl; cin >> number;

    switch (number % 2) {
    case 0:
        cout << number * 3 << endl;
        break;
    default:
        cout << number / 2 << endl;
        break;
    }
}


