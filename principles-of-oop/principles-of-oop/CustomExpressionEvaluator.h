#pragma once
#include <iostream>
#include "ExpressionEvaluator.h"
#include "IShuffle.h"
#include <fstream>

using namespace std;

class CustomExpressionEvaluator : public ExpressionEvaluator, public IShuffle {
public:
    CustomExpressionEvaluator(size_t n) : ExpressionEvaluator(n) {}

    double calculate() override {};

    void logToScreen() override {};

    void logToFile(const string& filename) override {};

    void shuffle() override {};
    void shuffle(size_t i, size_t j) override {};
};