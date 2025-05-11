#pragma once

#include <SFML/Graphics.hpp>
#include <filesystem>

class Font {
public:
    Font();
    ~Font();

    // Load font from file
    void loadFromFile(const std::filesystem::path& filename);

    // Get the raw sf::Font object
    const sf::Font& getRaw() const;

private:
    sf::Font font;
};
