#include "ScreenManager.h"
#include <iostream>
#include <cstdlib>  // For system()
#include <windows.h>

// Clear the console screen
void ScreenManager::clearScreen() {
    system("cls");  // Use "cls" on Windows
}

// Refresh the display with the marquee, input line, and command history
void ScreenManager::refreshDisplay(const std::string& marqueeText, int marqueePos, const std::vector<std::string>& commandHistory, const std::string& currentInput) {
    clearScreen();

    // Display the header
    std::cout << "****************************" << std::endl;
    std::cout << "* Displaying a marquee console! *" << std::endl;
    std::cout << "****************************" << std::endl;

    // Display the bouncing marquee
    std::cout << std::string(marqueePos, ' ') << marqueeText << std::endl;

    // Ensure the current input is always visible in the format "> input line"
    std::cout << "\n> " << currentInput << std::flush;

    // Display the input history below the current input line
    for (const auto& command : commandHistory) {
        std::cout << "\n" << command;
    }

    // Make sure everything is flushed properly to the console
    std::cout << std::flush;
}

// Get the width of the terminal dynamically
int ScreenManager::getTerminalWidth() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Right - csbi.srWindow.Left + 1;
}
