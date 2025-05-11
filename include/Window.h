#pragma once

#include <string>
#include <iostream>
#include <optional>

#include <SFML/Graphics.hpp>

class Window {

public:

    Window(unsigned int width = 800, unsigned int height = 600, const std::string& title = "Default");
    
    void run();

    inline bool isOpen() const { return window.isOpen(); }
    inline void clear() { window.clear(); }
    inline void display() { window.display(); }
    inline void close() { window.close(); }

private:

    sf::RenderWindow window;
    
    unsigned int width;
    unsigned int height;
    const std::string title;
    
    void createWindow();
    void windowLoop();

};