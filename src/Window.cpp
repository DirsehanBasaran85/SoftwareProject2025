#include "Window.h"

Window::Window(unsigned int width, unsigned int height , const std::string& title)
    : width(width), height(height), title(title)
{

    createWindow();
}

Window::~Window() {

}

void Window::run() {
    
    windowLoop();
}

void Window::createWindow() {
   
    window.create(sf::VideoMode({ width, height }), title);
}

void Window::windowLoop() {

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