#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <chrono>
using namespace std;
class  Summator {

};
void logToFile(const string& filename) {
    ofstream log1("wasd.log", ios_base::app);
    if (log1.is_open()) {
        auto now = chrono::system_clock::now();
        time_t now_time = chrono::system_clock::to_time_t(now);
        log1 << ctime(&now_time) << ": " << filename << endl;
        cout << "Записано в файл" << endl;
        log1.close();
    }
    else {
        cerr << "Не удалось открыть" << endl;
    }
}
int main()
{
    setlocale(LC_ALL, "Russian");
    logToFile("udalenie");
}
