#pragma once

#include <SFML/Graphics.hpp>

//Rendering texture where sprites are drawn to 
//think of it as the game world, where everything has a coordinate based on the game world


class Scene {
public:
    Scene(sf::Vector2u size);
    ~Scene();

    const sf::Texture& getScene();
    sf::Vector2u getSize() const;
    void clear();
    void draw(const sf::Drawable& drawable);
    void drawLine(const sf::Vector2f& p1, const sf::Vector2f& p2);
    void display();
    const sf::RenderTexture& getRaw() const;

private:
    sf::RenderTexture scene;
};