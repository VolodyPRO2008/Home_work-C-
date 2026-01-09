

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	//задание 1
	srand(time(NULL));
	const int res = 5;
	const int cos = 10;
	int sum = 0, max, min;
	int array[res][cos];

	for (int i = 0; i < res; i++) {
		for (int j = 0; j < cos; j++) {
			array[i][j] = rand() % 50;
		}
	}
	max = array[0][0];
	min = array[0][0];
	for (int i = 0; i < res; i++) {
		for (int j = 0; j < cos; j++) {
			sum += array[i][j];
			if (min > array[i][j]) {
				min = array[i][j];
			}
			if (max < array[i][j]) {
				max = array[i][j];
				}

		}
	}
	int rez = sum / (res * cos);
	cout << "Сумма чисел" << sum << endl;
	cout << "Среднее арифметическое всех элементов массива: " << rez << endl;
	cout << "max " << max << " and  min " << min << endl<< endl;

	//задание 2


	for (int i = 0; i < res; i++) {
		sum = 0;
		for (int j = 0; j < cos; j++) {
			if (array[i][j] >= 10)
				cout << array[i][j] << " ";
			else
				cout << array[i][j] << "  ";
			sum += array[i][j];

		}
		cout << "          |     " << sum << endl;
		cout << "- - - - - - - - - - - - - - -" << endl;
	}
	for (int i = 0; i < cos; i++) {
		sum = 0;
		for (int j = 0; j < res; j++) {
			sum += array[j][i];
		}
		if (sum >= 10)
			cout << sum << " ";
		else
			cout << sum << "  ";

	}
	sum = 0;
	for (int i = 0; i < res; i++) {
		for (int j = 0; j < cos; j++)
			sum += array[i][j];
	}
	cout << "  |  " << sum << endl; 


	//задание 3

	const int cos2 = 5;
	const int res2 = 5;
	int arr[cos2][res2];


	cout << endl <<"Матрица 5x10" << endl << endl;
	for (int i = 0; i < res; i++) {
		for (int j = 0; j < cos; j++) {
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << "Матрица 5x5" << endl << endl;
	for (int i = 0; i < res2;i++) {
		for (int j = 0; j < cos2 * 2; j++) {
			arr[i][j] = array[i][j] + array[i][j + 1];
			cout << arr[i][j] << " ";
			j++;
		}
		cout << endl;
	}
}