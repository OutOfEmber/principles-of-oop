#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <chrono>
using namespace std;

void logToFile(const string& message) {
    ofstream log("logi.log", ios_base::app);
    if (log.is_open()) {
        auto now = chrono::system_clock::now();
        time_t now_time = chrono::system_clock::to_time_t(now);
        log << ctime(&now_time) << "->" << message << endl;
        cout << "Записано в файл" << endl;
        log.close();
    }
    else {
        cerr << "Не удалось открыть" << endl;
    }
}
void logToScreen() {
    ifstream log("logi.log");
    if (!log.is_open()) {
        cerr << "Не удалось открыть" << endl;
        return;
    }
    string line;
    while (getline(log , line)) {
        cout << line << endl;
    }
    log.close();
}
int main()
{
    setlocale(LC_ALL, "Russian");
    logToFile("h");
    logToScreen();
}
