#ifndef PERSON_H
#define PERSON_H

#include <string>
#include "ISalaryCalculation.h"

using namespace std;

class Person : public ISalaryCalculation {
protected:
    string fullName;  
    string gender;   
    int birthYear;    

public:
    Person(string name, string g, int year)
        : fullName(name), gender(g), birthYear(year) {
    }

    virtual ~Person() {}

    string getFullName() { return fullName; }
};

#endif