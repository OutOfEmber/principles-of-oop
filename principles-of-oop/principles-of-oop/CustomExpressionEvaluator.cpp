#include "main.h"
using namespace std;

class CustomExpressionEvaluator : public ExpressionEvaluator, public IShuffle {
public:
    CustomExpressionEvaluator(size_t n) : ExpressionEvaluator(n) {}

    double calculate() override {
        double res = operands[0];
        for (size_t i = 1; i < count; ++i) res += operands[i] / (i + 1);
        return res;
    }

    void logToScreen() override {
        cout << "CustomExpression [" << count << " operands]: ";
        for (size_t i = 0; i < count; ++i) cout << (operands[i] < 0 ? "(" + to_string(operands[i]) + ")" : to_string(operands[i])) << " ";
        cout << endl;
    }

    void logToFile(const string& filename) override {
        ofstream file(filename, ios::app);
        file << "Logged CustomExpression" << endl;
    }

    void shuffle() override { shuffle(0, count - 1); }
    void shuffle(size_t i, size_t j) override {
        if (i < count && j < count) {
            swap(operands[i], operands[j]);
            operands[i] *= -1;
            operands[j] *= -1;
        }
    }
};