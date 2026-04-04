#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <iostream>
#include <string>

using namespace std;

class Processor {
private:
    string model;
    double frequency;  // ГГц
    int cores;

public:
    Processor(const string& m = "Unknown", double freq = 0.0, int c = 0);
    Processor(const Processor& other);
    ~Processor();

    string getModel() const;
    double getFrequency() const;
    int getCores() const;

    void setModel(const string& m);
    void setFrequency(double freq);
    void setCores(int c);

    void print() const;

    Processor& operator=(const Processor& other);
};

#endif