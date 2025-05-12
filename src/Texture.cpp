#include "Texture.h"

Texture::Texture() {

}

Texture::~Texture() {

}

sf::Vector2u Texture::getSize() const {
    
    return texture.getSize();
}

bool Texture::isRepeated() const {
    
    return texture.isRepeated();
}

bool Texture::isSmooth() const {
    
    return texture.isSmooth();
}

bool Texture::isSrgb() const {
    
    return texture.isSrgb();
}

void Texture::setRepeated(bool state) {
   
    texture.setRepeated(state);
}

void Texture::setSmoothness(bool state) {
    
    texture.setSmooth(state);
}

bool Texture::loadFromFile(
    const std::filesystem::path& filename,
    sf::Vector2u position,
    sf::Vector2u size,
    bool sRgb
) {
    
    if (!texture.loadFromFile(filename.string())) {
        return false;
    }
    texture.setRepeated(false);
    texture.setSmooth(false);
    return true;
}

const sf::Texture& Texture::getRaw() const {
    
    return texture;
}
