#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include <string>

using namespace std;

class Student : public Person {
private:
    int admissionYear;    
    string recordBookNum; 
    double averageScore;  

public:
    Student(string name, string g, int year, int admYear, string rbNum, double score);
    double calculate() override;
};

#endif