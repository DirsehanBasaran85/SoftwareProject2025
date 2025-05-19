#include "Application.h"

Application::Application()
    : 
    world(std::make_unique<World>()),
    game(std::make_unique<TestGame>(*world)),
    window(std::make_unique<Window>(1200, 800, "Test Window", world->getEntityManager(), world->getInputManager())),
    running(true)
{

}

Application::~Application() {}

void Application::run() {
    if (world->isRunning() && window->isOpen()) {

        window->pollEvents(); //window events
        game->update(); // run game specific unique code here also do your test code here
        world->update(); // run systems here
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