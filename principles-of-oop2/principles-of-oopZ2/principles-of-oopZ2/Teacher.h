#ifndef TEACHER_H
#define TEACHER_H

#include "Person.h"

enum Degree { CANDIDATE, DOCTOR, NO_DEGREE };
enum Rank { DOCENT, PROFESSOR, NO_RANK };

class Teacher : public Person {
private:
    int workStartYear;
    Degree degree;  
    Rank rank;
    int experience;

public:
    Teacher(string name, string g, int year, int startYear, Degree deg, Rank rnk, int exp);
    double calculate() override;
};

#endif