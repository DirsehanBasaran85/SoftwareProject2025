#include "Application.h"
#include "Window.h"

Application::Application()
    : running(true), window(nullptr) {
    initializeSystems();
}

Application::~Application() {

}

void Application::initializeWindow(unsigned int width, unsigned int height, const std::string& title) {
    if (!window) {  
        window = std::make_unique<Window>(width, height, title); 
        window->run();  
    }
}

void Application::initializeSystems() {

    initializeWindow(1200, 800, "Test");
    //initializeRenderer() etc.

}

void Application::processSystems() {
    if (window && window->isOpen()) {
        
    }
    else {
        shutdown();
    }
}

void Application::shutdown() {
    running = false;
    if (window && window->isOpen()) {
        window->close(); 
    }
}

bool Application::isRunning() {
    return running;
}
