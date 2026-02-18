#include "Subtractor.h"
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

Subtractor::Subtractor(size_t n) : ExpressionEvaluator(n) {}

double Subtractor::calculate() {
    double res = operands[0];
    for (size_t i = 1; i < count; ++i) res -= operands[i];
    return res;
}

void Subtractor::logToScreen() {
    for (size_t i = 0; i < count; ++i) {
        cout << formatOp(operands[i]) << (i < count - 1 ? " - " : "");
    }
    cout << endl;
}

void Subtractor::logToFile(const string& filename) {
    ofstream file(filename, ios::app);
    file << "Subtractor calculation logged." << endl;
}

void Subtractor::shuffle() { swap(operands[0], operands[count - 1]); }
void Subtractor::shuffle(size_t i, size_t j) { if (i < count && j < count) swap(operands[i], operands[j]); }