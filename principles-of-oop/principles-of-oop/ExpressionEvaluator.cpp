#include "main.h"
using namespace std;
class ExpressionEvaluator : public ILoggable {
protected:
    double* operands;
    size_t count;

public:
    ExpressionEvaluator() : count(20) {
        operands = new double[20] {0.0};
    }

    ExpressionEvaluator(size_t n) : count(n) {
        operands = new double[n] {0.0};
    }

    virtual ~ExpressionEvaluator() {
        delete[] operands;
    }

    void setOperand(size_t pos, double value) {
        if (pos < count) operands[pos] = value;
    }

    void setOperands(double ops[], size_t n) {
        for (size_t i = 0; i < n && i < count; ++i) operands[i] = ops[i];
    }

    virtual double calculate() = 0;
};