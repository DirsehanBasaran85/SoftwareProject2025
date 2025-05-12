#pragma once

#include <filesystem>
#include <SFML/Graphics.hpp>

//Wrapper for sf::texture

class Texture {

public:
    
    Texture();
    ~Texture();

    sf::Vector2u getSize() const;
    bool isRepeated() const;
    bool isSmooth() const;
    bool isSrgb() const;

    void setRepeated(bool state);
    void setSmoothness(bool state);

    bool loadFromFile(
        const std::filesystem::path& filename,
        sf::Vector2u position = { 0, 0 },
        sf::Vector2u size = { 0, 0 },
        bool sRgb = false
    );

    const sf::Texture& getRaw() const;
private:

    sf::Texture texture;
};
