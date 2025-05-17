#pragma once

#include "Window.h"
#include "EntityManager.h"
#include "Systems.h"

class Game {
public:
    Game();
    ~Game();

    void runFrame();
    bool isRunning() const;

    EntityManager& getEntityManager();
    void attachWindow(Window* w); // to be called after both game and window are constructed

private:
    void update();

    EntityManager entityManager;
    Window* window = nullptr; // reference set with attachWindow
    CollisionSystem collisionSystem;
    bool running = true;
};