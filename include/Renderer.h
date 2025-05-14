#pragma once

#include "DebugMenu.h"
#include "AssetManager.h"
#include "Scene.h"


//create scene --> draw sprites to scene --> draw scene to window --> Hurray!

class Renderer {

public:

    Renderer(sf::RenderWindow& window, AssetManager& assetManager, Scene& scene);
    ~Renderer();

    void renderToScene();
    void render();
    DebugMenu& getDebugMenu();

private:
    sf::RenderWindow& window;
    AssetManager& assetManager;
    Scene& scene;
    DebugMenu debugMenu;
};