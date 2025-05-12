#include "Window.h"
#include "Renderer.h"
#include <iostream>

Window::Window(unsigned int width, unsigned int height , const std::string& title)
    : width(width), height(height), title(title), scene({width,height}), assetManager(100), renderer(window, assetManager, scene)
{
    createWindow();
}

Window::~Window() {

}

void Window::run() {

    assetManager.loadTexture("appletex", "assets/AnimationSheet_Character.png", { 0,0 }, { 256,288 });
    Texture tex = assetManager.getTexture("appletex");
    assetManager.loadSprite("apple", tex, { 0,0 }, { 32,32 });
    scene.addEntity("apple",{570,400});
    
    
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
            else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
            {

                if (keyPressed->scancode == sf::Keyboard::Scancode::Escape) {
                    
                    //window.close();
                    sf::Vector2f debugtest = scene.getPosition("apple");
                    std::cout <<debugtest.x<<std::endl;
                    std::cout << debugtest.y << std::endl;
                }

                if (keyPressed->scancode == sf::Keyboard::Scancode::Up) {
                    
                    sf::Vector2f coordinates = scene.getPosition("apple");
                    coordinates.y -= 10;
                    scene.setPosition("apple", coordinates);
                }

                if (keyPressed->scancode == sf::Keyboard::Scancode::Down) {
                    
                    sf::Vector2f coordinates = scene.getPosition("apple");
                    coordinates.y += 10;
                    scene.setPosition("apple", coordinates);
                }

                if (keyPressed->scancode == sf::Keyboard::Scancode::Left) {
                   
                    sf::Vector2f coordinates = scene.getPosition("apple");
                    coordinates.x -= 10;
                    scene.setPosition("apple", coordinates);
                }

                if (keyPressed->scancode == sf::Keyboard::Scancode::Right) {

                    sf::Vector2f coordinates = scene.getPosition("apple");
                    coordinates.x += 10;
                    scene.setPosition("apple", coordinates);
                }
                    
            }
        }
        


        renderer.render();

    }
}