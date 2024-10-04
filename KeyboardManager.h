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

	void processInput(char key);
	std::string getCurrentInput() const;
    const std::vector<std::string>& getCommandHistory() const;
	void clearCommandHistory();
};

#endif // KEYBOARD_MANAGER_H