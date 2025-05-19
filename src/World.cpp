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
    auto player = entityManager.getEntityByID(0); // get player
    EntityMap& emap = entityManager.getEntityMap();
    EntityVec& enemies = emap["enemy"];

    for (auto e : enemies) {
        collisionSystem.resolveCollision(player, e);
    }
    

    entityManager.Update();
}

bool World::isRunning() const {
    return running;
}