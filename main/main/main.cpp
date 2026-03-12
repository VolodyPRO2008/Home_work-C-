#include "include.h"
#include "Point.h"

int main()
{
    setlocale(0, "");

    int x, y, z;

    cout << "Введите координаты x: "; cin >> x;  
    cout << "Введите координаты y: "; cin >> y;
    cout << "Введите координаты z: "; cin >> z;

    Point d2;
    d2.setX(x);
    d2.setY(y);
    d2.setZ(z);
    cout << "Координаты сохранины в файл: Point.txt" << endl << endl;

    d2.recording_text();

    d2.text_output();
}

