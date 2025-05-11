#pragma once

#include <SFML/Graphics.hpp>
#include <filesystem>

//Wrapper for sf::font

class Font {
public:
   
    Font();
    ~Font();

    void loadFromFile(const std::filesystem::path& filename);

    const sf::Font& getRaw() const;
private:
    
    sf::Font font;
};
