#pragma once

#include "AssetManager.h"
#include "Scene.h"
#include "InputManager.h"
#include "Renderer.h"
#include "EntityManager.h"
#include "DebugMenu.h"
#include <SFML/Graphics.hpp>
#include <string>

class Window {
public:
    Window(unsigned int width, unsigned int height, const std::string& title, EntityManager& em, InputManager& input);
    ~Window();

    bool isOpen();
    void pollEvents();
    void render();

    sf::RenderWindow& getRenderWindow();
    InputManager& getInputManager();
    AssetManager& getAssetManager();
    Scene& getScene();

private:
    sf::RenderWindow window;
    InputManager& input;
    AssetManager assetManager;
    Scene scene;
    Renderer renderer;
};