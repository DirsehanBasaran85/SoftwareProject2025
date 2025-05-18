#include "Application.h"

Application::Application()
    : world(std::make_unique<World>()),
      window(std::make_unique<Window>(1200, 800, "Test Window", world->getEntityManager(), world->getInputManager())), 
      game(std::make_unique<TestGame>(*world)),
      running(true)
{

}

Application::~Application() {}

void Application::run() {
    if (world->isRunning() && window->isOpen()) {

        window->pollEvents();
        world->update();
        game->update();
        window->render();
    }
    else {
        game->shutdown();
        shutdown();
    }
}

void Application::shutdown() {
    running = false;
}

bool Application::isRunning() {
    return running;
}
