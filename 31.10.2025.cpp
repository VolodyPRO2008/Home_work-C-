#include <iostream>
using namespace std;



//функция создания массива
void creating_an_array(const int size, int arr[]) {
    int fotot;
    for (int i = 0; i < size; i++) {
        cout << "Введите " << i + 1 << " элемент : "; cin >> fotot;
        arr[i] = fotot;
    }
 }
int clojenia_el(int arr[], int sum, int negative_numbers, int l) {
    for (int i = 0; i < 10; i++) {

        sum += arr[i];

        if (arr[i] < negative_numbers) {
            l += 1;
        }
    }
    return sum,l;
}

int main()
{
    setlocale(LC_ALL, "Ru");
    //задание 1
    cout << endl << "Задание 1" << endl;

    const int size = 10;
    double arr[size] = { -5.7, 6.0, 2, 0, -4.7, 6, 8.1, -4, 0 };
    double positive = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > 0)
        {
            positive = arr[i];
        }
    }
    double negative = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < 0)
        {
            negative = arr[i];
            break;
        }
    }
    cout << "Last positive number: " << positive <<
        endl;
    cout << "First negatine number:" << negative <<
        endl;


    //Задание 2

    cout << endl << "Задание 2" << endl;

        // 4 подъезда, каждый по 10 квартир (5 этажей × 2 квартиры)
    int p1[10] = { 2, 3, 4, 2, 3, 1, 5, 2, 4, 3 };  // 1-й подъезд
    int p2[10] = { 6, 2, 3, 4, 1, 2, 5, 3, 2, 4 };  // 2-й подъезд
    int p3[10] = { 7, 3, 2, 1, 4, 5, 6, 2, 3, 4 };  // 3-й подъезд
    int p4[10] = { 2, 3, 5, 4, 6, 2, 3, 1, 4, 2 };  // 4-й подъезд

    // а) Поиск квартиры
    int n;
    cout << "Квартира (1-40): ";
    cin >> n;

    if (n > 0 && n <= 40) {
        // Определяем подъезд и индекс в массиве подъезда
        int pod = (n - 1) / 10;      // 0-3
        int idx = (n - 1) % 10;      // 0-9

        // Получаем значение из нужного массива
        int residents;
        if (pod == 0) residents = p1[idx];
        else if (pod == 1) residents = p2[idx];
        else if (pod == 2) residents = p3[idx];
        else residents = p4[idx];

        cout << "Кв." << n << ": " << residents << " чел." << endl;

        // Сосед на этаже
        int floor = idx / 2;          // этаж в подъезде (0-4)
        int apt1 = floor * 2;         // индекс первой квартиры на этаже
        int apt2 = apt1 + 1;          // индекс второй квартиры на этаже

        // Находим соседа
        int neighbor_idx, neighbor_res;
        if (idx == apt1) {
            neighbor_idx = apt2;
        }
        else {
            neighbor_idx = apt1;
        }

        // Получаем значение соседа
        if (pod == 0) neighbor_res = p1[neighbor_idx];
        else if (pod == 1) neighbor_res = p2[neighbor_idx];
        else if (pod == 2) neighbor_res = p3[neighbor_idx];
        else neighbor_res = p4[neighbor_idx];

        // Номер соседней квартиры в общем счете
        int neighbor_num = pod * 10 + neighbor_idx + 1;
        cout << "Сосед: кв." << neighbor_num << " (" << neighbor_res << " чел.)" << endl;
    }

    // б) Сумма по подъездам
    cout << endl << "Жильцы по подъездам:" << endl;

    // Для p1
    int s1 = 0;
    for (int i = 0; i < 10; i++) s1 += p1[i];
    cout << "П1: " << s1 << endl;

    // Для p2
    int s2 = 0;
    for (int i = 0; i < 10; i++) s2 += p2[i];
    cout << "П2: " << s2 << endl;

    // Для p3
    int s3 = 0;
    for (int i = 0; i < 10; i++) s3 += p3[i];
    cout << "П3: " << s3 << endl;

    // Для p4
    int s4 = 0;
    for (int i = 0; i < 10; i++) s4 += p4[i];
    cout << "П4: " << s4 << endl;

    // в) Многодетные семьи
    cout << endl << "Многодетные (>5 чел.):" << endl;
    bool found = false;

    // Проверяем 1-й подъезд
    for (int i = 0; i < 10; i++) {
        if (p1[i] > 5) {
            cout << "Кв." << (i + 1) << " (" << p1[i] << ")" << endl;
            found = true;
        }
    }

    // Проверяем 2-й подъезд
    for (int i = 0; i < 10; i++) {
        if (p2[i] > 5) {
            cout << "Кв." << (10 + i + 1) << " (" << p2[i] << ")" << endl;
            found = true;
        }
    }

    // Проверяем 3-й подъезд
    for (int i = 0; i < 10; i++) {
        if (p3[i] > 5) {
            cout << "Кв." << (20 + i + 1) << " (" << p3[i] << ")" << endl;
            found = true;
        }
    }

    // Проверяем 4-й подъезд
    for (int i = 0; i < 10; i++) {
        if (p4[i] > 5) {
            cout << "Кв." << (30 + i + 1) << " (" << p4[i] << ")" << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Нет многодетных семей" << endl;
    }


    //Задание 3

    cout << endl << "Задание 3" << endl;

    int first_10_days[size] = {-5,-3,1,-3,-2,-15,-22,-10,-33};
    int second_10_days[size] = { -18,-8,-6,-19,-28,-25,-3,-3,-13,-10 };
    int third_10_days[size] = { -40,20,-17,-28,-20,-26,-30,-24,-22,-7 };
    int last_day[size] = {-3};
    int mark_temperature,d = 0,k = 0, l = 0;

    cout << "Введите отметку температуры, чтобы посчитать у скольки дней будет ниже температур, чем отметка: "; cout << "(Можно написать и с отрицательной температурой)"; cin >> mark_temperature;


    creating_an_array(size, first_10_days);
    creating_an_array(size, second_10_days);
    creating_an_array(size, third_10_days);
    cout << "Введите 31 элемент массива: "; cin >> k;
    last_day[0] = k;
    d, l = clojenia_el(first_10_days, d, mark_temperature , l);
    d, l = clojenia_el(second_10_days, d, mark_temperature, l);
    d, l = clojenia_el(third_10_days, d, mark_temperature, l);
    d, l = clojenia_el(last_day, d, mark_temperature, l);
    cout << d << " ";
    d /= 31;
    cout << "Средее значение температуры за месяц " << d << endl << " количество чисел меньше отметки" << l;
     
        





    //Задание 4
    cout << endl << "Задание 4" << endl;

    const int number_of_cars = 10;
    int car[number_of_cars], b = 0, a = 0, c = 0;

    cout << "Введите сумму 10 автомобилей" << endl;


    //смотрим какая цена самая большая из всех машин
    creating_an_array(number_of_cars, car);
    b = car[0];

    for (int i = 0; i < number_of_cars; i++) {

        if (b < car[i + 1])
            b = car[i + 1];

    }
    cout << "Самая большая цена: " << b << endl;

    //Сравниваем ее с другими машинами, если находим то выводим первый и последний элемент

    for (int i = 0; i < number_of_cars; i++) {
        if (b == car[i]) {
            a = i;
            break;
        }
    }
    for (int i = 0; i < number_of_cars; i++) {
        if (b == car[i]) {
            c = i;


        }
    }
    if (a != c) {
        cout << "Цена " << a + 1 << " машины, совпадает с ценной " << c + 1 << " машины" << endl;
    }

    //Задание 5
    cout << endl << "Задание 5" << endl;

    const int const_number = 10;
    int ramem[const_number], h, g,сomparison_array[10], v = 1;




    creating_an_array(const_number, ramem);


    cout << "Эти цифры повторяются в массиве:";

    for (int i = 0; i < const_number; i++) {
        bool el_arr = false;// не допускает повторения вывода одного и того же числа
        g = 0;// количество встреченых одних и тех же чисел
        h = ramem[i];
        for (int j = 0; j < const_number; j++) {
            if (h == ramem[j]) {
                g++;
                if (g >= 2) {
                    for (int el = 0; el < v; el++) {
                        //проверка на повтор числа в массиве 
                        if (h == сomparison_array[el]) {
                            el_arr = true;
                            break;
                        }
                    }
                    if (el_arr == false) {
                        сomparison_array[v - 1] = h;
                        cout << " " << сomparison_array[v - 1];
                        v++;
                        break;

                    }
                }
            }

        }

    //}

    //Задание 6

    cout << endl << "Задание 6" << endl;

    int A[const_number] = {1,1,1,1,1,1,1,1,1,1};
    int B[const_number] = {2,2,2,2,2,2,2,2,2,2};
    int X[const_number + 10];


    creating_an_array(const_number, A);
    creating_an_array(const_number, B);

    //чередования
    for (int i = 0; i < const_number; i = i+2) {
        X[i] = A[i];
        X[i + 1] = B[i];
    }
    for (int i = 0; i < const_number; i++) {
        cout << X[i] << " ";
    }
    cout << endl;
    //следования 
    for (int i = 0; i < const_number; i++) {
        X[i] = A[i];
    }
    for (int i = 10; i < const_number + 10; i++) {
         X[i]= B[i - 10];
    }
    for (int i = 0; i < const_number + 10; i++) {
        cout << X[i] << " ";
    }









    return 0;
}

