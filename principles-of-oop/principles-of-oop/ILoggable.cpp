#include "main.h"
class ILoggable {
public:
    virtual void logToScreen() = 0;
    virtual void logToFile(const string& filename) = 0;
    virtual ~ILoggable() {}
};