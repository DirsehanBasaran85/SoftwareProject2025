#pragma once
#include "GameInterface.h"
#include <vector>


class  TestGame : public GameInterface {

public:
    explicit TestGame(World& world) : world(world) {
        init();
    };

    void init() override {

        // bind controls
        InputManager& im = world.getInputManager();
        im.bindAction("MoveUp", { InputType::Keyboard, {.key = sf::Keyboard::Scan::Up} });
        im.bindAction("MoveDown", { InputType::Keyboard, {.key = sf::Keyboard::Scan::Down} });
        im.bindAction("MoveRight", { InputType::Keyboard, {.key = sf::Keyboard::Scan::Right} });
        im.bindAction("MoveLeft", { InputType::Keyboard, {.key = sf::Keyboard::Scan::Left} });

        // create components
        TransformComponent playertransform({ 200,200 }, { 0.0f,0.0f }, { 1.0f,1.0f }, 0.0f);
        CollisionComponent playercollision({ 32,32 });

        TransformComponent enemytransform({ 300,300 }, { 0.0f,0.0f }, { 1.0f,1.0f }, 0.0f);
        CollisionComponent enemycollision({ 32,32 });

        TransformComponent enemy2transform({ 400,400 }, { 0.0f,0.0f }, { 1.0f,1.0f }, 0.0f);
        CollisionComponent enemy2collision({ 32,32 });

        // create entities
        EntityManager& em = world.getEntityManager();
        player = em.addEntityWithTag("player");
        enemy = em.addEntityWithTag("enemy");
        EntityPtr enemy2 = em.addEntityWithTag("enemy");
      

        // add components to entities
        em.AddComponentToEntity(player, playertransform, playercollision);
        em.AddComponentToEntity(enemy, enemytransform, enemycollision);
        em.AddComponentToEntity(enemy2, enemy2transform, enemy2collision);
        em.Update();
    }

    void update() override {

        // run game logic here
        InputManager& im = world.getInputManager();
        EntityManager& em = world.getEntityManager();

        sf::Vector2f pos = em.getEntityPosByID(0); // 0 is the player
        if (im.isActionDown("MoveUp")) pos.y -= 1;
        if (im.isActionDown("MoveDown")) pos.y += 1;
        if (im.isActionDown("MoveRight")) pos.x += 1;
        if (im.isActionDown("MoveLeft")) pos.x -= 1;
        em.setEntityPosByID(0, pos); // player is the first entity thats added, therefore it has id 0

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