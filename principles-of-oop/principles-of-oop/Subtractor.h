#ifndef SUBTRACTOR_H
#define SUBTRACTOR_H
#include "ExpressionEvaluator.h"
#include "IShuffle.h"

using namespace std;

class Subtractor : public ExpressionEvaluator, public IShuffle {
public:
    Subtractor(size_t n);
    double calculate() override;
    void logToScreen() override;
    void logToFile(const string& filename) override;
    void shuffle() override;
    void shuffle(size_t i, size_t j) override;
};
#endif