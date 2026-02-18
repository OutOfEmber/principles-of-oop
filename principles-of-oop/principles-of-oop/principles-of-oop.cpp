#include <iostream>
#include <fstream>
#include <typeinfo>
#include "CustomExpressionEvaluator.h"
#include "Subtractor.h"
#include "Multiplier.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    ExpressionEvaluator* evaluators[3];


    evaluators[0] = new CustomExpressionEvaluator(6);
    double данные0[] = { 5, 16, -3, 10, 12, 2 };
    evaluators[0]->setOperands(данные0, 6);

    evaluators[1] = new Subtractor(4);
    double данные1[] = { 5.6, -2.1, 3.2, 1.5 };
    evaluators[1]->setOperands(данные1, 4);

    evaluators[2] = new Multiplier(3);
    evaluators[2]->setOperand(0, 1.5);
    evaluators[2]->setOperand(1, -8);
    evaluators[2]->setOperand(2, 2.5);

    cout << "===== ИСХОДНЫЕ ВЫРАЖЕНИЯ =====" << endl << endl;

    for (int i = 0; i < 3; ++i) {
        cout << "Выражение #" << i + 1 << ":" << endl;

        evaluators[i]->logToScreen();

        cout << "Результат: " << evaluators[i]->calculate() << endl;

        evaluators[i]->logToFile("лаба3.log");
        cout << "-----------------------------------" << endl;
    }

    cout << endl << "===== ПРОВЕРКА ИНТЕРФЕЙСА ISHUFFLE (RTTI) =====" << endl << endl;

    for (int i = 0; i < 3; ++i) {
        IShuffle* shuffler = dynamic_cast<IShuffle*>(evaluators[i]);

        if (shuffler) {
            cout << "Объект #" << i + 1 << " поддерживает перемешивание." << endl;
            cout << "Состояние ДО перемешивания:" << endl;
            evaluators[i]->logToScreen();

            shuffler->shuffle();

            cout << "Состояние ПОСЛЕ перемешивания (первый и последний операнды):" << endl;
            evaluators[i]->logToScreen();
            cout << "Новый результат: " << evaluators[i]->calculate() << endl;
        }
        else {
            cout << "Объект #" << i + 1 << " НЕ поддерживает перемешивание (Multiplier)." << endl;
        }
        cout << "-----------------------------------" << endl;
    }

    for (int i = 0; i < 3; ++i) {
        delete evaluators[i];
    }

    return 0;
}