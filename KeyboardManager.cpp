#include "KeyboardManager.h"
#include <iostream>

KeyboardManager::KeyboardManager() : inputBuffer("") {}

// Handle key input (character, backspace, enter)
void KeyboardManager::processInput(char key) {
    if (key == '\r') {  // Enter key

		// save command to history
        if (!inputBuffer.empty()) {
            commandHistory.push_back(inputBuffer);
			inputBuffer.clear();
        }
    }
    else if (key == '\b') {  // Backspace handling
        if (!inputBuffer.empty()) {
            inputBuffer.pop_back();  // Remove the last character from the buffer
        }
    }
    else {
        inputBuffer += key;  // Append typed character to the buffer
    }
}

// Get the current input buffer (for display)
std::string KeyboardManager::getCurrentInput() const {
    return inputBuffer;
}

// Get the command history (for display)
const std::vector<std::string>& KeyboardManager::getCommandHistory() const {
    return commandHistory;
}

void KeyboardManager::clearCommandHistory() {
	commandHistory.clear();
}