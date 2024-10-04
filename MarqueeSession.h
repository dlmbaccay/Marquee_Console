#ifndef MARQUEE_SESSION_H
#define MARQUEE_SESSION_H

#include "ScreenManager.h"
#include "ScreenSession.h"
#include <string>
#include <vector>

class MarqueeSession : public ScreenSession {
private:
    std::string marqueeText;
    int xPosition, yPosition;    // X and Y positions for diagonal movement
    int xDirection, yDirection;  // Directions for both horizontal and vertical movement
    int maxHeight;               // Fixed height for the marquee

public:
    MarqueeSession(ScreenManager& manager, const std::string& text, int rate, int height);

    void update();
    void refreshDisplay(const std::vector<std::string>& commandHistory, const std::string& currentInput);
};

#endif // MARQUEE_SESSION_H