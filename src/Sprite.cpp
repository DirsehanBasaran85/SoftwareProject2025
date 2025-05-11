#include "Sprite.h"

Sprite::Sprite(const sf::Texture& texture) : sprite(texture) {

}

Sprite::~Sprite() {

}

void Sprite::setTexture(const sf::Texture& texture) {

    sprite.setTexture(texture);
}

sf::Vector2u Sprite::getSize() const {

    return sprite.getTexture().getSize();
}

void Sprite::setPosition(const sf::Vector2f& position) {

    sprite.setPosition(position);
}

sf::Vector2f Sprite::getPosition() const {

    return sprite.getPosition();
}

const sf::Sprite& Sprite::getRaw() const {

    return sprite;
}