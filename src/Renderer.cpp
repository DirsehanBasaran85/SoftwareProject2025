#include "Renderer.h"
#include <iostream>

Renderer::Renderer(sf::RenderWindow& window, AssetManager& assetManager, Scene& scene)
    : window(window), assetManager(assetManager), scene(scene) {

  
}

Renderer::~Renderer() {
}

DebugMenu& Renderer::getDebugMenu() { return debugMenu; }

void Renderer::renderToScene() {

    scene.clear();

    for (const auto& entityPtr : scene.getEntities()) {

        const std::string& entityName = entityPtr->getTag();
        sf::Vector2f position = scene.getPosition(entityName);

        Sprite& spriteEntity = assetManager.getSprite(entityName);
        sf::Sprite sprite = spriteEntity.getRaw();
        sprite.setPosition(position);

        scene.draw(sprite);
    }

    debugMenu.Update(scene);

    scene.display();
}

void Renderer::render() {

    renderToScene();

    window.clear(); 

    sf::Sprite sceneSprite(scene.getScene());  
    window.draw(sceneSprite);

    debugMenu.Render(); // render imgui on top

    window.display(); 
}
