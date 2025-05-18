#include "Application.h"

Application::Application()
    : game(std::make_unique<Game>()),
      window(std::make_unique<Window>(1200, 800, "Test Window", game->getEntityManager())), running(true)
{}

Application::~Application() {}


void Application::processSystems() {
    if (game->isRunning() && window->isOpen()) {

        window->pollEvents();
        window->processInput(game->getEntityManager());
        game->update();
        window->render();
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
