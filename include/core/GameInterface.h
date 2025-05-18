#pragma once

#include "World.h"

// The game we want to run uses this interface to initialize and run itself 

class GameInterface {

public:
    virtual void Init(World& world) = 0;
    virtual void Update(World& world) = 0;
    virtual void Shutdown(World& world) = 0;
};