#include "CustomExpressionEvaluator.h"
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

CustomExpressionEvaluator::CustomExpressionEvaluator(size_t n) : ExpressionEvaluator(n) {}

double CustomExpressionEvaluator::calculate() {
    double res = operands[0];
    for (size_t i = 1; i < count; ++i) res += operands[i] / (i + 1);
    return res;
}

void CustomExpressionEvaluator::logToScreen() {
    for (size_t i = 0; i < count; ++i) {
        cout << formatOp(operands[i]);
        if (i > 0) cout << "/" << (i + 1);
        if (i < count - 1) cout << " + ";
    }
    cout << endl;
}

void CustomExpressionEvaluator::logToFile(const string& filename) {
    ofstream file(filename, ios::app);
    file << "Custom (Var 1) calculation logged." << endl;
}

void CustomExpressionEvaluator::shuffle() { swap(operands[0], operands[count - 1]); }
void CustomExpressionEvaluator::shuffle(size_t i, size_t j) { if (i < count && j < count) swap(operands[i], operands[j]); }