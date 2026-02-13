#include "main.h"
using namespace std;
class Subtractor : public ExpressionEvaluator, public IShuffle {
public:
    Subtractor(size_t n) : ExpressionEvaluator(n) {}

    double calculate() override {
        double res = operands[0];
        for (size_t i = 1; i < count; ++i) res -= operands[i];
        return res;
    }

    void logToScreen() override { cout << "Subtractor (x1 - x2 - ...)" << endl; }
    void logToFile(const string& filename) override {}
    void shuffle() override { swap(operands[0], operands[count - 1]); }
    void shuffle(size_t i, size_t j) override { swap(operands[i], operands[j]); }
};