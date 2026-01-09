#include <iostream>
using namespace std;

//Задание 1
int degree(int degree_bases, int exponent) {
    int a = 1;
    for (int i = 0; i < exponent;i++) {
        a *= degree_bases;
    }
    return a;
}

//Задание 2

int range(int number_one, int number_two) {
    for (int i = number_one; i <= number_two; i++) {
        number_one += i + 1;
    }
    return number_one;
}




int main()
{
    cout << degree(5,3);

    cout << endl;

    cout << range(4, 8);

    cout << endl; 


}

