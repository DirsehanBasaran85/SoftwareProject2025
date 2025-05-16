#pragma once

#include <SFML/Graphics.hpp>
#include <optional>
#include <string>

#include "Renderer.h"
#include "InputManager.h"
#include "AssetManager.h"
#include "Scene.h"

class Window {
public:
    Window(unsigned int width = 800, unsigned int height = 600, const std::string& title = "Default");
    ~Window();

    void pollEvents();      // process input events
    void update();          // logic like input & game updates
    void render();          // calls renderer

    bool isOpen() const;
    void close();

private:
    sf::RenderWindow window;
    unsigned int width;
    unsigned int height;
    const std::string title;

    InputManager input;
    AssetManager assetManager;
    Scene scene;
    Renderer renderer;

    void createWindow();
    void processInput();
};