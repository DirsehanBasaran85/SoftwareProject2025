#include "Application.h"
#include "Window.h"

Application::Application()
    : running(true), window(1200,800,"test") {
   
    window.run();
}

Application::~Application() {

}


void Application::processSystems() {
    
    if (window.isOpen()) {
        //game related stuff goes here
    }
    else {
        shutdown();
    }
}

void Application::shutdown() {
    
    running = false;
    if (window.isOpen()) {
        window.close(); 
    }
}

bool Application::isRunning() {
    
    return running;
}
