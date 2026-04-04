#define _CRT_SECURE_NO_WARNINGS

#include "Processor.h"

Processor::Processor(const string& m, double freq, int c)
    : model(m), frequency(freq), cores(c) {
    cout << "[Процессор] Создан: " << model << " (" << frequency << " ГГц, " << cores << " ядра)" << endl;
}

Processor::Processor(const Processor& other)
    : model(other.model), frequency(other.frequency), cores(other.cores) {
    cout << "[Процессор] Создана копия: " << model << endl;
}

Processor::~Processor() {
    cout << "[Процессор] Уничтожен: " << model << endl;
}

string Processor::getModel() const { return model; }
double Processor::getFrequency() const { return frequency; }
int Processor::getCores() const { return cores; }

void Processor::setModel(const string& m) { model = m; }
void Processor::setFrequency(double freq) { frequency = freq; }
void Processor::setCores(int c) { cores = c; }

void Processor::print() const {
    cout << "Процессор: " << model << ", " << frequency << " ГГц, " << cores << " ядер" << endl;
}

Processor& Processor::operator=(const Processor& other) {
    if (this != &other) {
        model = other.model;
        frequency = other.frequency;
        cores = other.cores;
    }
    return *this;
}