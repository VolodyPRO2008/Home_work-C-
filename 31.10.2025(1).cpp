
#include <iostream>
#include <time.h>
using namespace std;


void number_search(int arr[2][5],int number,char znak) {
    switch (znak) {
    case '*':
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 5; j++) {
                arr[i][j] = number;
                cout << number << " ";
                number *= 2;
            }
            cout << endl;
        }
        break;
    case '+':
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 5; j++) {
                arr[i][j] = number;
                cout << number << " ";
                number += 1;
            }
            cout << endl;
        }
        break;
    }

}


int main()
{
    setlocale(LC_ALL,"RU");
    //Задание 1-2
    srand(time(NULL));
    const int res = 2;
    const int cos = 5;

    int array[res][cos], number;
    char znak;

    cout << "Введите число с которого будет начинаться функция массива: ";  cin >> number;
    cout << "Введите знак (+ или *): "; cin >> znak;
    number_search(array, number,znak);
    //Задание 3
    int arr[2][6] = { {1,2,0,4,5,3}, {4,5,3,9,0,1} };

    cout << "Исходный массив:\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 6; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    int shifts = 2;

    for (int s = 0; s < shifts; s++) {
        for (int i = 0; i < 2; i++) {
            int last = arr[i][5];
            for (int j = 5; j > 0; j--) {
                arr[i][j] = arr[i][j - 1];
            }
            arr[i][0] = last;
        }
    }

    cout << "\nПосле сдвига вправо на " << shifts << ":\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 6; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    


}

