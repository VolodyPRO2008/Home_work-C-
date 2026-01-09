#include <iostream>
#include <time.h>

using namespace std;
int main()
{
	setlocale(LC_ALL, "RU");
	srand(time(NULL));

	//Задание 1

	int arr[10],a = 0;

	for (int i = 0; i < 10; i++) {
		arr[i] = rand() % 10 + 1;
		a += arr[i];
		cout << arr[i] << " ";
	}
	cout << endl << "Среденее Арифметическое значение: " << a / 10 << endl;

	//Задание 2

	char ABC[15];
	int b = 0,c = 0, d = 0, e = 0;

	for (int i = 0; i < 15; i++) {
		b = rand() % 30 + 1;
		if (b <= 10) {
			ABC[i] = 'A';
			c++;
		}
		else if (b > 10 && b <= 20) {
			ABC[i] = 'B';
			d++;
		}
		else {
			ABC[i] = 'C';
			e++;
		}
	}
	cout << "A: " << c << endl;
	cout << "B: " << d << endl;
	cout << "C: " << e << endl << endl;

	//Задание 3

	double array[20], s = 0;

	// Заполняем массив случайными числами от -1 до 1
	for (int i = 0; i < 20; i++) {
		array[i] = -1.0 + 2.0 * (rand() / (double)RAND_MAX);
		cout << array[i] << " ";
	}

	cout << endl << endl;

	// Сортировка по убыванию (пузырьковая)
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19 - i; j++) {
			if (array[j] < array[j + 1]) {  // Меняем знак на < для сортировки по убыванию
				s = array[j];
				array[j] = array[j + 1];
				array[j + 1] = s;
			}
		}
	}

	// Выводим отсортированный массив
	cout << "Массив по убыванию: " << endl;
	for (int i = 0; i < 20; i++) {
		cout << array[i] << " ";
	}
	//Задание 4


	int arrz[20];

	int removeValue = 0;
	int newSize = 0;


	for (int i = 0; i < 20; i++) {
		arrz[i] = rand() % 50 + 1;;
		cout << arrz[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < 20; i++) {

		if (arrz[i] % 2 != 0) {
			removeValue = arrz[i];
		}

		if (arrz[i] != removeValue) {
			arrz[newSize++] = arrz[i];
		}
	}

	for (int i = 0; i < newSize; i++) {
		std::cout << arrz[i] << " ";
	}
	cout << endl;
	//Задание 5

	char arrs[10]{ 'k', 'a', 'y', 'a', 'k', 'l', 'a', 'y', 'a', 'k' };
	int asciiCode, k = 10;
	int arrg[10];
	bool bukvs_rovns= true;
	for (int i = 0; i < 10; i++) {
		asciiCode = arrs[i];
		arrg[i] = asciiCode;
	}

	for (int i = 0; i < 10; i ++) {
		if (i != 5 && k != 5) {
			if (arrg[i] == arrg[k - 1]) {
				k--;
			}
			else {
				bukvs_rovns = false;
				break;
			}
		}
		else{
			break;
		}
		
	}
	if (bukvs_rovns == true) {
		cout << "это слово палиндром" << endl;
	}
	else {
		cout << "это слово не палиндром" << endl;
	}



	//Многомерные массивы
	//Задание 1 
	int mass_array[5][5], v = 0;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5;j++) {
			mass_array[i][j] = rand() % 10 + 1;
		}
	}
	for (int i = 0; i < 5; i++) {
		cout << mass_array[i][v] << endl;
		for (int j = 0; j <= v; j++) {
			cout << " ";
		}
		v++;
	}

	cout << endl;

	//Задание 2


	int mass_arr[4][4],h = 0;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			mass_arr[i][j] = rand() % 100 + 0;
			cout << mass_arr[i][j] << " ";
		}
		cout << endl; 
	}


	for (int i = 0; i < 4; i++) {
		for (int j = 0; j <= 4; j++) {
			h += mass_arr[i][j];
		}
		break;
	}
	cout << endl << "Сумма элементов первой строки: " << h << endl; 


	//Задание 3



	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			cout << i + j << " ";
		}
		cout << endl;
	}
	cout << endl;


	//Задание 4

	const int SIZE = 6;
	int matrix[SIZE][SIZE];

	// Создаем симметричную матрицу
	for (int i = 0; i < SIZE; i++) {
		for (int j = i; j < SIZE; j++) {
			// Генерируем случайное число от 1 до 20
			int randomNum = rand() % 20 + 1;

			// Заполняем симметрично относительно главной диагонали
			matrix[i][j] = randomNum;   // Выше диагонали
			matrix[j][i] = randomNum;   // Ниже диагонали
		}
	}

	// Выводим матрицу
	cout << "Симметричная матрица 6x6:" << endl;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cout << matrix[i][j] << "\t";
		}
		cout << endl;

	//Задание 5

	int mass_arr_two[3][3], q = 0;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			mass_arr_two[i][j] = rand() % 20 + 1;
			cout << mass_arr_two[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (q < mass_arr_two[i][j]) {
				q = mass_arr_two[i][j];
			}
		}
	}
	cout << "максимальный элемент в матрице " << q << endl;

}

