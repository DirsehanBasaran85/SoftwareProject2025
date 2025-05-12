#pragma once

#include <vector>
#include <unordered_map>
#include <string>
#include <filesystem> // std::filesystem::path
#include <memory> // std::move
#include <cstddef> // std:size_t

#include "Texture.h"
#include "Sprite.h"
#include "Font.h"    

//load textures --> assign textures to sprites --> render sprites!
//load fonts --> render fonts!
//use get functions with the textures/sprites/font name to get whichever texture/sprite/font you want to use!


class AssetManager {

public:
    
    AssetManager(std::size_t initialCapacity = 100);

    void loadTexture(const std::string& name, const std::filesystem::path& filename,
        sf::Vector2u position = { 0, 0 }, sf::Vector2u size = { 0, 0 }, bool sRgb = false);
    Texture& getTexture(const std::string& name);

    void loadSprite(const std::string& name, const Texture& texture,
        sf::Vector2u position = { 0, 0 }, sf::Vector2u size = { 0, 0 });
    Sprite& getSprite(const std::string& name);

    void loadFont(const std::string& name, const std::filesystem::path& filename);
    Font& getFont(const std::string& name);
private:
    //stores data
    std::vector<Texture> textures;
    std::vector<Sprite> sprites;
    std::vector<Font> fonts;

    //stores string names so its easier to work with the above vectors
    std::unordered_map<std::string, std::size_t> textureNameToIndex;
    std::unordered_map<std::string, std::size_t> spriteNameToIndex;
    std::unordered_map<std::string, std::size_t> fontNameToIndex;
};
