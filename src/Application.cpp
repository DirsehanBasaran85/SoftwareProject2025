#include "Application.h"

Application::Application()
    : world(std::make_unique<World>()),
      window(std::make_unique<Window>(1200, 800, "Test Window", world->getEntityManager(), world->getInputManager())), 
      game(std::make_unique<TestGame>()),
      running(true)
{
    game->Init(*world);
}

Application::~Application() {}


void Application::run() {
    game->Init(*world);
    if (world->isRunning() && window->isOpen()) {

        window->pollEvents();
        world->update();
        game->Update(*world);
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
