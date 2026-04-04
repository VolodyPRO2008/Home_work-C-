#define _CRT_SECURE_NO_WARNINGS

#include "Group.h"
#include <fstream>
#include <iomanip>
#include <sstream>

Group::Group(const string& n) : name(n) {
    cout << "Создана группа: " << name << endl;
}

Group::Group(const Group& other)
    : name(other.name), students(other.students),
    subjects(other.subjects), gradeTable(other.gradeTable) {
    cout << "Создана копия группы" << endl;
}

Group::~Group() {
    cout << "Уничтожена группа: " << name << endl;
}

void Group::addStudent(const StudentGrade& student) {
    students.push_back(student);
    // Расширяем таблицу оценок
    for (auto& row : gradeTable) {
        row.push_back(0);
    }
}

void Group::addSubject(const Subject& subject) {
    subjects.push_back(subject);
    // Расширяем таблицу оценок
    if (gradeTable.empty()) {
        gradeTable.resize(students.size());
    }
    for (auto& row : gradeTable) {
        row.push_back(0);
    }
}

void Group::setGrade(int studentIndex, int subjectIndex, int grade) {
    if (studentIndex >= 0 && studentIndex < (int)students.size() &&
        subjectIndex >= 0 && subjectIndex < (int)subjects.size()) {
        gradeTable[studentIndex][subjectIndex] = grade;
        students[studentIndex].addGrade(grade);
    }
}

bool Group::loadStudentsFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Ошибка: не удалось открыть файл " << filename << endl;
        return false;
    }

    string line;
    while (getline(file, line)) {
        if (!line.empty()) {
            students.push_back(StudentGrade(line));
        }
    }

    file.close();
    cout << "Загружено " << students.size() << " студентов из файла " << filename << endl;

    // Инициализация таблицы оценок
    gradeTable.resize(students.size());
    for (auto& row : gradeTable) {
        row.resize(subjects.size(), 0);
    }

    return true;
}

bool Group::loadSubjectsFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Ошибка: не удалось открыть файл " << filename << endl;
        return false;
    }

    string line;
    while (getline(file, line)) {
        if (!line.empty()) {
            subjects.push_back(Subject(line));
        }
    }

    file.close();
    cout << "Загружено " << subjects.size() << " предметов из файла " << filename << endl;

    // Инициализация таблицы оценок
    for (auto& row : gradeTable) {
        row.resize(subjects.size(), 0);
    }

    return true;
}

bool Group::loadGradesFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Ошибка: не удалось открыть файл " << filename << endl;
        return false;
    }

    string line;
    int studentIdx = 0;
    while (getline(file, line) && studentIdx < (int)students.size()) {
        stringstream ss(line);
        int grade;
        int subjectIdx = 0;
        while (ss >> grade && subjectIdx < (int)subjects.size()) {
            setGrade(studentIdx, subjectIdx, grade);
            subjectIdx++;
        }
        studentIdx++;
    }

    file.close();
    cout << "Загружены оценки из файла " << filename << endl;
    return true;
}

double Group::getStudentAverage(int studentIndex) const {
    if (studentIndex >= 0 && studentIndex < (int)students.size()) {
        return students[studentIndex].getAverage();
    }
    return 0;
}

double Group::getSubjectAverage(int subjectIndex) const {
    if (subjectIndex < 0 || subjectIndex >= (int)subjects.size()) return 0;

    double sum = 0;
    int count = 0;
    for (const auto& row : gradeTable) {
        if (subjectIndex < (int)row.size()) {
            sum += row[subjectIndex];
            count++;
        }
    }
    return count > 0 ? sum / count : 0;
}

double Group::getGroupAverage() const {
    double sum = 0;
    for (const auto& student : students) {
        sum += student.getAverage();
    }
    return students.empty() ? 0 : sum / students.size();
}

int Group::getMaxGradeForSubject(int subjectIndex, int& studentIndex) const {
    int maxGrade = -1;
    studentIndex = -1;

    for (size_t i = 0; i < gradeTable.size(); i++) {
        if (subjectIndex < (int)gradeTable[i].size()) {
            int grade = gradeTable[i][subjectIndex];
            if (grade > maxGrade) {
                maxGrade = grade;
                studentIndex = i;
            }
        }
    }
    return maxGrade;
}

int Group::getMinGradeForSubject(int subjectIndex, int& studentIndex) const {
    int minGrade = 13;
    studentIndex = -1;

    for (size_t i = 0; i < gradeTable.size(); i++) {
        if (subjectIndex < (int)gradeTable[i].size()) {
            int grade = gradeTable[i][subjectIndex];
            if (grade < minGrade && grade > 0) {
                minGrade = grade;
                studentIndex = i;
            }
        }
    }
    return minGrade;
}

void Group::displayGradeTable() const {
    cout << "\n=== ТАБЛИЦА ОЦЕНОК ===" << endl;

    // Заголовок
    cout << left << setw(20) << "Студент / Предмет";
    for (const auto& subject : subjects) {
        cout << setw(10) << subject.getName();
    }
    cout << setw(12) << "Средний" << endl;

    // Разделитель
    cout << string(20 + subjects.size() * 10 + 12, '-') << endl;

    // Данные
    for (size_t i = 0; i < students.size(); i++) {
        cout << left << setw(20) << students[i].getName();
        for (size_t j = 0; j < subjects.size(); j++) {
            if (j < gradeTable[i].size()) {
                cout << setw(10) << gradeTable[i][j];
            }
            else {
                cout << setw(10) << "-";
            }
        }
        cout << setw(12) << fixed << setprecision(2) << students[i].getAverage() << endl;
    }
}

void Group::displayStudentAverages() const {
    cout << "\n=== СРЕДНИЕ ОЦЕНКИ СТУДЕНТОВ ===" << endl;
    for (const auto& student : students) {
        cout << student.getName() << ": " << fixed << setprecision(2) << student.getAverage() << endl;
    }
    cout << "Средний балл группы: " << fixed << setprecision(2) << getGroupAverage() << endl;
}

void Group::displaySubjectAverages() const {
    cout << "\n=== СРЕДНИЕ ОЦЕНКИ ПО ПРЕДМЕТАМ ===" << endl;
    for (size_t i = 0; i < subjects.size(); i++) {
        cout << subjects[i].getName() << ": " << fixed << setprecision(2) << getSubjectAverage(i) << endl;
    }
}

void Group::displaySubjectExtremes() const {
    cout << "\n=== МАКСИМАЛЬНЫЕ И МИНИМАЛЬНЫЕ ОЦЕНКИ ПО ПРЕДМЕТАМ ===" << endl;

    for (size_t i = 0; i < subjects.size(); i++) {
        int studentIdxMax, studentIdxMin;
        int maxGrade = getMaxGradeForSubject(i, studentIdxMax);
        int minGrade = getMinGradeForSubject(i, studentIdxMin);

        cout << subjects[i].getName() << ":" << endl;
        if (studentIdxMax >= 0) {
            cout << "  Максимум: " << maxGrade << " ("
                << students[studentIdxMax].getName() << ")" << endl;
        }
        if (studentIdxMin >= 0) {
            cout << "  Минимум: " << minGrade << " ("
                << students[studentIdxMin].getName() << ")" << endl;
        }
    }
}

void Group::displayAll() const {
    displayGradeTable();
    displayStudentAverages();
    displaySubjectAverages();
    displaySubjectExtremes();
}

string Group::getName() const { return name; }
int Group::getStudentCount() const { return students.size(); }
int Group::getSubjectCount() const { return subjects.size(); }