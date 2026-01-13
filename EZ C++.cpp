#include <iostream>
#include <string>

using namespace std;

int sum(int a, int b) {
    return a + b;
}

int conversion_from_Celsius_to_Fahrenheit(int degrees) {
    return degrees * 9 / 5 + 32;
}

void even_or_odd(int number) {
    if (number % 2 == 0) {
        cout << "Число четное";
    }
    else {
        cout << "Число нечетное";
    }
}

void Leap_year(int year) {
    if (year % 400 == 0) {
        cout << "год весокосный";
    }
    else if (year % 4 == 0 && year % 100 != 0) {
        cout << "год весокосный";
    }
    else {
        cout << "год не весокосный";
    }
}

int array_min(int arr[], int size) {
    int min = arr[0];
    for (int i = 0; i < size; i++)
        if (arr[i] < min) {
            min = arr[i];
        }
    return min;
}

int max(int number_one, int number_two) {
    if (number_one > number_two) {
        return number_one;
    }
    else return number_two;
}

void isPrime(int number) {
    int a = 0;
    for (int i = 1; i < number; i++) {
        if (number % i == 0) {
            a++;
        }
     }
    if (a == 1) {
        cout << "Число простое" << endl;
    }
    else cout << "Число не простое" << endl;
}

int max_array(int* arr, int size) {
    int a = 0;
    for (int i = 0; i < size; i++) {
        a += arr[i];
    }
    return a;
}

int arithmetic_mean(int arr[], int size) {
    int a = 0;
    for (int i = 0; i < size; i++) {
        a += arr[i];
    }
    return a / size;
}




int main()
{
    setlocale(0, "");

    cout << "Задание 1.1:" << endl;
    int a, b;
    cout << "Введи первое число: ";  cin >> a;
    cout << "Введи второе число: ";  cin >> b;

    cout << sum(a, b);
    cout << endl;

    cout << "Задание 1.2:" << endl;
    int degree;

    cout << "Введите грудусы в Фаренгейтах: "; cin >> degree;

    cout << conversion_from_Celsius_to_Fahrenheit(degree);
    cout << endl;

    cout << "Задание 2.1:" << endl;
    int number;
    cout << "Введите число "; cin >> number;

    even_or_odd(number);
    cout << endl;

    cout << "Задание 2.2:" << endl;
    int year;

    cout << "Введите год: "; cin >> year;
    Leap_year(year);

    cout << endl;
    cout << "Задание 3.1:" << endl;

    int num, c = 0;
    cout << "Введите число до которого будет происходить вычесление: "; cin >> num;

    for (int i = 0; i <= num; i++) {
        c += i;
    }
    cout << "сумма всех чисел " << c << endl;
    cout << "Задание 3.2:" << endl;

    int number_2;
    cout << "Введите число : "; cin >> number_2;

    cout << endl;


    for (int i = 1; i <= 10; i++) {
        cout << number_2 << " x " << i << " = " << number_2 * i << endl;
    }

    cout << "Задание 4.1:" << endl;
    int arr_min[10]{ 32,13,6,3,4,6,0,56,2,4 };

    for (int i = 0; i < 10; i++) {
        cout << arr_min[i] << " ";
    }
    cout << endl;

    cout << array_min(arr_min, 10) << endl;
    cout << "Задание 4.2:" << endl;
    int arr[3][3]{
        {10, 1, 3},
        {14, 5, 2},
        {0, 0, 3}
    };

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
     
        cout << endl;
    }

    for (int i = 0; i < 3; i++) {
        int x = 0;
        for (int j = 0; j < 3; j++) {
            x += arr[i][j];
        }
        cout << "Сумма строки " << i + 1 << " = " << x << endl;
    }

    cout << "Задание 5.1:" << endl;

    int max_one, max_two;

    cout << "Введи первое число: "; cin >> max_one;
    cout << "Введи второе число: "; cin >> max_two;

    cout << "Самый большой из двух цифр: " << max(max_one, max_two) << endl;

    cout << "Задание 5.2:" << endl;

    int prime;
    cout << endl << "Ввидите число: "; cin >> prime;

    isPrime(prime);
    cout << "Задание 6.1:" << endl;

    int x1, x2;

    cout << "Введите x1: "; cin >> x1; cout << "Введите x2: "; cin >> x2;


    int* ptx1 = &x1;
    int* ptx2 = &x2;
    cout << "До перестоновки: " << endl;

    cout << "x1" << " = " << *ptx1 << " x2 " << " = " << *ptx2 << endl;

    ptx1 = &x2;
    ptx2 = &x1;

    cout << "После: " << endl;
    cout << "x1" << " = " << *ptx1 << " x2 " << " = " << *ptx2 << endl;

    cout << "Задание 6.2:" << endl;


    int arrr[5] = { 1,1,1,1,1 };

    for (int i = 0; i < 5; i++)
        cout << arrr[i] << " ";

    cout << endl << "Сумма всех элементов массива: " << max_array(arrr, 5) << endl;

    cout << "Задание 7.1:" << endl;

    string slovo;
    cout << "Введите предложение: "; cin >> slovo;
    int m = 0;
    bool perebor = true;

    for (int i = 0; perebor == true; i++) {
        if (slovo[i] != NULL) {
            m++;
        }
        else perebor = false;
    }
    cout << "Симолов в слове: " << m << endl;

    cout << "Задание 7.2:" << endl;

    int my_arr[5]{4,2,5,6,4};

    for (int i = 0; i < 5; i++) {
        cout << my_arr[i] << " ";
    }

    cout << "Среднее арифметическое: " << arithmetic_mean(my_arr, 5);

}