#include <iostream>
#include <string>
#include <vector>

using namespace std;

class IPayment {
public:
    virtual double calculatePayment() = 0;
    virtual ~IPayment() {}
};

class Person {
protected:
    string name;    
    int birthYear;  
    string gender;  

public:
    Person(string n, int y, string g) : name(n), birthYear(y), gender(g) {}

    virtual void printInfo() {
        cout << "ФИО: " << name << ", Год рождения: " << birthYear << ", Пол: " << gender;
    }

    virtual ~Person() {}
};

class Teacher : public Person, public IPayment {
private:
    int experience;  
    string position;   
    string degree;

public:
    Teacher(string n, int y, string g, int exp, string pos, string deg)
        : Person(n, y, g), experience(exp), position(pos), degree(deg) {}

    void printInfo() override {
        cout << "[ПРЕПОДАВАТЕЛЬ] ";
        Person::printInfo();
        cout << ", Должность: " << position << ", Степень: " << degree << ", Стаж: " << experience << " лет" << endl;
    }

    double calculatePayment() override {
        double salary = 5000.0;
        salary += experience * 300.0;
        if (degree == "Доктор наук") salary += 2000.0;
        return salary;
    }
};

class Student : public Person, public IPayment {
private:
    int entryYear;      
    string recordBook;  
    double averageScore;

public:
    Student(string n, int y, string g, int eYear, string rb, double score)
        : Person(n, y, g), entryYear(eYear), recordBook(rb), averageScore(score) {}

    void printInfo() override {
        cout << "[СТУДЕНТ] ";
        Person::printInfo();
        cout << ", Зачетка: " << recordBook << ", Ср. балл: " << averageScore << endl;
    }

    double calculatePayment() override {
        return (averageScore >= 4.5) ? 1500.0 : 900.0;
    }
};


int main() {
    setlocale(LC_ALL, "ru");
    Person* community[3];

    community[0] = new Teacher("Александр Петров", 1975, "Муж", 20, "Профессор", "Доктор наук");
    community[1] = new Student("Мария Сидорова", 2004, "Жен", 2022, "22-ИВТ-01", 4.8);
    community[2] = new Student("Игорь Волков", 2005, "Муж", 2023, "23-ИВТ-05", 3.9);

    cout << "=== Список университета ===" << endl;

    for (int i = 0; i < 3; ++i) {
        community[i]->printInfo();

        IPayment* p = dynamic_cast<IPayment*>(community[i]);
        if (p) {
            cout << ">>> Начислено к выплате: " << p->calculatePayment() << " руб." << endl;
        }
        cout << "---------------------------" << endl;
    }

    for (int i = 0; i < 3; ++i) {
        delete community[i];
    }

    return 0;
}