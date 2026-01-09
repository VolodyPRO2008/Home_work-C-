#include <iostream>
#include <time.h>
using namespace std;

//Задание 1



void degree_number(int number, int degree, int perf) {
	if (degree != 0) {
		perf *= number;
		degree--;
		degree_number(number, degree, perf);
	}
	else
		cout << perf;
}

//Задание 2

void stars(int quantity) {
	if (quantity != 0) {
		cout << "*";
		quantity--;
		stars(quantity);
	}
	else
		cout << endl;
}

//Задание 3

void range(int a, int b, int c) {
	if (a < b) {
		a++;
		c += a;
		range(a, b, c);
	}
	else
		cout << c;
}

//Задание 4

void findMinSequence(int arr[] = nullptr, int i = 0, int minSum = 1000000, int start = 0) {
	// Первый вызов - создаем массив
	if (arr == nullptr) {
		int numbers[100];
		srand(time(NULL));
		for (int j = 0; j < 100; j++) numbers[j] = rand() % 100 + 1;
		findMinSequence(numbers);
		return;
	}

	// Основная рекурсия
	if (i <= 90) {
		int sum = 0;
		for (int j = 0; j < 10; j++) sum += arr[i + j];

		if (sum < minSum) {
			minSum = sum;
			start = i;
		}

		findMinSequence(arr, i + 1, minSum, start);
	}
	else {
		// Вывод результата при завершении рекурсии
		cout << "Начало: " << start << "\nСумма: " << minSum << "\nЧисла: ";
		for (int j = 0; j < 10; j++) cout << arr[start + j] << " ";
	}
}
//Задание 5

void maximum_element(int arr[], int size) {
	int a = 0;

	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 30 + 1;  
	}

	for (int i = 0; i < size; i++) {
		if (arr[i] > a) { 
			a = arr[i];
		}
	}

	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl << "максимальный элемент данного массива: " << a;
}

void maximum_element(int arr[][5], int size) {
	int a = 0;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < 5; j++) {
			arr[i][j] = rand() % 30 + 1;  
		}
	}

	
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < 5; j++) {
			if (arr[i][j] > a) {  
				a = arr[i][j];
			}
		}
	}

	
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < 5; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << "максимальный элемент данного массива : " << a;
}

void maximum_element(int arr[][5][5], int size) {
	int a = 0;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < 5; j++) {
			for (int el = 0; el < 5; el++) {
				arr[i][j][el] = rand() % 30 + 1; 
			}
		}
	}

	cout << "===================================\n";

	for (int i = 0; i < size; i++) {
		cout << "Слой " << i + 1 << ":\n";
		for (int j = 0; j < 5; j++) {
			for (int el = 0; el < 5; el++) {
				cout << arr[i][j][el] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	cout << "===================================\n";

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < 5; j++) {
			for (int el = 0; el < 5; el++) {
				if (arr[i][j][el] > a) {  
					a = arr[i][j][el];
				}
			}
		}
	}
	cout << "максимальный элемент данного массива : " << a;
}

void maximum_element(int a, int b) {
	if (a < b) {
		cout << "Самый большой элемент из 2 других: " << b;
	}
	else {
		cout << "Самый большой элемент из 2 других: " << a;
	}
}

void maximum_element(int a, int b, int c) {
	if (a >= c && a >= b) {
		cout << "Самый большой элемент из 3 других: " << a;
	}
	else if (c >= a && c >= b) {
		cout << "Самый большой элемент из 3 других: " << c;
	}
	else if (b >= c && b >= a) {
		cout << "Самый большой элемент из 3 других: " << b;
	}
}

int main() {
	srand(time(NULL));


	setlocale(LC_ALL,"RU");
	int number, degree;
	cout << "Введите основание: "; cin >> number;
	cout << "Введите показатель: "; cin >> degree;

	degree_number(number,degree,1);

	cout << endl;

	int number_of_stars;
	cout << "Введите колчиство звезд: "; cin >> number_of_stars;

	stars(number_of_stars);

	cout << endl;

	int a, b;
	cout << "Введите число с которого будует отсчет: "; cin >> a;
	cout << "Введите число до куда будует отсчет: "; cin >> b;

	range(a, b, a);


	cout << endl;

	findMinSequence();

	cout << endl;

	int options;

	cout << "Введите что хотите сделать: " << endl
		<< "1) Посчитать самый большой элемент в массиве" << endl
		<< "2) Вывести самый большой элемент из 2/3 цифр" << endl;
	cin >> options;

	if (options == 1) {
		cout << "У какого массива вы хотите посчитать самый большой элемент:" << endl
			<< "1) Одномерный массив" << endl
			<< "2) Двухмерный массив" << endl
			<< "3) Трехмерный массив" << endl;
		cin >> options;

		if (options == 1) {
			const int size = 5;
			int arr[size];
			maximum_element(arr, size);
		}
		else if (options == 2) {
			const int size = 5;
			int arr[size][5];  // Исправлено: должно быть [5], а не [4]
			maximum_element(arr, size);  // Исправлено: передаем массив, а не элемент
		}
		else if (options == 3) {
			const int size = 5;
			int arr[size][5][5];  // Исправлено: должно быть [5][5], а не [4][4]
			maximum_element(arr, size);  // Исправлено
		}
	}
	else if (options == 2) {
		cout << "Хотите посмотреть из скольки цифр самое большое: " << endl
			<< "1) из двух цифр" << endl
			<< "2) Из трех цифр" << endl;
		cin >> options;

		if (options == 1) {
			int a, b;
			cout << "Введите первое число: "; cin >> a;
			cout << "Введите второе число: "; cin >> b;
			maximum_element(a, b);
		}
		else if (options == 2) {
			int a, b, c;
			cout << "Введите первое число: "; cin >> a;
			cout << "Введите второе число: "; cin >> b;
			cout << "Введите третье число: "; cin >> c;
			maximum_element(a, b, c);
		}
	}
	else {
		cout << "Вы ввели не то действие, пожалуйста перезагрузите программу, и правильно введите ваши действия ";
	}

	return 0;
}