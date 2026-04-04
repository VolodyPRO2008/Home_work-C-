#ifndef COMPUTER_H
#define COMPUTER_H

#include <iostream>
#include <string>
#include "Processor.h"

using namespace std;

class Computer {
private:
    string brand;
    Processor* processor;  // Композиция: Computer управляет временем жизни Processor
    int ram;               // ОЗУ в ГБ
    int storage;           // SSD в ГБ

public:
    Computer(const string& br = "Unknown", const string& procModel = "Unknown",
        double freq = 0.0, int cores = 0, int ramSize = 0, int storageSize = 0);
    Computer(const Computer& other);
    ~Computer();

    string getBrand() const;
    Processor* getProcessor() const;
    int getRam() const;
    int getStorage() const;

    void setBrand(const string& br);
    void setRam(int ramSize);
    void setStorage(int storageSize);

    void print() const;

    Computer& operator=(const Computer& other);
};

#endif