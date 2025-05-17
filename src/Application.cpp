#include "Application.h"

Application::Application()
    : game(std::make_unique<Game>()), running(true) {
   
}

Application::~Application() {

}


void Application::processSystems() {
    if (game->isRunning()) {
        game->runFrame();
    }
    else {
        shutdown();
    }
}

void Application::shutdown() {
    running = false;
}

bool Application::isRunning() {
    return running;
}
