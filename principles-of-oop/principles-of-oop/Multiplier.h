#ifndef MULTIPLIER_H
#define MULTIPLIER_H
#include "ExpressionEvaluator.h"

using namespace std;

class Multiplier : public ExpressionEvaluator {
public:
    Multiplier(size_t n);
    double calculate() override;
    void logToScreen() override;
    void logToFile(const string& filename) override;
};
#endif