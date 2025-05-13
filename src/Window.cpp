#include "Window.h"
#include "Renderer.h"
#include <iostream>

Window::Window(unsigned int width, unsigned int height , const std::string& title)
    : width(width), height(height), title(title)
{
    createWindow();
    ImGui::SFML::Init(window);  // init imgui
}

Window::~Window() {
    ImGui::SFML::Shutdown();  //clean on exit
}

void Window::run() {
    
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
            
            if (event->is<sf::Event::Closed>())
                close();
        }

        clear();

        display();
    }
}