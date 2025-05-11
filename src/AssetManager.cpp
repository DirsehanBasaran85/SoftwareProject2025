#include "AssetManager.h"

AssetManager::AssetManager(std::size_t initialCapacity) {
    textures.reserve(initialCapacity);  
    //sprites.reserve(initialCapacity); 
    fonts.reserve(initialCapacity);
}

void AssetManager::loadTexture(const std::string& name, const std::filesystem::path& filename,
    sf::Vector2u position, sf::Vector2u size, bool sRgb) {

    //create and load texture from file
    Texture texture;
    texture.loadFromFile(filename, position, size, sRgb);
    textures.push_back(texture);  
    textureNameToIndex[name] = textures.size() - 1; 
}

Texture& AssetManager::getTexture(const std::string& name) {
    //retrieve texture by its name using the map
    return textures[textureNameToIndex.at(name)];
}

//void AssetManager::loadSprite(const std::string& name, const Texture& texture) {
    // Create sprite and set its texture
    //Sprite sprite(texture.getRaw());
    //sprites.push_back(sprite);  // Add sprite to the vector
    //spriteNameToIndex[name] = sprites.size() - 1;  // Map name to index
//}

//Sprite& AssetManager::getSprite(const std::string& name) {
    // Retrieve sprite by its name using the map
    //return sprites[spriteNameToIndex.at(name)];
//}

void AssetManager::loadFont(const std::string& name, const std::filesystem::path& filename) {
    // Create and load font from file
    Font font;
    font.loadFromFile(filename);
    fonts.push_back(font);  // Add font to the vector
    fontNameToIndex[name] = fonts.size() - 1;  // Map name to index
}

Font& AssetManager::getFont(const std::string& name) {
    // Retrieve font by its name using the map
    return fonts[fontNameToIndex.at(name)];
}




