#include "AssetManager.h"
#include <iostream>


AssetManager::AssetManager(std::size_t initialCapacity) {

    textures.reserve(initialCapacity);
    sprites.reserve(initialCapacity);
    fonts.reserve(initialCapacity);
}

void AssetManager::loadTexture(const std::string& name, const std::filesystem::path& filename,
    sf::Vector2u position, sf::Vector2u size, bool sRgb) {
    std::cout << "loading texture: " << name << std::endl;
    std::cout << "path: " << filename << std::endl;
    textures.emplace_back();
    Texture& textureRef = textures.back();
    if (!textureRef.loadFromFile(filename, position, size, sRgb)) {
        std::cerr << "Failed to load texture: " << filename << "\n";
    };
    textureNameToIndex[name] = textures.size() - 1;

}

Texture& AssetManager::getTexture(const std::string& name) {
    std::cout << "texture name: " << name << std::endl;
    std::cout <<"texture idx: " << textureNameToIndex.at(name) << std::endl;
    return textures[textureNameToIndex.at(name)];
}

void AssetManager::loadSprite(const std::string& name, const Texture& texture,
    sf::Vector2u position, sf::Vector2u size) {
    std::cout << "loading sprite name: " << name << std::endl;
    Sprite sprite(texture.getRaw(), position, size);
    sprites.push_back(sprite);
    spriteNameToIndex[name] = sprites.size() - 1;
}

Sprite& AssetManager::getSprite(const std::string& name) {

    return sprites[spriteNameToIndex.at(name)];
}

void AssetManager::loadFont(const std::string& name, const std::filesystem::path& filename) {

    Font font;
    font.loadFromFile(filename);
    fonts.push_back(font);
    fontNameToIndex[name] = fonts.size() - 1;
}

Font& AssetManager::getFont(const std::string& name) {

    return fonts[fontNameToIndex.at(name)];
}




