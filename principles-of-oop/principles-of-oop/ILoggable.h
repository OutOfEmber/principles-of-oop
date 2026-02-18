#ifndef ILOGGABLE_H
#define ILOGGABLE_H
#include <string>

using namespace std;

class ILoggable {
public:
    virtual void logToScreen() = 0;
    virtual void logToFile(const string& filename) = 0;
    virtual ~ILoggable() {}
};
#endif