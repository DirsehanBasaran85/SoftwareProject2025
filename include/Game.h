#pragma once

#include <SFML/Graphics.hpp>
#include "InputManager.h"
#include "AssetManager.h"
#include "Scene.h"
#include "Renderer.h"
#include "EntityManager.h"
#include "Systems.h"

class Game {
public:
    Game(unsigned int width = 1200, unsigned int height = 800, const std::string& title = "test");
    ~Game();

    void runFrame();
    bool isRunning() const;

private:
    void processInput();
    void update();
    void render();
    void pollEvents();

    sf::RenderWindow window;
    InputManager input;
    AssetManager assetManager;
    Scene scene;
    Renderer renderer;
    EntityManager entityManager;
    CollisionSystem collisionSystem;

    bool running;
};