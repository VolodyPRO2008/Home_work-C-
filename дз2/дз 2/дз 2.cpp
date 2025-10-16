// дз 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL,"Ru");
    // задание 1
    char ch = '.';
    int ch_code;
    ch_code = int(ch);
    cout << ch_code;


    if ((ch_code >=65 && ch_code <= 90) || (ch_code >=97 && ch_code <= 122)) {
       cout << "Вы ввели букву" << endl;
    }
    else if (ch_code >= 48 && ch_code <= 57 ) {
       cout << "Вы ввели цифру" << endl;
    }
    else if (ch_code == 46 || ch_code == 44 || ch_code == 33 || ch_code == 63) {
       cout << "Вы ввели знак препинания" << endl;
    }
    else {
       cout << "Вы ввели что-то другое" << endl;
    }
    //задание 2
    int choice, dialogue_duration;


    cout << "Введите какой оператор вы ходите выбрать: " << endl << endl;
    cout << "MTS: 180 руб за минуту (1)" << endl;
    cout << "Билайн: 200 руб за минуту (2)" << endl;
    cout << "Yota: 170 руб за минуту (3)" << endl;
    cout << "Мегафон: 220 руб за минуту (4)" << endl;
    cout << "Теле2.: 190 руб за минуту (5)" << endl;

    cin >> choice;

    cout << "Введите сколшько минут вы будуите разговарить по телефону: " << endl; cin >> dialogue_duration;

    switch (choice) {
    case 1:
       dialogue_duration = 180 * dialogue_duration;
       cout << "Ваша стоимость" << dialogue_duration << endl;
       break;
    case 2:
       dialogue_duration = 200 * dialogue_duration;
       cout << "Ваша стоимость" << dialogue_duration << endl;
       break;
    case 3:
       dialogue_duration = 170 * dialogue_duration;
       cout << "Ваша стоимость" << dialogue_duration << endl;
       break;
    case 4:
       dialogue_duration = 220 * dialogue_duration;
       cout << "Ваша стоимость" << dialogue_duration << endl;
       break;
    case 5:
       dialogue_duration = 190 * dialogue_duration;
       cout << "Ваша стоимость" << dialogue_duration << endl;
       break;
    default:
       cout << "Вы ввели не ту команду, пожалуйста повторите еще раз" << endl;
    }
    //задание 3 
    int a1;
    int f1; 
    int b1;
    int c1 = 0;
    int v = 0;
    cout << "Введите доход который получит Вася"<< endl; cin >> a1;
    f1 = a1;
    cout << "Введите солкько раз Вася опаздал" << endl; cin >> b1;
    if (1 <= b1) {
        for (int i = 1; i <= b1; i++) {
            if (i % 3 == 0) {
                c1++;
                v = a1 * 0.2;
                a1 += v;

            }
        }

        cout << "Строчек надо напичатать для такой зарплаты: " << a1;
        
    }
         
    else cout << a1 * 2;
}

