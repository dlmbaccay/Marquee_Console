#include "ScreenManager.h"
#include <iostream>
#include <cstdlib>  // For system()
#include <windows.h>

// Clear the console screen
void ScreenManager::clearScreen() {
    system("cls");  // Use "cls" on Windows
}

// Get the width of the terminal dynamically
int ScreenManager::getTerminalWidth() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Right - csbi.srWindow.Left + 1;
}