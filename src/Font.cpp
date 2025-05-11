#include "Font.h"

Font::Font() {

}

Font::~Font() {

}

void Font::loadFromFile(const std::filesystem::path& filename) {
    
    if (!font.openFromFile(filename)) {
       //Error handling here
    }
}

const sf::Font& Font::getRaw() const {
    
    return font;
}
