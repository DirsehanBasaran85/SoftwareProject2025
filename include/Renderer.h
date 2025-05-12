#pragma once

#include "AssetManager.h"
#include "Scene.h"

//create scene --> draw sprites to scene --> draw scene to window --> Hurray!

class Renderer {

public:
    
    Renderer(sf::RenderWindow& window, AssetManager& assetManager, Scene& scene);

    void render();
private:

    sf::RenderWindow& window;
    AssetManager& assetManager;
    Scene& scene;
};