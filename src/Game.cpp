#include "Game.h"

Game::Game()
    :  window(1200, 800, "test"), running(true) {
}

Game::~Game() {
}

void Game::runFrame() {
    if (window.isOpen()) {
        window.pollEvents();
        window.update();
        window.render();
    }
    else {
        running = false;
    }
}

bool Game::isRunning() const {
    return running;
}