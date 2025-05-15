#pragma once

#include <SFML/Graphics.hpp>

//Wrapper for sf::sprite

class Sprite {

public:

    Sprite(const sf::Texture& texture, sf::Vector2u position = { 0, 0 }, sf::Vector2u size = { 0, 0 });
    ~Sprite();

    void setTexture(const sf::Texture& texture, sf::Vector2u position = { 0, 0 }, sf::Vector2u size = { 0, 0 });

    sf::Vector2u getSize() const;

    void setPosition(const sf::Vector2f& position);
    sf::Vector2f getPosition() const;

    const sf::Sprite& getRaw() const;
private:

    sf::Sprite sprite;
};

