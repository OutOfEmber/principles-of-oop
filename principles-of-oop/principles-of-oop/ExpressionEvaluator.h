#ifndef EXPRESSIONEVALUATOR_H
#define EXPRESSIONEVALUATOR_H
#include "ILoggable.h"

using namespace std;

class ExpressionEvaluator : public ILoggable {
protected:
    double* operands;
    size_t count;
    string formatOp(double val);

public:
    ExpressionEvaluator();
    ExpressionEvaluator(size_t n);
    virtual ~ExpressionEvaluator();

    void setOperand(size_t pos, double value);
    void setOperands(double ops[], size_t n);
    virtual double calculate() = 0;
};
#endif