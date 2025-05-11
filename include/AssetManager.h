#pragma once

#include <vector>
#include <unordered_map>
#include <string>
#include <filesystem> // std::filesystem::path
#include <memory> // std::move

#include "Texture.h"
//#include "Sprite.h"
#include "Font.h"    



class AssetManager {

public:
    AssetManager(std::size_t initialCapacity = 100);

    void loadTexture(const std::string& name, const std::filesystem::path& filename,
        sf::Vector2u position = { 0, 0 }, sf::Vector2u size = { 0, 0 }, bool sRgb = false);

    Texture& getTexture(const std::string& name);

    //void loadSprite(const std::string& name, const Texture& texture);

    //Sprite& getSprite(const std::string& name);

    void loadFont(const std::string& name, const std::filesystem::path& filename);

    Font& getFont(const std::string& name);

private:
    std::vector<Texture> textures;
    //std::vector<Sprite> sprites;
    std::vector<Font> fonts;

    std::unordered_map<std::string, std::size_t> textureNameToIndex;
    //std::unordered_map<std::string, std::size_t> spriteNameToIndex;
    std::unordered_map<std::string, std::size_t> fontNameToIndex;
};
