#pragma once

#include <string>
#include <iostream>
#include <optional>

#include <SFML/Graphics.hpp>

#include "Renderer.h"

//System that handles window operations and also event handling later

class Window {

public:
   
    Window(unsigned int width = 800, unsigned int height = 600, const std::string& title = "Default");
    ~Window();

    void run();

    inline bool isOpen() const { return window.isOpen(); }
    inline void clear(sf::Color color = sf::Color::Black) { window.clear(color); }
    inline void display() { window.display(); }
    inline void close() { window.close(); }
private:
    
    sf::RenderWindow window;
    
    unsigned int width;
    unsigned int height;
    const std::string title;
    
    AssetManager assetManager;
    Scene scene;
    Renderer renderer;

    void createWindow();
    void windowLoop();
};