#ifndef game_hpp
#define game_hpp
#include <stdio.h>
#include <SDL2/SDL.h>

class Game {
    
public:
    Game();
    ~Game();

    void init(const char*, int xpos, int ypos, int width, int height, bool fullscreen);
    
    void handleEvents();
    void update();
    void render();
    void clean();

    bool running();

private:
    bool isRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;
};




#endif /* game_hpp */