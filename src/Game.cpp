#include "Game.h"
#include <iostream>

Game::Game(unsigned int width, unsigned int height, const std::string& title)
    : window(sf::VideoMode({ width, height }), title, sf::Style::Titlebar | sf::Style::Close),
    assetManager(100),
    scene({ width, height }),
    renderer(window, assetManager, scene,entityManager),
    running(true)
{
    window.setVerticalSyncEnabled(true);

    if (!renderer.getDebugMenu().Init(&window)) {
        std::cout << "ImGui failed to start\n";
    }

    assetManager.loadTexture("appletex", "assets/AnimationSheet_Character.png", { 0,0 }, { 256,288 });
    Texture& tex = assetManager.getTexture("appletex");
    assetManager.loadSprite("apple", tex, { 0,0 }, { 32,32 });
    assetManager.loadSprite("goomba", tex, { 32,32 }, { 32,32 });
    assetManager.loadSprite("test", tex, { 32,32 }, { 32,32 });

    entityManager.addInitializedEntityByTag("apple", { 570,400 });
    entityManager.addInitializedEntityByTag("goomba", { 300,300 });
    entityManager.AddComponents("test");
    entityManager.Update();

    input.bindAction("MoveUp", { InputType::Keyboard, {.key = sf::Keyboard::Scan::Up} });
    input.bindAction("MoveDown", { InputType::Keyboard, {.key = sf::Keyboard::Scan::Down} });
    input.bindAction("MoveRight", { InputType::Keyboard, {.key = sf::Keyboard::Scan::Right} });
    input.bindAction("MoveLeft", { InputType::Keyboard, {.key = sf::Keyboard::Scan::Left} });
}

Game::~Game() {
    //ImGui::SFML::Shutdown(); not sure if i should put it here or debugmenu
}

void Game::pollEvents() {
    input.beginFrame();
    while (const std::optional event = window.pollEvent()) {
        renderer.getDebugMenu().ProcessEvent(*event);
        if (event->is<sf::Event::Closed>())
            window.close();
        input.update(*event);
    }
}

void Game::processInput() {
    sf::Vector2f pos = entityManager.getFirstEntityPosByTag("apple");
    if (input.isActionDown("MoveUp")) pos.y -= 1;
    if (input.isActionDown("MoveDown")) pos.y += 1;
    if (input.isActionDown("MoveRight")) pos.x += 1;
    if (input.isActionDown("MoveLeft")) pos.x -= 1;
    entityManager.setEntityPosByTag("apple", pos);
}

void Game::update() {
    processInput();

    auto apple = entityManager.getFirstEntityByTag("apple");
    auto goomba = entityManager.getFirstEntityByTag("goomba");
    auto test = entityManager.getEntityByID(2);

    collisionSystem.resolveCollision(apple, goomba);
    collisionSystem.resolveCollision(apple, test);

    entityManager.Update();
}

void Game::render() {
    renderer.render();
}

void Game::runFrame() {
    if (window.isOpen()) {
        pollEvents();
        update();
        render();
    }
    else {
        running = false;
    }
}

bool Game::isRunning() const {
    return running;
}
