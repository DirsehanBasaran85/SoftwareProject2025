#pragma once

#include <memory>
#include <string>

#include "Window.h"

class Application {

public:
    Application();
    ~Application();

    void initializeWindow(unsigned int width, unsigned int height, const std::string& title);
    void initializeSystems();
    void processSystems();
    void shutdown();
    bool isRunning();

private:
    bool running;
    std::unique_ptr<Window> window;  
};