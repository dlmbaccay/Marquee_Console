#include "MarqueeSession.h"
#include <thread>
#include <chrono>
#include <iostream>
#include <windows.h> // For SetConsoleCursorPosition

// Constructor initializes base class and sets marquee-specific attributes
MarqueeSession::MarqueeSession(ScreenManager& manager, const std::string& text, int rate, int height)
    : ScreenSession(manager, rate), marqueeText(text), xPosition(0), yPosition(0), xDirection(1), yDirection(1), maxHeight(height) {}

// Update marquee position and handle diagonal bouncing
void MarqueeSession::update() {
    int terminalWidth = screenManager.getTerminalWidth();

    // The marquee moves within the top "maxHeight" lines of the terminal
    size_t maxXPosition = terminalWidth - marqueeText.length();
    int maxYPosition = maxHeight - 1;  // Vertical bounds

    // Horizontal (X-axis) bouncing
    if (xPosition <= 0) {
        xDirection = 1;  // Bounce to the right
    }
    else if (xPosition >= maxXPosition) {
        xDirection = -1;  // Bounce to the left
    }

    // Vertical (Y-axis) bouncing
    if (yPosition <= 0) {
        yDirection = 1;  // Bounce down
    }
    else if (yPosition >= maxYPosition) {
        yDirection = -1;  // Bounce up
    }

    // Update the position based on current directions
    xPosition += xDirection;
    yPosition += yDirection;
}

// Get the current text of the marquee
std::string MarqueeSession::getText() const {
    return marqueeText;
}

// Get the current X position of the marquee
int MarqueeSession::getXPosition() const {
    return xPosition;
}

// Get the current Y position of the marquee
int MarqueeSession::getYPosition() const {
    return yPosition;
}

// Get the refresh rate from the base class (ScreenSession)
int MarqueeSession::getRefreshRate() const {
    return refreshRate;
}

// Refresh the display with the marquee, input line, and command history
void MarqueeSession::refreshDisplay(const std::vector<std::string>& commandHistory, const std::string& currentInput) {
    screenManager.clearScreen();

    // Display the header
    std::cout << "*********************************" << std::endl;
    std::cout << "* Displaying a marquee console! *" << std::endl;
    std::cout << "*********************************" << std::endl;

    // Move the cursor to the Y position of the marquee
    for (int i = 0; i < yPosition; ++i) {
        std::cout << std::endl;  // Add empty lines to simulate the Y position of the marquee
    }

    // Display the bouncing marquee at the X position
    std::cout << std::string(xPosition, ' ') << marqueeText << std::endl;

    // Leave enough vertical space for input and history
    for (int i = yPosition; i < maxHeight; ++i) {
        std::cout << std::endl;
    }

    // Display the input history just above the input line
    for (const auto& command : commandHistory) {
        std::cout << "Processed command: " << command << std::endl;
    }

    // Use Windows API to set cursor position for the input line
    COORD coord;
    coord.X = 0; // Reset X to start of the line
    coord.Y = maxHeight + 3; // Position below the history (fixed at bottom)
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); // Move cursor to input area

    // Display the input prompt with current input
    std::cout << "> " << currentInput << std::flush;

    // Ensure everything is flushed properly to the console
    std::cout << std::flush;
}