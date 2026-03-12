#pragma once
class Point
{
private:
	int x, y, z;
public:
	//Конструктор по умолчанию
	Point() :x(0), y(0), z(0) {}

	// геторы
	int getX() { return x; }
	int getY() { return y; }
	int getZ() { return z; }

	//сеторы

	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }
	void setZ(int z) { this->z = z; }

	//Запись текста в файл 

	void recording_text();

	//Вывод текста из файла

	void text_output();
};

