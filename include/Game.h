#pragma once

#include "EntityManager.h"
#include "Systems.h"

class Game {
public:
    Game();
    ~Game();

    bool isRunning() const;

    EntityManager& getEntityManager();

    void update();
private:

    EntityManager entityManager;
    CollisionSystem collisionSystem;
    bool running = true;
};