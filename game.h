#ifndef GAME_H
#define GAME_H

#include "object.h"
#include <SDL2/SDL.h>
#include <iostream>
using namespace std;



class Game {
public:
    Game();
    ~Game();
    void loop();
    void update() {};
    void input() {};
    void render();
    void draw(Object o);
    void draw(const char* msg, int x, int y, int r, int g, int b, int size);
private:
    SDL_Renderer* ren;
    SDL_Window* win;
    bool running;
    int count;
    int frameCount, timerFPS, lastFrame;
    Object gojo;
};


#endif /* game_hpp */