#pragma once
#include "GameInterface.h"
#include <vector>


class TestGame : public GameInterface {

public:

    void Init(World& world) override {
        // bind controls
        world.getInputManager().bindAction("MoveUp", {InputType::Keyboard, {.key = sf::Keyboard::Scan::Up}});
        world.getInputManager().bindAction("MoveDown", { InputType::Keyboard, {.key = sf::Keyboard::Scan::Down} });
        world.getInputManager().bindAction("MoveRight", { InputType::Keyboard, {.key = sf::Keyboard::Scan::Right} });
        world.getInputManager().bindAction("MoveLeft", { InputType::Keyboard, {.key = sf::Keyboard::Scan::Left} });
        // create entities
        world.getEntityManager().addInitializedEntityByTag("apple", {570,400});
        world.getEntityManager().addInitializedEntityByTag("goomba", { 300,300 });
        world.getEntityManager().AddComponents("test");
        world.getEntityManager().Update();

    }

    void Update(World& world) override {

        // run game logic here
        sf::Vector2f pos = world.getEntityManager().getFirstEntityPosByTag("apple");
        if (world.getInputManager().isActionDown("MoveUp")) pos.y -= 1;
        if (world.getInputManager().isActionDown("MoveDown")) pos.y += 1;
        if (world.getInputManager().isActionDown("MoveRight")) pos.x += 1;
        if (world.getInputManager().isActionDown("MoveLeft")) pos.x -= 1;
        world.getEntityManager().setEntityPosByTag("apple", pos);

    }

    void Shutdown(World& world) override {
        // clean up
    }

private:
    EntityPtr player; // for quick access maybe
    //std::vector<EntityPtr> enemies; // for quick access maybe
};