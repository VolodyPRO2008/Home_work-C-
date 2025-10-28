#include <iostream>
#include <time.h>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    //Задания 1
    int numbers1;
    int numbers2;

    cout << "Введите первое целое число: ";cin >> numbers1; cout << "Введите второе целое число: "; cin >> numbers2;
    cout << numbers1 << " + " << numbers2  << " = " << numbers1 + numbers2 << endl;

    //Задания 2


    int number;

    cout << "Введите число, программа выведит оно четное или нет: "; cin >> number;

    if (number % 2 == 0) {
        cout << "Число четное " << endl;
    }
    else if (number % 2 != 0 ) {
        cout << "Число не четное " << endl;
    }

    //Задания 3

    for (int i = 1; i <= 10; i++) {
        cout << i << " в кубе = " << i * i * i << endl << endl;
    }

    //Задания 4

    const int size = 8;
    int arr[size];
    int max = 0;
    
    for (int i = 0; i < size; i++) {
        arr[i] =  rand() % 10 + 5;
        cout << arr[i] << endl;
    }
    cout << endl;
    for (int i = 1; i < size; i++) {
        if (arr[i - 1] < arr[i]) {
            max = arr[i];
        }
    }
    cout << "Самое большое число в массиве: " << max << endl << endl << endl;
    //Задания 5


    const int res = 3;
    const int cos = 3;
    int a  = 1;
    int arrey[cos][res];
    int i = 0;
    for (; i < cos;) {

        for (int j = 0; j < res; j++) {
            cout << a;
            a++;
        }
        cout << endl;
        i++;
    }






return 0;
}