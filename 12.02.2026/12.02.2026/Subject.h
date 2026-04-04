#ifndef SUBJECT_H
#define SUBJECT_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Subject {
private:
    string name;

public:
    Subject(const string& n = "");
    Subject(const Subject& other);
    ~Subject();

    string getName() const;
    void setName(const string& n);

    void display() const;
};

#endif