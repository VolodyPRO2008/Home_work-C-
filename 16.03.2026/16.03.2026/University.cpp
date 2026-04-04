#define _CRT_SECURE_NO_WARNINGS

#include "University.h"

University::University(const string& n) : name(n) {
    cout << "[Университет] Создан: " << name << endl;
}

University::University(const University& other) : name(other.name) {
    // Агрегация: копируем только указатели, а не сами объекты
    for (Student* s : other.students) {
        students.push_back(s);
    }
    cout << "[Университет] Создана копия: " << name << endl;
}

University::~University() {
    cout << "[Университет] Уничтожен: " << name << endl;
    // Агрегация: НЕ удаляем студентов, так как не управляем их временем жизни
    students.clear();
}

void University::enrollStudent(Student* student) {
    if (student != nullptr) {
        students.push_back(student);
        cout << "[Университет] Зачислен студент: " << student->getName() << " в " << name << endl;
    }
}

void University::expelStudent(int studentId) {
    for (auto it = students.begin(); it != students.end(); ++it) {
        if ((*it)->getId() == studentId) {
            cout << "[Университет] Отчислен студент: " << (*it)->getName() << " из " << name << endl;
            students.erase(it);
            return;
        }
    }
    cout << "Студент с ID " << studentId << " не найден" << endl;
}

Student* University::getStudent(int index) {
    if (index >= 0 && index < (int)students.size()) {
        return students[index];
    }
    return nullptr;
}

int University::getStudentCount() const {
    return students.size();
}

void University::print() const {
    cout << "\n=== УНИВЕРСИТЕТ: " << name << " ===" << endl;
    cout << "Количество студентов: " << students.size() << endl;
    for (size_t i = 0; i < students.size(); i++) {
        cout << "  " << i + 1 << ". ";
        students[i]->print();
    }
}

University& University::operator=(const University& other) {
    if (this != &other) {
        name = other.name;
        students.clear();
        for (Student* s : other.students) {
            students.push_back(s);
        }
    }
    return *this;
}