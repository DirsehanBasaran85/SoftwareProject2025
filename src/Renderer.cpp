#include "Renderer.h"
#include <iostream>

Renderer::Renderer(sf::RenderWindow& window, AssetManager& assetManager, Scene& scene)
    : window(window), assetManager(assetManager), scene(scene) {
    
}

Renderer::~Renderer() {
}

void Renderer::render() {

    ImGui::SFML::Update(window, deltaClock.restart()); // new imgui frame


    // builds imgui stats window
    ImGui::Begin("Stats");
    ImGui::Text("FPS: %.1f", ImGui::GetIO().Framerate);
    ImGui::End();
    
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

    ImGui::SFML::Render(window); // render imgui on top

    window.display(); 
}

