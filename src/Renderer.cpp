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

    for (const auto& entityPtr : scene.em.getEntities()) {

        const std::string& entityName = entityPtr->getTag();
        sf::Vector2f position = scene.em.getFirstEntityPosByTag(entityName);

        Sprite& spriteEntity = assetManager.getSprite(entityName);
        sf::Sprite sprite = spriteEntity.getRaw();
        sprite.setPosition(position);

        if (debugMenu.showCollisions) {     
            if (entityPtr->hasComponent<CollisionComponent>()) {
                auto& box = entityPtr->getComponent<CollisionComponent>();
                auto& tc = entityPtr->getComponent<TransformComponent>();
                sf::RectangleShape rect;
                rect.setSize(sf::Vector2f(box.size.x, box.size.y));
                rect.setOrigin(sf::Vector2f(0.0f, 0.0f));
                rect.setPosition(sf::Vector2f(tc.position.x, tc.position.y));
                rect.setFillColor(sf::Color(0, 0, 0, 0));
                rect.setOutlineColor(sf::Color(255, 255, 255, 255));
                rect.setOutlineThickness(1);
                scene.draw(rect);
            }
        
        }
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