#include "Application.h"
#include <SFML/Graphics.hpp>

int main() {

    Application app;
    while (app.isRunning()) {
       
        //Input System, Renderer System, Sound System etc.
        app.run(); 
    }

    return 0;
}