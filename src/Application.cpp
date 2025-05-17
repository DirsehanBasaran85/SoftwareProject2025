#include "Application.h"

Application::Application()
    : game(std::make_unique<Game>()), running(true)
{
    window = std::make_unique<Window>(1200, 800, "Test Window", game->getEntityManager());
    game->attachWindow(window.get());
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
