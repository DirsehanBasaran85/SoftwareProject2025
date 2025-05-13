#include "Renderer.h"
#include <iostream>

Renderer::Renderer(sf::RenderWindow& window, AssetManager& assetManager, Scene& scene)
    : window(window), assetManager(assetManager), scene(scene) {

  
}

Renderer::~Renderer() {
}

DebugMenu& Renderer::getDebugMenu() { return debugMenu; }

void Renderer::render() {

   
    scene.clear();

    DebugMenu& debugMenu = getDebugMenu(); // use a reference to avoid uninitialized copy (it might crash without a ref)
    debugMenu.Update(scene);
    for (const auto& entityPtr : scene.getEntities()) {
        
        const std::string& entityName = entityPtr->getTag();
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

    debugMenu.Render(); // render imgui on top

    window.display(); 
}

