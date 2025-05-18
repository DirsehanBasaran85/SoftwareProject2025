#include "World.h"
#include <iostream>

World::World() : running(true) {

}

World::~World() {}

EntityManager& World::getEntityManager() {
    return entityManager;
}

InputManager& World::getInputManager() {
    return inputManager;
}

void World::update() {
    //Systems are resolved here not in game

    /*
    * something like this for all entities that have the required components for the systems
    for (auto& system : systems) {
        system->Update();
    }
    */
    auto apple = entityManager.getFirstEntityByTag("apple");
    auto goomba = entityManager.getFirstEntityByTag("goomba");
    auto test = entityManager.getEntityByID(2);

    collisionSystem.resolveCollision(apple, goomba);
    collisionSystem.resolveCollision(apple, test);

    entityManager.Update();
}

bool World::isRunning() const {
    return running;
}