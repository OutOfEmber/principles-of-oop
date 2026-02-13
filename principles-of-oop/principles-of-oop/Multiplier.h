#pragma once
#include <iostream>
#include "ExpressionEvaluator.h"
#include <string>

using namespace std;

class Multiplier : public ExpressionEvaluator {
public:
    Multiplier(size_t n) : ExpressionEvaluator(n) {};
    virtual double calculate() override {};
    virtual void logToScreen() override {};
    virtual void logToFile(const string& filename) override {};
};