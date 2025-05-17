#pragma once

#include "Window.h"
#include "EntityManager.h"
#include "Systems.h"

class Game {
public:
    Game();
    ~Game();

    bool isRunning() const;

    EntityManager& getEntityManager();
    void attachWindow(Window* w); // to be called after both game and window are constructed

    void update();
private:

    EntityManager entityManager;
    Window* window = nullptr; // reference set with attachWindow
    CollisionSystem collisionSystem;
    bool running = true;
};