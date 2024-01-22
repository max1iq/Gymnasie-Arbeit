//Linking the standard IO and SDL2 headers
#include "Game.hpp"

Game *game = nullptr;

int main(int argc, char * args[]) {

    game = new Game();
    
    game->init("Mulle x Figge", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, true);

    while (game->running()) {

        game->handleEvents();
        game->update();
        game->render();

    }

    game->clean();

    return 0;

}