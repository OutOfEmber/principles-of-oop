#include "ExpressionEvaluator.h"
#include <iostream>

using namespace std;

ExpressionEvaluator::ExpressionEvaluator() : count(20) {
    operands = new double[20] {0};
}

ExpressionEvaluator::ExpressionEvaluator(size_t n) : count(n) {
    operands = new double[n] {0};
}

ExpressionEvaluator::~ExpressionEvaluator() {
    delete[] operands;
}

void ExpressionEvaluator::setOperand(size_t pos, double value) {
    if (pos < count) operands[pos] = value;
}

void ExpressionEvaluator::setOperands(double ops[], size_t n) {
    for (size_t i = 0; i < n && i < count; ++i) operands[i] = ops[i];
}

string ExpressionEvaluator::formatOp(double val) {
    return (val < 0) ? "(" + to_string(val) + ")" : to_string(val);
}