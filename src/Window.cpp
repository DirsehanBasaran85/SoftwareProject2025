#include "Window.h"
#include "Renderer.h"
#include <iostream>

Window::Window(unsigned int width, unsigned int height, const std::string& title)
    : width(width), height(height), title(title), scene({ width,height }), assetManager(100), renderer(window, assetManager, scene)
{
    createWindow();
    if (!renderer.getDebugMenu().Init(&window)) { // init imgui
        std::cout << "ImGui failed to start";
    }
}

Window::~Window() {
}

void Window::run() {

    assetManager.loadTexture("appletex", "assets/AnimationSheet_Character.png", { 0,0 }, { 256,288 });
    Texture tex = assetManager.getTexture("appletex");
    assetManager.loadSprite("apple", tex, { 0,0 }, { 32,32 });
    assetManager.loadSprite("goomba", tex, { 32,32 }, { 32,32 });

    scene.addEntity("apple", { 570,400 });
    scene.addEntity("goomba", { 300,300 });

    scene.update();

    // Bind actions
    input.bindAction("MoveUp", { InputType::Keyboard, {.key = sf::Keyboard::Scan::Up} });
    input.bindAction("MoveDown", { InputType::Keyboard, {.key = sf::Keyboard::Scan::Down} });
    input.bindAction("MoveRight", { InputType::Keyboard, {.key = sf::Keyboard::Scan::Right} });
    input.bindAction("MoveLeft", { InputType::Keyboard, {.key = sf::Keyboard::Scan::Left} });

    windowLoop();
}

void Window::createWindow() {

    window.create(sf::VideoMode({ width, height }), title, sf::Style::Titlebar | sf::Style::Close);
    window.setVerticalSyncEnabled(true);
}

void Window::checkInput() {

    if (input.isActionDown("MoveUp")) {
        sf::Vector2f coordinates = scene.getPosition("apple");
        coordinates.y -= 1;
        scene.setPosition("apple", coordinates);
    }

    if (input.isActionDown("MoveDown")) {
        sf::Vector2f coordinates = scene.getPosition("apple");
        coordinates.y += 1;
        scene.setPosition("apple", coordinates);
    }

    if (input.isActionDown("MoveRight")) {
        sf::Vector2f coordinates = scene.getPosition("apple");
        coordinates.x += 1;
        scene.setPosition("apple", coordinates);
    }

    if (input.isActionDown("MoveLeft")) {
        sf::Vector2f coordinates = scene.getPosition("apple");
        coordinates.x -= 1;
        scene.setPosition("apple", coordinates);
    }

}

void Window::windowLoop() {

    while (isOpen())
    {

        input.beginFrame();
        while (const std::optional event = window.pollEvent())
        {
            renderer.getDebugMenu().ProcessEvent(*event); // feed imgui

            if (event->is<sf::Event::Closed>())
                close();
            
            input.update(*event);
            // Check actions

        }

        checkInput();

        renderer.render();
    }
}