#pragma once

#include <string>
#include <iostream>
#include <optional>

#include <SFML/Graphics.hpp>
#include <imgui.h>
#include <imgui-SFML.h>

//System that handles window operations and also event handling later

//System that handles window operations and also event handling later

class Window {

public:
   
    Window(unsigned int width = 800, unsigned int height = 600, const std::string& title = "Default");
    ~Window();

    void run();

    inline bool isOpen() const { return window.isOpen(); }
    inline void clear() { window.clear(); }
    inline void display() { window.display(); }
    inline void close() { window.close(); }
private:
    
    sf::RenderWindow window;
    sf::Clock        deltaClock{}; // for imgui::sfml::update

    unsigned int width;
    unsigned int height;
    const std::string title;

    void createWindow();
    void windowLoop();
};