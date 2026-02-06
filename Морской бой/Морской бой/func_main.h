#pragma once

#include <iostream>
#include <string>
using namespace std;


enum Letters {
	A = 1, B = 2, C = 3, D = 4, E = 5,F = 6
};


//Функция победы игрока
bool victory_player(int* arr_shots_player /*массив выстрелов игрока*/, int* arr_ships_computer /*массив короблей компьютера*/, int size /*размер массива выстрелов играка*/) { 
	int wrecked_ships = 0;
	for (int i = 0; i < size + 1; i++) {
		for (int j = 0; j < 3; j++) {
			if (arr_shots_player[i] == arr_ships_computer[j]) {
				wrecked_ships++;
				break;
			}
		}
	}
	if (wrecked_ships == 3) {
		return true;
	}
	else {
		return false;
	}
}


//Функция победы компьютера
bool victory_computer(int* arr_shots_computer /*массив выстрелов компьютера*/, string* arr_ships_player /*массив короблей игрока*/,  int size /*размер массива выстрелов компьютера*/) {
	int wrecked_ships = 0;
	for (int i = 0; i < size + 1; i++) {
		for (int j = 0; j < 3; j++) {
			int ships_player = stoi(arr_ships_player[j]);
			if (arr_shots_computer[i] == ships_player) {
				wrecked_ships++;
				break;
			}
		}
	}
	if (wrecked_ships == 3) {
		return true;
	}
	else {
		return false;
	}
}




//Функция создание кароблей по координатам пользователя
void ship_coordinates_player(string* arr /*этот массив где будут храниться все координаты*/) {
	bool creat_ships = false; /*проверка сделано ли 3 корабля*/
	bool correct_coordinate = false;/*проверка сделано корабли правельно*/
	int number_ships = 0; /*счетчик короблей*/
	for (; creat_ships == false;) {
		correct_coordinate = false;
		for (; correct_coordinate == false;) {
			string coordinates;
			cout << "Введите координаты " << number_ships + 1 << " корабля от A1 до F6 (Пример A1): ";
			cin >> coordinates;
			cout << int(coordinates[0]) << int(coordinates[1]);
			if ((int(coordinates[0]) > 64 && int(coordinates[0]) < 71) && (int(coordinates[1]) > 48) && (int(coordinates[1]) < 55)) {
				correct_coordinate = true;
			}
			else {
				cout << "Корабь создать невозможно " << endl;
			}
			if (correct_coordinate == true && number_ships < 2) {
				cout << "Корабль создан " << endl;
				arr[number_ships] = coordinates;
				number_ships++;
			}
			else if (correct_coordinate == true && number_ships == 2) {
				cout << "Корабль создан " << endl;
				arr[number_ships] = coordinates;
				creat_ships = true;
				break;
			}
		}
	}

}

//Функция меняет первую букву координат игрока в цифру в слове
void letter_conversion(string* arr) {
	for (int i = 0; i < 3; i++) {
		string j = arr[i];
		switch (j[0]) {
		case 'A': 
			j[0] = char(A + '0');
			arr[i] = j;
			break;
		case 'B':
			j[0] = char(B + '0');
			arr[i] = j;
			break;
		case 'C':
			j[0] = char(C + '0');
			arr[i] = j;
			break;
		case 'D':
			j[0] = char(D + '0');
			arr[i] = j;
			break;
		case 'E':
			j[0] = char(E + '0');
			arr[i] = j;
			break;
		case 'F':
			j[0] = char(F + '0');
			arr[i] = j;
			break;
		}
	}
}



//Функция меняет первую букву координат игрока в цифру в массиве
string letter_conversion(string arr) {
	char j = arr[0];
	switch (j) {
	case 'A':
		j = char(A + '0');
		arr[0] = j;
		return arr;

	case 'B':
		j = char(B + '0');
		arr[0] = j;
		return arr;

	case 'C':
		j = char(C + '0');
		arr[0] = j;
		return arr;

	case 'D':
		j = char(D + '0');
		arr[0] = j;
		return arr;

	case 'E':
		j = char(E + '0');
		arr[0] = j;
		return arr;

	case 'F':
		j = char(F + '0');
		arr[0] = j;
		return arr;

	}
}




//пузерьковая сортировка для строк
void bubble_sort(string* arr) {
	// 1. Преобразуем все строки в int
	int intArr[3];
	for (int i = 0; i < 3; i++) {
		intArr[i] = stoi(arr[i]);
	}

	// 2. Сортируем массив int пузырьком
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2 - i; j++) {
			if (intArr[j] > intArr[j + 1]) {
				// Меняем местами int
				int temp = intArr[j];
				intArr[j] = intArr[j + 1];
				intArr[j + 1] = temp;
			}
		}
	}

	// 3. Преобразуем отсортированные int обратно в string
	for (int i = 0; i < 3; i++) {
		arr[i] = to_string(intArr[i]);
	}
}

//пузерьковая сортировка для цифр
void bubble_sort(int* arr, int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}






//Функция ввывода карты игрока
void print_map_player(string* array_ships /*массив координат кароблей*/, int* array_shots_computer/*массив координат выстрелов*/, int size_shors_copmuter /*размер массив с координатами выстрелов*/) {
	letter_conversion(array_ships);
	bubble_sort(array_ships);
	int number_of_ships = 0; //количество корблей созданных
	bool shot_comp = false; // является ли сейчас точка куда выстрельнул компьютер


	cout << endl << "   1 2 3 4 5 6" << endl;
	cout << "   = = = = = =" << endl;
	for (int i = 0; i < 6; i++) {
		cout << "|" << char(65 + i) << "|";
		for (int j = 0; j < 6; j++) {
			string first_coordinates_ship_player = array_ships[number_of_ships]; //Берем число из массива
			int first_coordinates_ship_player_int = first_coordinates_ship_player[0] - '0'; // Берем первую цифру из числа

			string second_coordinates_ship_player = array_ships[number_of_ships];//Берем число из массива
			int second_coordinates_ship_player_int = second_coordinates_ship_player[1] - '0';//Берем вторую цифру из числа(и да дальше будет способ получше чем это, я это просто писал в первый день, поэтому лучше ничего не прид)
			for (int el = 0; el < size_shors_copmuter + 1;el++) { //колчество выстрелов которые были
				int first_coordinates_shot_coputer = array_shots_computer[el] / 10; //Берем первую цифру от числа которое в массиве выстрелов
				int second_coordinates_shot_coputer = array_shots_computer[el] % 10;//Берем второую цифру от числа которое в массиве выстрелов
				if ((first_coordinates_shot_coputer == i + 1) && (second_coordinates_shot_coputer == j + 1)) { // i и j являются точками по которым был выстрел 
					shot_comp = true;
					break;
				}
			}
			if (((first_coordinates_ship_player_int == i + 1) && (second_coordinates_ship_player_int == j + 1)) && shot_comp == true) { // если координаты расположение каробля и выстрела совподают, то # будет красным
				cout << "\033[90m#\033[0m" << " ";
				if (number_of_ships < 2) {
					number_of_ships++;
					if (j == 5) {
						cout << "|";
					}
				}
				shot_comp = false;
			}
 			else if (((first_coordinates_ship_player_int == i + 1) && (second_coordinates_ship_player_int == j + 1)) && shot_comp != true) {// обычное выведение каробля, когда по ниму не попали 
				cout << "\033[32m#\033[0m" << " ";
				if (number_of_ships < 2) {
					number_of_ships++;
					if (j == 5) {
						cout << "|";
					}
				}
			}
			else if (((first_coordinates_ship_player_int != i + 1) || (second_coordinates_ship_player_int != j + 1)) && shot_comp == true) {// когда по кароблю не попали, но выстрел был
				cout << "\033[34m*\033[0m" << " ";
				if (j == 5) {
					cout << "|";
				}
				shot_comp = false;

			}
			else { // вывод когда нету ни выстрела по этой координате, ни каробля
				cout << "*" << " ";
				if (j == 5) {
					cout << "|";
				}
			}
		}
		cout << endl;
	}
	cout << "   = = = = = =" << endl;
}

//Функция ввывода карты игрока
void print_map_computer(int* coordinates_ships /*массив координат кароблей*/, int* coordinates_shots_player /*массив координат выстрелов*/, int size_max_array_shots/*размер массив с координатами выстрелов*/) {

	bool shots_ships = false; // был ли выстрел по этой точке
	int size = 0;

	cout << endl << "   1 2 3 4 5 6" << endl;
	cout << "   = = = = = =" << endl;
	for (int i = 0; i < 6; i++) {
		cout << "|" << char(65 + i) << "|";
		for (int j = 0; j < 6; j++) {
			shots_ships = false;
			for (size; size < size_max_array_shots;) {
				int first_coordinates_shots = coordinates_shots_player[size] / 10; // первая координата точки выстрела 
				int second_coordinates_shots = coordinates_shots_player[size] % 10; // вторая координата точки выстрела 
				if (first_coordinates_shots == i + 1 && second_coordinates_shots == j + 1) {
					if (shots_ships == true) {
						size++;
						break;
					}
					for (int el = 0; el < 3; el++) {
						int first_coordinates_ships = coordinates_ships[el] / 10; // массив кароблей первая точка
						int second_coordinates_ships = coordinates_ships[el] % 10;// массив кароблей вторая точка
						if (first_coordinates_ships == i + 1 && second_coordinates_ships == j + 1) { // если это также самая точка где был выстрел
							cout << "\033[31m#\033[0m" << " ";
							if (j == 5) {
								cout << "|";
							}
							shots_ships = true;
							break;
						}
					}
					if (shots_ships == false) { // не попал по кароблю
						cout << "\033[34m*\033[0m" << " ";
						if (j == 5) {
							cout << "|";
						}
						shots_ships = true;
					}
				}
				else { // если в эту точку не попали 
					cout << "*" << " ";
					if (j == 5) {
						cout << "|";
					}
					break;
				}
			}
			if (size_max_array_shots == 0) { // для вывода с поля вначале
				cout << "*" << " ";
				if (j == 5) {
					cout << "|";
				}
			}
			else if (size == size_max_array_shots && shots_ships == false) { // когда не осталось больше короблей
				cout << "*" << " ";
				if (j == 5) {
					cout << "|";
				}
			}
		}
		cout << endl;
	}
	cout << "   = = = = = =" << endl;
}






//генерация кароблей у компьютер
void computer_melts_the_ships(int* arr_ships /*массив кароблей, который будем заполнять*/) {
	int ship_coordinates; // координата каробля
	
	for (int i = 0; i < 3;) {
		bool cord_on = false; // есть ли такая координата
		string y_coordinates = to_string(1 + rand() % 6);
		string x_coordinates = to_string(1 + rand() % 6);
		ship_coordinates = stoi(y_coordinates + x_coordinates); //записываем координату каробля в переменную
		for (int j = 0; j < 3 ; j++) {
			if (arr_ships[j] == ship_coordinates) {
				cord_on = true;
				break;
			}
		}
		if (cord_on == false) { // если повторяющихся нет, добовляем в массив
			
			arr_ships[i] = ship_coordinates;
			i++;
		}

	}
	bubble_sort(arr_ships,2); // сразу сортируем, чтобы в будущем легче было выводить координаты на поле компьютера 
}


// генератор случайных выстрелов компьютеров
void computer_shots(int* array_shots_computer/*массив выстрелов*/, int size_max_array_shots/*размер массива*/) {
	int shot_coordinates;
	for (int i = 0; i < 100; i++) { // не может быть так чтобы больше 100 раз вызывалас данный цикал (просто так от болды написал, а так вызываться может максимум 36 раз)
		bool cord_on = false;
		string y_coordinates = to_string(1 + rand() % 6);
		string x_coordinates = to_string(1 + rand() % 6);
		shot_coordinates = stoi(y_coordinates + x_coordinates);
		for (int j = 0; j < size_max_array_shots + 1; j++) {
			if (array_shots_computer[j] == shot_coordinates) {
				cord_on = true;
				break;
			}
		}
		if (cord_on == false) {
			break;
		}
	}
	// тут такой же принцеп как и сверху
	array_shots_computer[size_max_array_shots] = shot_coordinates;
	cout << "Компьютер стрельнул по координатам: " << char(64+(shot_coordinates/10)) << shot_coordinates % 10; // вывод куда стрелял компьютер
}

// выстрелы игрока
void playrs_shots(int* shots_player /*массив выстрелов игрока*/, int size_max_array_shots /*размер массива выстрелов игрока*/) {
	int shot_coordinates;
	bool corect_shot = false;

	for (; corect_shot == false;) { // каждый раз выводим один раз цикл (вообще можно было без него, но я тестировал отоброжение на поле компьютера и мне уже влом что-либо делать, я пишу этот текст сейчас 1:00, а я начинал в 14)
		string coordinates;
		cout << "Введите координаты " << size_max_array_shots + 1 << " выстрела от A1 до F6 (Пример A1): ";
		cin >> coordinates;
		if ((int(coordinates[0]) > 64 && int(coordinates[0]) < 71) && (int(coordinates[1]) > 48) && (int(coordinates[1]) < 55)) { // проверка на правильность набора координат
			coordinates = letter_conversion(coordinates); // переделка первой координаты в число
			shot_coordinates = stoi(coordinates);// (так как у нас выше был string,но который можно переделать в int, тут я его и переделываю)
			shots_player[size_max_array_shots] = shot_coordinates; // ну тут я помещаю его в массив
			corect_shot = true;
		}
		else {
			cout << "Не правильно задоное значение " << endl;
		}
	}
	if (size_max_array_shots >= 1){ // если будет один элемент то его бесмысленно сортировать
		bubble_sort(shots_player,size_max_array_shots + 1);
	}
	
}







