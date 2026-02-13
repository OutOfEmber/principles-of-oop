#pragma once
#include "ILoggable.h"
class ExpressionEvaluator : public ILoggable {
protected:
    double* operands;
    size_t count;

public:
    ExpressionEvaluator() : count(20) {}
    ExpressionEvaluator(size_t n) : count(n) {}
    virtual ~ExpressionEvaluator() {}
    void setOperand(size_t pos, double value) {}
    void setOperands(double ops[], size_t n) {}
    virtual double calculate() = 0;
};