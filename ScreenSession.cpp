#include "ScreenSession.h"

// Constructor to initialize session
ScreenSession::ScreenSession(ScreenManager& manager, int rate)
    : screenManager(manager), refreshRate(rate), running(false) {}

// Start the session
void ScreenSession::start(const std::vector<std::string>& commandHistory, const std::string& currentInput) {
    running = true;
}

// Stop the session
void ScreenSession::stop() {
    running = false;
}