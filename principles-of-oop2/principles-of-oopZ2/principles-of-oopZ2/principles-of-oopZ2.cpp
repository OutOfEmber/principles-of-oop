#include <iostream>
#include <iomanip>
#include <typeinfo>
#include <vector>
#include "Teacher.h"
#include "Student.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    vector<ISalaryCalculation*> people;

    people.push_back(new Teacher("Масленников В.А.", "Муж", 2003, 2025, CANDIDATE, PROFESSOR, 1));
    people.push_back(new Teacher("Алексеев В.Д.", "Муж", 2001, 2020, DOCTOR, DOCENT, 5));

    people.push_back(new Student("Рубашенков Г.А.", "Муж", 2007, 2023, "9ИС-223.1", 4.8));
    people.push_back(new Student("Заблоцкий Н.А.", "Муж", 2007, 2023, "9ИС-223.2", 3.9));

    cout << "--- Список выплат ---" << endl;

    for (auto p : people) {
        Person* personPtr = dynamic_cast<Person*>(p);

        if (personPtr) {
            cout << "Объект: " << typeid(*p).name() << endl;
            cout << "ФИО: " << personPtr->getFullName() << endl;
            cout << "Сумма к выплате: " << fixed << setprecision(0) << p->calculate() << " руб." << endl;
            cout << "------------------------------------------" << endl;
        }
    }

    for (auto p : people) delete p;

    return 0;
}