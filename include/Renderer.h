#pragma once

#include "AssetManager.h"
#include "Scene.h"
#include <imgui.h>
#include <imgui-SFML.h>

//create scene --> draw sprites to scene --> draw scene to window --> Hurray!

class Renderer {

public:
    
    Renderer(sf::RenderWindow& window, AssetManager& assetManager, Scene& scene);
    ~Renderer();

    void render();
private:

    sf::Clock        deltaClock{}; // for imgui::sfml::update
    sf::RenderWindow& window;
    AssetManager& assetManager;
    Scene& scene;
};