#pragma once
#include "ExpressionEvaluator.h"
#include "IShuffle.h"
#include <string>
#include <algorithm>

using namespace std;

class Subtractor : public ExpressionEvaluator, public IShuffle {
public:
    Subtractor(size_t n) : ExpressionEvaluator(n) {}

    double calculate() override {}
    void logToScreen() override {}
    void logToFile(const string& filename) override {}
    void shuffle() override {}
    void shuffle(size_t i, size_t j) override {}

};