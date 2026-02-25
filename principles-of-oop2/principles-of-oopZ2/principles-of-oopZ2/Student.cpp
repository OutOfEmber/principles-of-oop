#include "Student.h"

Student::Student(string name, string g, int year, int admYear, string rbNum, double score)
    : Person(name, g, year), admissionYear(admYear), recordBookNum(rbNum), averageScore(score) {}

double Student::calculate() {
    return (averageScore > 4.5) ? 1200.0 : 800.0;
}