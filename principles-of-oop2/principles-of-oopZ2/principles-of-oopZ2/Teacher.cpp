#include "Teacher.h"

Teacher::Teacher(string name, string g, int year, int startYear, Degree deg, Rank rnk, int exp)
    : Person(name, g, year),
    workStartYear(startYear),
    degree(deg),
    rank(rnk),
    experience(exp)
{
}

double Teacher::calculate() {
    double salary = 5000.0;

    if (degree == DOCTOR) {
        salary += 1200.0;
    }
    else if (degree == CANDIDATE) {
        salary += 700.0;
    }

    if (rank == PROFESSOR) {
        salary += 3500.0;
    }
    else if (rank == DOCENT) {
        salary += 2200.0;
    }

    salary += (experience / 5) * 700.0;

    return salary;
}