#include "Window.h"
#include "Renderer.h"
#include <iostream>

Window::Window(unsigned int width, unsigned int height , const std::string& title)
    : width(width), height(height), title(title)
{
    createWindow();
    if (!ImGui::SFML::Init(window)) { // init imgui
        std::cout << "ImGui failed to start";
    }
}

Window::~Window() {
   ImGui::SFML::Shutdown(); // clean up
}

void Window::run() {

    assetManager.loadTexture("appletex", "assets/AnimationSheet_Character.png", { 0,0 }, { 256,288 });
    Texture tex = assetManager.getTexture("appletex");
    assetManager.loadSprite("apple", tex, { 0,0 }, { 32,32 });
    scene.addEntity("apple",{570,400});
    
    
    windowLoop();
}

void Window::createWindow() {

    window.create(sf::VideoMode({ width, height }), title,sf::Style::Titlebar | sf::Style::Close);
    window.setVerticalSyncEnabled(true);
}

void Window::windowLoop() {
    while (isOpen()) {

    while (isOpen())
    {
        
        while (const std::optional event = window.pollEvent())
        {
            ImGui::SFML::ProcessEvent(window, *event); // feed imgui
            
            if (event->is<sf::Event::Closed>())
                close();
        }

        clear();

        display();
    }
}