#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"

class Student : public Person {
private:
    int admissionYear;
    string recordBookNum;
    double averageScore;

public:
    Student(string name, string g, int year, int admYear, string rbNum, double score)
        : Person(name, g, year), admissionYear(admYear), recordBookNum(rbNum), averageScore(score) {
    }

    double calculate() override {
        return (averageScore > 4.5) ? 1200.0 : 800.0;
    }
};

#endif