#ifndef KEYBOARD_MANAGER_H
#define KEYBOARD_MANAGER_H

#include <string>
#include <vector>

class KeyboardManager {
private:
    std::string inputBuffer;
    std::vector<std::string> commandHistory;

public:
    KeyboardManager();

    const std::vector<std::string>& getCommandHistory() const;

    std::string getCurrentInput() const;

    void processInput(char key);
    void clearBuffer();
    void saveCommand();

};

#endif // KEYBOARD_MANAGER_H