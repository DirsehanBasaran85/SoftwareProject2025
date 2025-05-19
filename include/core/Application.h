#pragma once

#include <memory>
#include <string>

#include "World.h"
#include "Window.h"
#include "testgame.h"


//Core of the program controls System initialization and how Systems are processed

class Application {

public:
    Application();
    ~Application();

    void run();
    void shutdown();
    bool isRunning();

private:
    bool running;
    std::unique_ptr<World> world;
    std::unique_ptr<GameInterface> game;
    std::unique_ptr<Window> window;
};