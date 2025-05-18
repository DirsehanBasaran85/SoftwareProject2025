#pragma once

#include "DebugMenu.h"
#include "AssetManager.h"
#include "Scene.h"
#include "EntityManager.h"

//create scene --> draw sprites to scene --> draw scene to window --> Hurray!

class Renderer {
public:
    Renderer(sf::RenderWindow& window, AssetManager& assetManager, Scene& scene, EntityManager& em);
    ~Renderer();

    void renderToScene();
    void render();
    DebugMenu& getDebugMenu();

private:
    sf::RenderWindow& window;
    AssetManager& assetManager;
    Scene& scene;
    EntityManager& em;
    DebugMenu debugMenu;
};