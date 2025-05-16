#pragma once

#include <memory>
#include <string>

#include "Game.h"

//Core of the program controls System initialization and how Systems are processed

class Application {

public:
    Application();
    ~Application();

    void processSystems();
    void shutdown();
    bool isRunning();

private:
    bool running;
    std::unique_ptr<Game> game;
};