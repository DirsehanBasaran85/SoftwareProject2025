#include "Scene.h"
#include <stdexcept>

Scene::Scene(sf::Vector2u size) : scene(size) {

}

Scene::~Scene() {}

const sf::Texture& Scene::getScene() {
    return scene.getTexture();
}

sf::Vector2u Scene::getSize() const {

    return scene.getSize();
}

void Scene::clear() {

    scene.clear();
}

void Scene::draw(const sf::Drawable& drawable) {

    scene.draw(drawable);
}

void Scene::drawLine(const sf::Vector2f& p1, const sf::Vector2f& p2) 
{
    sf::VertexArray line(sf::PrimitiveType::LineStrip, 2);

    line[0].position = sf::Vector2f(p1.x, p1.y);
    line[1].position = sf::Vector2f(p2.x, p2.y);

    this->draw(line);
}

void Scene::display() {

    scene.display();
}


const sf::RenderTexture& Scene::getRaw() const {

    return scene;
}

