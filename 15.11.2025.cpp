

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Задание 1
void print_number_system(int number, int number_system) {
    if (number_system > 2 && number_system <= 36) {

        int a = 0;
        int number_two = number;
        for (int i = 1; 0 < number_two;) {
            number_two = number_two / number_system;
            a++;
        }
        int* arr = new int[a];
        for (int i = 0; i < a; i++) {
            arr[i] = number % number_system;
            number = number / number_system;

        }
        for (int i = 0; i < a; a--) {
            if (arr[a - 1] > 9) {
                int acscii_code = (arr[a - 1] - 10) + 65;
                char sumbol = acscii_code;
                cout << sumbol;
            }
            else
                cout << arr[a - 1];
        }
        delete[] arr;
    }
    else {
        cout << "Вы ввели не ту систему счисление, пожалуйста попробуйте заного";
    }
}
//Задание 2

void brositKubiki() {
    int kubik1 = rand() % 6 + 1;  // первый кубик (1-6)
    int kubik2 = rand() % 6 + 1;  // второй кубик (1-6)   
    int sum_kubik = kubik1 + kubik2;

    srand(time(0));

    int playerTotal = 0;
    int computerTotal = 0;

    cout << "ИГРА В КУБИКИ\n";
    cout << "Будет 5 бросков. У кого сумма больше - тот победил!\n\n";

    // Выбор кто ходит первым
    int choice;
    cout << "Кто первый бросает?\n";
    cout << "1 - Я\n";
    cout << "2 - Компьютер\n";
    cout << "Ваш выбор: ";
    cin >> choice;

    for (int i = 1; i <= 5; i++) {
        cout << "\n--- Бросок " << i << " ---\n";

        if (choice == 1) {
            // Сначала человек
            cout << "Ваш бросок... (нажмите Enter)";
            cin.ignore();
            cin.get();

            int sum = sum_kubik;  // ВЫЗОВ ФУНКЦИИ
            playerTotal += sum;
            cout << "Сумма очков: " << sum << endl;
            cout << "Ваш счет: " << playerTotal << endl;

            // Теперь компьютер
            cout << "\nБросок компьютера...\n";
            sum = sum_kubik;  // ВЫЗОВ ФУНКЦИИ
            computerTotal += sum;
            cout << "Сумма очков: " << sum << endl;
            cout << "Счет компьютера: " << computerTotal << endl;
        }
        else {
            // Сначала компьютер
            cout << "Бросок компьютера...\n";
            int sum = sum_kubik;  // ВЫЗОВ ФУНКЦИИ
            computerTotal += sum;
            cout << "Сумма очков: " << sum << endl;
            cout << "Счет компьютера: " << computerTotal << endl;

            // Теперь человек
            cout << "\nВаш бросок... (нажмите Enter)";
            cin.ignore();
            cin.get();

            sum = sum_kubik;  // ВЫЗОВ ФУНКЦИИ
            playerTotal += sum;
            cout << "Сумма очков: " << sum << endl;
            cout << "Ваш счет: " << playerTotal << endl;
        }
    }

    // Итоги
    cout << "\n=== ИТОГИ ===\n";
    cout << "Ваш общий счет: " << playerTotal << endl;
    cout << "Счет компьютера: " << computerTotal << endl;

    // Средние значения
    cout << "\nСреднее за бросок:\n";
    cout << "Вы: " << playerTotal / 5.0 << endl;
    cout << "Компьютер: " << computerTotal / 5.0 << endl;

    // Кто победил
    cout << "\n";
    if (playerTotal > computerTotal) {
        cout << "ВЫ ПОБЕДИЛИ!\n";
    }
    else if (computerTotal > playerTotal) {
        cout << "ПОБЕДИЛ КОМПЬЮТЕР\n";
    }
    else {
        cout << "НИЧЬЯ!\n";
    }
}


//Задание 3

void rectangle(int width, int height) {
    for (int i = 0; i < height;i ++) {
        for (int j = 0; j < width; j++) {
            cout << "*";
        }
        cout << endl;
    }
}
//Задание 4

void factorial(int number ) {
    int a = 1;
    for (int i = 1; i <= number; i++)
        a *= i;
    cout << a;
}

//Задание 5

void prime_number(int number) {
    int a = 0;
    for (int i = 2; i < number; i++) {
        if (number % 2 == 0) {
            a++;
        }
    }
    if (a == 1) {
        cout << "это число простое" << endl;
    }
    else {
        cout << "это число не простое" << endl;
    }
}

//Задание 6

void min_max_element(int arr[], int size) {
    int a = 1;
    for (int i = 0; i < size;i++) {
        if (arr[i] < a) {
            a = arr[i];
        }
    }
    cout << "Самый маленький элемент массива: " << a << endl;
    a = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > a) {
            a = arr[i];
        }
    }
    cout << "Самый большой элемент массива: " << a << endl;
}

//Задание 7

void flip_the_array(int array[],int size ) {
    int a = size, temp = 0;

    for (int i = 0; i < size / 2; i++) {
        int temp = array[i];
        array[i] = array[size - 1 - i];
        array[size - 1 - i] = temp;
    }
    for (int i = 0; i < a; i++) {
        cout << array[i];
    }
}



int main()
{
    setlocale(LC_ALL, "Ru");
    int number, number_system;
    cout << "Введите число для перевода в систему счисления: "; cin >> number;

    cout << "Введите систему счисления (от 2 до 36): "; cin >> number_system;

    print_number_system(number, number_system);
    cout << endl;

    brositKubiki();

    int width, height;
    cout << "Введите ширину прямоугольника: "; cin >> width;

    cout << "Введите высоту прямоугольника: "; cin >> height;

    rectangle(width, height);
    cout << endl;

    int nunber;
    cout << "Введите число для факториала: "; cin >> number;
    factorial(number);

    cout << endl;

    int num;
    cout << "Введите число, программа выводит простое оно или нет: "; cin >> num;
    prime_number(num);

    int arr[6] = { 1,2,3,4,5,11 };

    cout << "Внутри этого массива: " << endl;

    min_max_element(arr, 6);
    ;
    int arrey[4]{ 1,2,3,4 };
    flip_the_array(arrey, 4);



}

