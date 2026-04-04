#define _CRT_SECURE_NO_WARNINGS

#include "Computer.h"

Computer::Computer(const string& br, const string& procModel, double freq, int cores, int ramSize, int storageSize)
    : brand(br), ram(ramSize), storage(storageSize) {
    // Композиция: Computer создаёт Processor
    processor = new Processor(procModel, freq, cores);
    cout << "[Компьютер] Создан компьютер: " << brand << " (ОЗУ: " << ram << " ГБ, SSD: " << storage << " ГБ)" << endl;
}

// Конструктор копирования - глубокое копирование (композиция)
Computer::Computer(const Computer& other)
    : brand(other.brand), ram(other.ram), storage(other.storage) {
    processor = new Processor(*other.processor);
    cout << "[Компьютер] Создана копия компьютера: " << brand << endl;
}

Computer::~Computer() {
    cout << "[Компьютер] Уничтожается компьютер: " << brand << endl;
    // Композиция: Computer удаляет Processor
    delete processor;
}

string Computer::getBrand() const { return brand; }
Processor* Computer::getProcessor() const { return processor; }
int Computer::getRam() const { return ram; }
int Computer::getStorage() const { return storage; }

void Computer::setBrand(const string& br) { brand = br; }
void Computer::setRam(int ramSize) { ram = ramSize; }
void Computer::setStorage(int storageSize) { storage = storageSize; }

void Computer::print() const {
    cout << "\n=== КОМПЬЮТЕР ===" << endl;
    cout << "Бренд: " << brand << endl;
    processor->print();
    cout << "ОЗУ: " << ram << " ГБ" << endl;
    cout << "SSD: " << storage << " ГБ" << endl;
}

Computer& Computer::operator=(const Computer& other) {
    if (this != &other) {
        brand = other.brand;
        ram = other.ram;
        storage = other.storage;

        delete processor;
        processor = new Processor(*other.processor);
    }
    return *this;
}