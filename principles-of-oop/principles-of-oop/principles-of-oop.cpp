#define _CRT_SECURE_NO_WARNINGS
#include <iostream>   
#include <fstream>    
#include <string>     
#include <algorithm>  
#include "Multiplier.h"
#include "Substractor.h"
#include "IShuffle.h"
#include "ILoggable.h"
#include "ExpressionEvaluator.h"
#include "CustomExpressionEvaluator.h"
using namespace std;

int main() {

    ExpressionEvaluator* evaluators[3];

    evaluators[0] = new CustomExpressionEvaluator(6);
    double ops0[] = { 5, 16, -3, 10, 12, 2 };
    evaluators[0]->setOperands(ops0, 6);

    evaluators[1] = new Subtractor(4);
    double ops1[] = { 5.6, -2.1, 3.2, 1.5 };
    evaluators[1]->setOperands(ops1, 4);

    evaluators[2] = new Multiplier(3);
    evaluators[2]->setOperand(0, 1.5); 
    evaluators[2]->setOperand(1, -8);
    evaluators[2]->setOperand(2, 2.5);

    for (int i = 0; i < 3; ++i) {
        evaluators[i]->logToScreen();
        cout << "Result: " << evaluators[i]->calculate() << endl << endl;
    }

    cout << "--- RTTI Check ---" << endl;
    for (int i = 0; i < 3; ++i) {
        IShuffle* sh = dynamic_cast<IShuffle*>(evaluators[i]); 
        if (sh) {
            cout << "Object " << i << " supports shuffle. Shuffling..." << endl;
            sh->shuffle();
            evaluators[i]->logToScreen();
            evaluators[i]->logToFile("Logi.log");
            cout << "New Result: " << evaluators[i]->calculate() << endl << endl;
        }
    }
    for (int i = 0; i < 3; ++i) delete evaluators[i];

    return 0;
}