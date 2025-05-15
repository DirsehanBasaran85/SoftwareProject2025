#include "Sprite.h"

Sprite::Sprite(const sf::Texture& texture, sf::Vector2u position, sf::Vector2u size) : sprite(texture) {

    setTexture(texture, position, size);
}

Sprite::~Sprite() {

}

void Sprite::setTexture(const sf::Texture& texture, sf::Vector2u position, sf::Vector2u size) {

    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect({ static_cast<int>(position.x),static_cast<int>(position.y) }, { static_cast<int>(size.x), static_cast<int>(size.y) }));
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
