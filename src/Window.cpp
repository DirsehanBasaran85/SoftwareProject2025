#include "Window.h"
#include <iostream>

Window::Window(unsigned int width, unsigned int height, const std::string& title)
    : width(width), height(height), title(title),
    scene({ width, height }), assetManager(100), renderer(window, assetManager, scene) {

    createWindow();

    if (!renderer.getDebugMenu().Init(&window)) {
        std::cout << "ImGui failed to start\n";
    }

    assetManager.loadTexture("appletex", "assets/AnimationSheet_Character.png", { 0,0 }, { 256,288 });
    Texture& tex = assetManager.getTexture("appletex"); /// make sure the texture doesnt go out of scope, always use refs ! otherwise white boxes.
    assetManager.loadSprite("apple", tex, { 0,0 }, { 32,32 });
    assetManager.loadSprite("goomba", tex, { 32,32 }, { 32,32 });
    assetManager.loadSprite("test", tex, { 32,32 }, { 32,32 });

    scene.em.addInitializedEntityByTag("apple", { 570,400 });
    scene.em.addInitializedEntityByTag("goomba", { 300,300 });
    scene.em.AddComponents("test");
    scene.em.Update();

    input.bindAction("MoveUp", { InputType::Keyboard, {.key = sf::Keyboard::Scan::Up} });
    input.bindAction("MoveDown", { InputType::Keyboard, {.key = sf::Keyboard::Scan::Down} });
    input.bindAction("MoveRight", { InputType::Keyboard, {.key = sf::Keyboard::Scan::Right} });
    input.bindAction("MoveLeft", { InputType::Keyboard, {.key = sf::Keyboard::Scan::Left} });
}

Window::~Window() {
    ImGui::SFML::Shutdown();
}

void Window::createWindow() {
    window.create(sf::VideoMode({ width, height }), title, sf::Style::Titlebar | sf::Style::Close);
    window.setVerticalSyncEnabled(true);
}

void Window::pollEvents() {
    input.beginFrame();
    while (const std::optional event = window.pollEvent()) {
        renderer.getDebugMenu().ProcessEvent(*event);
        if (event->is<sf::Event::Closed>())
            close();
        input.update(*event);
    }
}

void Window::processInput() {
    if (input.isActionDown("MoveUp")) {
        sf::Vector2f pos = scene.em.getFirstEntityPosByTag("apple");
        pos.y -= 1;
        scene.em.setEntityPosByTag("apple", pos);
    }
    if (input.isActionDown("MoveDown")) {
        sf::Vector2f pos = scene.em.getFirstEntityPosByTag("apple");
        pos.y += 1;
        scene.em.setEntityPosByTag("apple", pos);
    }
    if (input.isActionDown("MoveRight")) {
        sf::Vector2f pos = scene.em.getFirstEntityPosByTag("apple");
        pos.x += 1;
        scene.em.setEntityPosByTag("apple", pos);
    }
    if (input.isActionDown("MoveLeft")) {
        sf::Vector2f pos = scene.em.getFirstEntityPosByTag("apple");
        pos.x -= 1;
        scene.em.setEntityPosByTag("apple", pos);
    }
}

void Window::update() {
    processInput();

    auto apple = scene.em.getFirstEntityByTag("apple");
    auto goomba = scene.em.getFirstEntityByTag("goomba");
    auto test = scene.em.getEntityByID(2);

    scene.csystem.resolveCollision(apple, goomba);
    scene.csystem.resolveCollision(apple, test);

    scene.em.Update();
}

void Window::render() {
    renderer.render();
}

bool Window::isOpen() const {
    return window.isOpen();
}

void Window::close() {
    window.close();
}