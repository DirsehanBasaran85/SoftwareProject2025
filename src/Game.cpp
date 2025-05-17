#include "Game.h"
#include <iostream>

Game::Game() : running(true) {}

Game::~Game() {}

void Game::attachWindow(Window* w) {
    window = w;
}

EntityManager& Game::getEntityManager() {
    return entityManager;
}

void Game::update() {
    window->processInput(entityManager);

    auto apple = entityManager.getFirstEntityByTag("apple");
    auto goomba = entityManager.getFirstEntityByTag("goomba");
    auto test = entityManager.getEntityByID(2);

    collisionSystem.resolveCollision(apple, goomba);
    collisionSystem.resolveCollision(apple, test);

    entityManager.Update();
}

void Game::runFrame() {
    if (window->getRenderWindow().isOpen()) {
        window->pollEvents();
        update();
        window->render(entityManager);
    }
    else {
        running = false;
    }
}

bool Game::isRunning() const {
    return running;
}