#include "Renderer.h"
#include <iostream>

Renderer::Renderer(sf::RenderWindow& window, AssetManager& assetManager, Scene& scene)
    : window(window), assetManager(assetManager), scene(scene) {

}

void Renderer::render() {
    
    scene.clear();

    for (const auto& entityPair : scene.getEntities()) {
        
        const std::string& entityName = entityPair.first;
        sf::Vector2f position = scene.getPosition(entityName);

        // Debug
       // std::cout << "Rendering entity: " << entityName << " at (" << position.x << ", " << position.y << ")\n";

        Sprite& spriteEntity = assetManager.getSprite(entityName);
        sf::Sprite sprite = spriteEntity.getRaw();
        sprite.setPosition(position);

        scene.draw(sprite); 
    }

    scene.display();  
    window.clear(); 
    sf::Sprite sceneSprite(scene.getRaw().getTexture());  
    window.draw(sceneSprite);  
    window.display(); 
}

