
#include <iostream>
using namespace std;


//Задание 1

void square_matrix(int size, int** arr, int** array) {
    int a = 0; 
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            arr[i][j] = 1 + rand() % 100;
        }
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < size; i = i++) {
        for (int j = 0; j < size; j++) {
            int b = arr[i][j + i];
            if (b > a) {
                a = b;
            }
            break;
        }
    }
    cout << "Максимальный элемент главной диагонали: " << a;

    for (int i = 0; i < size; i++) {
    
        for (int j = 0; j < size; j++) {
         
            if (j < size - 1) {
         
                for (int k = 0; k < size - j - 1; k++) {
                    if (arr[i][k] > arr[i][k + 1]) {
            
                        int temp = arr[i][k];
                        arr[i][k] = arr[i][k + 1];
                        arr[i][k + 1] = temp;
                    }
                }
            }
        }
    }
    cout << endl << endl << "Измененый массив по вазрастанию: " << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
//Задание 2
int find_nod(int a, int b) {
    if (b == 0) {
        return a;
    }
    else {
        return find_nod(b, a % b);
    }
}

//Задание 3

int secret[4], tries = 0;

void makeNumber() {
    // Простой способ получить "случайные" цифры
    for (int i = 0; i < 4; i++) {
        secret[i] = (i * 7 + 3) % 10;
        for (int j = 0; j < i; j++) {
            if (secret[j] == secret[i]) {
                secret[i] = (secret[i] + 1) % 10;
                j = -1;
            }
        }
    }
    if (secret[0] == 0) secret[0] = 1;
}

void play() {
    tries++;

    int num;
    cout << endl << "Попытка " << tries << ": ";
    cin >> num;

    // Проверка числа
    if (num < 1000 || num > 9999) {
        cout << "Только 4-значное число!" << endl;
        play();
        return;
    }

    // Разбиваем на цифры
    int user[4];
    user[0] = num / 1000;
    user[1] = (num / 100) % 10;
    user[2] = (num / 10) % 10;
    user[3] = num % 10;

    // Проверка на повторы
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            if (user[i] == user[j]) {
                cout << "Цифры не должны повторяться!" << endl;
                play();
                return;
            }
        }
    }

    // Считаем быков и коров
    int bulls = 0, cows = 0;
    for (int i = 0; i < 4; i++) {
        if (user[i] == secret[i]) {
            bulls++;
        }
        else {
            for (int j = 0; j < 4; j++) {
                if (user[i] == secret[j]) {
                    cows++;
                    break;
                }
            }
        }
    }

    cout << bulls << " быков, " << cows << " коров" << endl;

    if (bulls == 4) {
        cout << "Угадал за " << tries << " попыток!" << endl;
    }
    else {
        play();
    }
}



int main()
{

    setlocale(LC_ALL, "Ru");


    srand(time(NULL));

    int size;
    cout << "Введите размер матрицы: ";
    cin >> size;

    // Создание матрицы
    int** matrix = new int* [size];
    for (int i = 0; i < size; i++) {
        matrix[i] = new int[size];
    }

    int** array = new int* [size];
    for (int i = 0; i < size; i++) {
        matrix[i] = new int[size];
    }

    // Заполнение матрицы
    square_matrix(size, matrix,array);


    int num1, num2;

    cout << "Введите первое число: " << endl;
    cin >> num1;

    cout << "Введите второе число: " << endl;
    cin >> num2;

    // Находим НОД
    int result = find_nod(num1, num2);

    cout << "Наибольший общий делитель чисел и равен: " << num1, num2, result;
    cout << endl << endl;


    cout << "Быки и коровы" << endl;
    cout << "Угадай 4-значное число" << endl;
    cout << "Цифры не повторяются" << endl;

    makeNumber();

    // Подсказка (можно удалить)
    cout << "(Число: ";
    for (int i = 0; i < 4; i++) cout << secret[i];
    cout << ")" << endl;

    play();


    return 0;
}


