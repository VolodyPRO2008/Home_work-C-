// дз.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

int main(){
    setlocale(LC_ALL, "ru");
    //Задание 1

    int n;
    int c = 0;
    int a1 = 10;
    int k = 1;
    int sum = 0;
    int choice;
    cout << "Напишите число которое будем размберать" << endl; cin >> n;



   for (; n != 0;) {
       int tit = n % a1 ;
       sum += tit ;
       n /= 10;
       c++;
   }



   cout << "Что вы хотите получить (Посчитать сколько цифр в числе - 1; Посчитать сумму всех цифр в вашем числе - 2; Посчитать среднее арифметическое - 3)" << endl; cin >> choice;

   switch (choice) {
   case 1:
       cout << "В числе " << c << " цифор" << endl;
       break;
   case 2:
       cout << "Сумма всех цифр: " << sum << endl;
       break;
   case 3:
       cout << "Среднее арифметическое: " << sum / c << endl;
       break;
   }


    //Задание 2

    int a;
    int b;
    int c1 = 0;

    cout << "Введите размер доски (x): "; cin >> a; cout << "Введите размер доски (y): "; cin >> b;


    for (int i = 1; i <= a; i++) {
        cout << endl;
        c1++;
        for (int j = 1; j <= b; j ++) {
            if (c1 % 2 == 0) {
                if (j % 2 == 0) {
                    cout << "***";
                }
                else {
                    cout << "---";
                }
            }
            else {
                if (j % 2 == 0) {
                    cout << "---";
                }
                else {
                    cout << "***";
                }
            }

        }   
    }
    cout << endl;
   //Задание 3

    int number_humen;
    int number_zakaz;

    int order_amount = 0;
    int mne_len_chtoto_dumat;
    cout << "Введите соклько человек хочет заказать заказ" << endl; cin >> number_humen;
    cout << "Чтобы указать напиток/кондитерское изделия нужно указать номер заказа:" << endl << "Капучино - 1; Чёрный чай - 2; Тирамису - 3; Эклер ванильный - 4; Маффин шоколадный - 5  " << endl;


        for (int i = 1; i <= number_humen; i++) {
            bool povtor = true;
            for (; povtor == true;) {

                cout << "Выберите заказы для человека под номер  " << i << endl << endl << "Напитки:" << endl << "Капучино — 180 руб ;" << endl << "Чёрный чай — 120 руб; " << endl << endl << "Кондитерские изделия: " << endl << "Тирамису — 220 руб; " << endl << "Эклер ванильный — 150 руб;" << endl << "Маффин шоколадный — 160 руб" << endl; cin >> number_zakaz;

                switch (number_zakaz) {
                case 1:
                    cout << "Капучино добавлен в карзину" << endl;
                    order_amount += 180;
                    cout << "Хотите ли вы еще чего-то заказать для человека под номер " << i << " (да - 0; нет - 1)" << endl; cin >> mne_len_chtoto_dumat;
                    if (mne_len_chtoto_dumat == 0) {
                        break;
                    }
                    else if (mne_len_chtoto_dumat == 1) {
                        povtor = false;
                        break;
                    }
                case 2:
                    cout << "Чёрный чай добавлен в карзину" << endl;
                    order_amount += 120;
                    cout << "Хотите ли вы еще чего-то заказать для человека под номер " << i << " (да - 0; нет - 1)" << endl; cin >> mne_len_chtoto_dumat;
                    if (mne_len_chtoto_dumat == 0) {
                        break;
                    }
                    else if (mne_len_chtoto_dumat == 1) {
                        povtor = false;
                        break;
                    }
                case 3:
                    cout << "Тирамису добавлен в карзину" << endl;
                    order_amount += 220;
                    cout << "Хотите ли вы еще чего-то заказать для человека под номер " << i << " (да - 0; нет - 1)" << endl; cin >> mne_len_chtoto_dumat;
                    if (mne_len_chtoto_dumat == 0) {
                        break;
                    }
                    else if (mne_len_chtoto_dumat == 1) {
                        povtor = false;
                        break;
                    }
                case 4:
                    cout << "Эклер ванильный добавлен в карзину" << endl;
                    order_amount += 150;
                    cout << "Хотите ли вы еще чего-то заказать для человека под номер " << i << " (да - 0; нет - 1)" << endl; cin >> mne_len_chtoto_dumat;
                    if (mne_len_chtoto_dumat == 0) {
                        break;
                    }
                    else if (mne_len_chtoto_dumat == 1) {
                        povtor = false;
                        break;
                    }
                case 5:
                    cout << "Маффин шоколадный добавлен в карзину" << endl;
                    order_amount += 160;
                    cout << "Хотите ли вы еще чего-то заказать для человека под номер " << i << " (да - 0; нет - 1)" << endl; cin >> mne_len_chtoto_dumat;
                    if (mne_len_chtoto_dumat == 0) {
                        break;
                    }
                    else if (mne_len_chtoto_dumat == 1) {
                        povtor = false;
                        break;
                    }
                default:
                    cout << "Такого тавара нету" << endl;
                }

            }
    }
        cout <<  "Вы выбрали заказ на сумму: " << order_amount  << endl << endl;


    //Задание 4

    for (int i = 1; i <= 9; i++ ) {
        cout << "A" << i << " " << "B" << i <<" " << "C" << i << " " << "D" << i << " " << "E" << i << " " << "F" << i << " " << "G" << i << " " << "H" << i << " " << "I" << i << " " << "J" << i << " " << endl;
    }



}

