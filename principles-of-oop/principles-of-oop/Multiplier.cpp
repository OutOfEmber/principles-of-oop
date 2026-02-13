#include "main.h"
using namespace std;
class Multiplier : public ExpressionEvaluator {
public:
    Multiplier(size_t n) : ExpressionEvaluator(n) {}
    double calculate() override {
        double res = operands[0];
        for (size_t i = 1; i < count; ++i) res *= operands[i];
        return res;
    }
    void logToScreen() override { cout << "Multiplier (x1 * x2 * ...)" << endl; }
    void logToFile(const string& filename) override {}
};