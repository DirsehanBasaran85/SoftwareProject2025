#include "Application.h"

Application::Application()
    : game(std::make_unique<TestGame>(*world)),
      world(std::make_unique<World>()),
      window(std::make_unique<Window>(1200, 800, "Test Window", world->getEntityManager(), world->getInputManager())),
      running(true)
{

}

Application::~Application() {}

void Application::run() {
    if (world->isRunning() && window->isOpen()) {

        window->pollEvents(); //window events
        world->update(); // run systems here
        game->update(); // run game specific unique code here also do your test code here
        window->render(); // render stuff
    }
    else {
        game->shutdown(); // maybe for saving before ending the program
        shutdown();
    }
}

void Application::shutdown() {
    running = false;
}

bool Application::isRunning() {
    return running;
}
