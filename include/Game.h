#pragma once

#include "Window.h"

class Game {
public:
    Game();
    ~Game();

    void runFrame();
    bool isRunning() const;

private:
    bool running;
    Window window;
};