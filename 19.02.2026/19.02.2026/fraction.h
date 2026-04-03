#pragma once

#include "include.h"
class Fraction
{
private:
	double numerator, denominator;
	static int count;
public:
	//Конструкторы
	Fraction() : numerator(0), denominator(0){}
	Fraction(double num, double den) : numerator(num), denominator(den) {}

	//Геторы и сеторы 
	void setNumerator(double num) {
		this->numerator = num;
	}
	void setDenominator(double den) {
		this->denominator = den;
	}

	double getNumerator() {
		return numerator;
	}
	double getDenominator() {
		return denominator;
	}
	// методы 

	void display();
	static int getCount() {
		return count;
	}

};

