#include "Multiplier.h"
#include <iostream>
#include <fstream>

using namespace std;

Multiplier::Multiplier(size_t n) : ExpressionEvaluator(n) {}

double Multiplier::calculate() {
    double res = 1;
    for (size_t i = 0; i < count; ++i) res *= operands[i];
    return res;
}

void Multiplier::logToScreen() {
    for (size_t i = 0; i < count; ++i) {
        cout << formatOp(operands[i]) << (i < count - 1 ? " * " : "");
    }
    cout << endl;
}

void Multiplier::logToFile(const string& filename) {
    ofstream file(filename, ios::app);
    file << "Multiplier calculation logged." << endl;
}