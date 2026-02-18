#include <iostream>
#include <vector>
#include <typeinfo>
#include "Teacher.h"
#include "Student.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    vector<ISalaryCalculation*> people;

    people.push_back(new Teacher("Масленников В.А.", "Муж", 2003, 2025, "полководец", "ПРОфессор", 1));
    people.push_back(new Teacher("Алексеев В.Д.", "Муж", 2002, 2024, "нолик", "ПРОфессор-в2", 2));
    people.push_back(new Student("Глеп Рубашенков", "Муж", 2007, 2023, "9ИС-323", 4.8));
    people.push_back(new Student("Годид Заблоцкий", "Жен", 2007, 2023, "9ИС-323", 3.9));

    cout << "--- Список выплат ---" << endl;

    for (auto p : people) {
        Person* personPtr = dynamic_cast<Person*>(p);

        if (personPtr) {
            cout << "Объект: " << typeid(*p).name() << endl;
            cout << "ФИО: " << personPtr->getFullName() << endl;
            cout << "Сумма к выплате: " << p->calculate() << " руб." << endl;
            cout << "-----------------------" << endl;
        }
    }

    for (auto p : people) {
        delete p;
    }

    return 0;
}