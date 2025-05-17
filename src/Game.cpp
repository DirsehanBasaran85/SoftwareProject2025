#include "Game.h"
#include <iostream>

Game::Game() : running(true) {

    entityManager.addInitializedEntityByTag("apple", { 570,400 });
    entityManager.addInitializedEntityByTag("goomba", { 300,300 });
    entityManager.AddComponents("test");
    entityManager.Update();

}

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

bool Game::isRunning() const {
    return running;
}