#pragma once

#include "World.h"

// The game we want to run uses this interface to initialize and run itself 

class GameInterface {

public:
    virtual void init() = 0;
    virtual void update() = 0;
    virtual void shutdown() = 0;
};