#pragma once
#include "GameInterface.h"
#include <vector>


class TestGame : public GameInterface {

public:
    explicit TestGame(World& world) : world(world) {
        init();
    };

    void init() override {
        
        // bind controls
        world.getInputManager().bindAction("MoveUp", {InputType::Keyboard, {.key = sf::Keyboard::Scan::Up}});
        world.getInputManager().bindAction("MoveDown", { InputType::Keyboard, {.key = sf::Keyboard::Scan::Down} });
        world.getInputManager().bindAction("MoveRight", { InputType::Keyboard, {.key = sf::Keyboard::Scan::Right} });
        world.getInputManager().bindAction("MoveLeft", { InputType::Keyboard, {.key = sf::Keyboard::Scan::Left} });
        
        // create components
        TransformComponent playertransform({ 200,200 }, { 0.0f,0.0f }, { 1.0f,1.0f }, 0.0f);
        CollisionComponent playercollision({ 32,32 });

        TransformComponent enemytransform({ 300,300 }, { 0.0f,0.0f }, { 1.0f,1.0f }, 0.0f);
        CollisionComponent enemycollision({ 32,32 });
        
        // create entities
        player = world.getEntityManager().addEntityByTag("player");
        enemy = world.getEntityManager().addEntityByTag("enemy");

        // add components to entities
        world.getEntityManager().AddComponentToEntity(player, playertransform, playercollision);
        world.getEntityManager().AddComponentToEntity(enemy, enemytransform, enemycollision);
        world.getEntityManager().Update();

    }

    void update() override {

        // run game logic here
        sf::Vector2f pos = world.getEntityManager().getFirstEntityPosByTag("player");
        if (world.getInputManager().isActionDown("MoveUp")) pos.y -= 1;
        if (world.getInputManager().isActionDown("MoveDown")) pos.y += 1;
        if (world.getInputManager().isActionDown("MoveRight")) pos.x += 1;
        if (world.getInputManager().isActionDown("MoveLeft")) pos.x -= 1;
        world.getEntityManager().setEntityPosByTag("player", pos);

    }

    void shutdown() override {
        // clean up
    }

private:
    World& world;
    EntityPtr player;
    EntityPtr enemy;
    //std::vector<EntityPtr> enemies; // for quick access maybe
};