#include "Window.h"
#include <iostream>

Window::Window(unsigned int width, unsigned int height, const std::string& title, EntityManager& em, InputManager& input)
    : window(sf::VideoMode({ width, height }), title, sf::Style::Titlebar | sf::Style::Close),
    assetManager(100),
    input(input),
    scene({ width, height }),
    renderer(window, assetManager, scene, em)
{
    window.setVerticalSyncEnabled(true);

    // init imgui
    if (!renderer.getDebugMenu().Init(&window)) {
        std::cout << "ImGui failed to start\n";
    }

    // load assets
    assetManager.loadTexture("gametex", "assets/tilesetfinal.png", { 0,0 }, { 256,288 });
    Texture& tex = assetManager.getTexture("gametex");
    assetManager.loadSprite("player", tex, { 0,0 }, { 32,32 });
    assetManager.loadSprite("enemy", tex, { 0,192 }, { 32,32 });

}

Window::~Window() {}

bool Window::isOpen() {
    return window.isOpen();
}

void Window::pollEvents() {
    input.beginFrame();
    while (const std::optional event = window.pollEvent()) {
        renderer.getDebugMenu().ProcessEvent(*event);
        if (event->is<sf::Event::Closed>())
            window.close();
        input.update(*event);
    }
}

void Window::render() {
    renderer.render();
}

sf::RenderWindow& Window::getRenderWindow() { return window; }
InputManager& Window::getInputManager() { return input; }
AssetManager& Window::getAssetManager() { return assetManager; }
Scene& Window::getScene() { return scene; }