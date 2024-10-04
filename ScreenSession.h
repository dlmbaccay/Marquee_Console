#ifndef SCREEN_SESSION_H
#define SCREEN_SESSION_H

#include "ScreenManager.h"
#include <vector>

class ScreenSession {
protected:  // Protected so that derived classes can access them
    ScreenManager& screenManager;
    bool running;
    int refreshRate; // In milliseconds

public:
    ScreenSession(ScreenManager& manager, int rate);
    virtual ~ScreenSession() = default;

    virtual void start(const std::vector<std::string>& commandHistory, const std::string& currentInput);
    virtual void stop();
};

#endif // SCREEN_SESSION_H