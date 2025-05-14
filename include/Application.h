#pragma once

#include <memory>
#include <string>

#include "Window.h"

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
    Window window;
};