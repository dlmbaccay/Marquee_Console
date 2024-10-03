#include "ScreenManager.h"
#include "MarqueeSession.h"
#include "KeyboardManager.h"
#include <thread>
#include <atomic>
#include <iostream>
#include <conio.h>  // For _kbhit() and _getch() on Windows

const int REFRESH_RATE = 50;  // Refresh rate in milliseconds
const int POLLING_RATE = 25;   // Polling rate for keyboard input in milliseconds
const int MARQUEE_HEIGHT = 15;  // Height of the area where the marquee will bounce

std::atomic<bool> running(true);

// Marquee session thread function
void marqueeThread(MarqueeSession& marqueeSession, KeyboardManager& keyboardManager) {
    while (running) {
        marqueeSession.update();  // Update marquee position
        marqueeSession.refreshDisplay(keyboardManager.getCommandHistory(), keyboardManager.getCurrentInput()); // Refresh the display
        std::this_thread::sleep_for(std::chrono::milliseconds(REFRESH_RATE));  // Refresh at regular intervals
    }
}

// Keyboard input thread function
void keyboardThread(KeyboardManager& keyboardManager) {
    while (running) {
        if (_kbhit()) { // Check if a key has been pressed
            char key = _getch();  // Capture the key pressed
            keyboardManager.processInput(key);  // Process the input and update the buffer
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(POLLING_RATE));  // Polling interval
    }
}

int main() {
    // Create a ScreenManager instance
    ScreenManager screenManager;

    // Create a MarqueeSession with a height of MARQUEE_HEIGHT and a refresh rate of REFRESH_RATE
    MarqueeSession marqueeSession(screenManager, "Hello World in marquee!", REFRESH_RATE, MARQUEE_HEIGHT);

    // Create a KeyboardManager instance
    KeyboardManager keyboardManager;

    // Start the marquee and keyboard threads
    std::thread marqueeTh(marqueeThread, std::ref(marqueeSession), std::ref(keyboardManager));
    std::thread keyboardTh(keyboardThread, std::ref(keyboardManager));

    // Wait for both threads to complete
    if (marqueeTh.joinable()) marqueeTh.join();
    if (keyboardTh.joinable()) keyboardTh.join();

    return 0;
}