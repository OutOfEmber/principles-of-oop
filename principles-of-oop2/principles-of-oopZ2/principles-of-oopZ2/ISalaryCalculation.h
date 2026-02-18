#ifndef ISALARYCALCULATION_H
#define ISALARYCALCULATION_H

class ISalaryCalculation {
public:
    virtual double calculate() = 0;
    virtual ~ISalaryCalculation() {}
};

#endif