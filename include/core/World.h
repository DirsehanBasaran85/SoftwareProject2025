#pragma once

#include "EntityManager.h"
#include "InputManager.h"
#include "Systems.h"
#include "Component.h"

class World {
public:
    World();
    ~World();

    bool isRunning() const;

    EntityManager& getEntityManager();
    InputManager& getInputManager();

    void update();
private:

    EntityManager entityManager;
    InputManager inputManager;
    CollisionSystem collisionSystem;
    bool running = true;
};