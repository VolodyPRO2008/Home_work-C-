#include "Point.h"
#include "include.h"


void Point::recording_text() {
	ofstream outFlie("Point.txt");
	if (outFlie.is_open()) {
		outFlie << "Координата по x: " << x << endl;
		outFlie << "Координата по y: " << y << endl;
		outFlie << "Координата по z: " << z << endl;
		outFlie.close();
	}
}

void Point::text_output() {
	ifstream inFile("Point.txt");
	string line;
	if (inFile.is_open()) {
		while (getline(inFile, line)) {
			cout << line << endl;
		}
		inFile.close();
	}
}