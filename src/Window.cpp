#include "Window.h"
#include <iostream>

Window::Window(unsigned int width, unsigned int height, const std::string& title, EntityManager& em)
    : window(sf::VideoMode({ width, height }), title, sf::Style::Titlebar | sf::Style::Close),
    assetManager(100),
    scene({ width, height }),
    renderer(window, assetManager, scene, em)
{
    window.setVerticalSyncEnabled(true);

    // init imgui
    if (!renderer.getDebugMenu().Init(&window)) {
        std::cout << "ImGui failed to start\n";
    }

    // load assets
    assetManager.loadTexture("appletex", "assets/AnimationSheet_Character.png", { 0,0 }, { 256,288 });
    Texture& tex = assetManager.getTexture("appletex");
    assetManager.loadSprite("apple", tex, { 0,0 }, { 32,32 });
    assetManager.loadSprite("goomba", tex, { 32,32 }, { 32,32 });
    assetManager.loadSprite("test", tex, { 32,32 }, { 32,32 });

    // bind controls
    input.bindAction("MoveUp", { InputType::Keyboard, {.key = sf::Keyboard::Scan::Up} });
    input.bindAction("MoveDown", { InputType::Keyboard, {.key = sf::Keyboard::Scan::Down} });
    input.bindAction("MoveRight", { InputType::Keyboard, {.key = sf::Keyboard::Scan::Right} });
    input.bindAction("MoveLeft", { InputType::Keyboard, {.key = sf::Keyboard::Scan::Left} });
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

void Window::processInput(EntityManager& em) {
    sf::Vector2f pos = em.getFirstEntityPosByTag("apple");
    if (input.isActionDown("MoveUp")) pos.y -= 1;
    if (input.isActionDown("MoveDown")) pos.y += 1;
    if (input.isActionDown("MoveRight")) pos.x += 1;
    if (input.isActionDown("MoveLeft")) pos.x -= 1;
    em.setEntityPosByTag("apple", pos);
}

void Window::render() {
    renderer.render();
}

sf::RenderWindow& Window::getRenderWindow() { return window; }
InputManager& Window::getInputManager() { return input; }
AssetManager& Window::getAssetManager() { return assetManager; }
Scene& Window::getScene() { return scene; }