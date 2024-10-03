#ifndef SCREEN_MANAGER_H
#define SCREEN_MANAGER_H

#include <string>
#include <vector>

class ScreenManager {
public:
    int getTerminalWidth();

    void clearScreen();
    void refreshDisplay(const std::string& marqueeText, int marqueePos, const std::vector<std::string>& commandHistory, const std::string& currentInput);
};

#endif // SCREEN_MANAGER_H