#ifndef TEACHER_H
#define TEACHER_H

#include "Person.h"

class Teacher : public Person {
private:
    int workStartYear;
    string degree;   
    string rank;    
    int experience;

public:
    Teacher(string name, string g, int year, int startYear, string deg, string rnk, int exp)
        : Person(name, g, year), workStartYear(startYear), degree(deg), rank(rnk), experience(exp) {
    }

    double calculate() override {
        double salary = 5000.0; // базовая ставка

        if (degree == "кандидат наук") salary += 700;
        else if (degree == "доктор наук") salary += 1200;

        if (rank == "доцент") salary += 2200;
        else if (rank == "профессор") salary += 3500;

        salary += (experience / 5) * 700; // надбавка за стаж
        return salary;
    }
};

#endif