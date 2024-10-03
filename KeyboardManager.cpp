#include "KeyboardManager.h"
#include <iostream>

KeyboardManager::KeyboardManager() : inputBuffer("") {}

// Handle key input (character, backspace, enter)
void KeyboardManager::processInput(char key) {
    if (key == '\r') {  // Enter key
        saveCommand();  // Save the current command to history
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

// Save the current input buffer as a command and clear the buffer
void KeyboardManager::saveCommand() {
    if (!inputBuffer.empty()) {
        commandHistory.push_back(inputBuffer);  // Add the input to the command history
        inputBuffer.clear();  // Clear the buffer after pressing Enter
    }
}

// Clear the input buffer
void KeyboardManager::clearBuffer() {
    inputBuffer.clear();
}

// Get the current input buffer (for display)
std::string KeyboardManager::getCurrentInput() const {
    return inputBuffer;
}

// Get the command history (for display)
const std::vector<std::string>& KeyboardManager::getCommandHistory() const {
    return commandHistory;
}
