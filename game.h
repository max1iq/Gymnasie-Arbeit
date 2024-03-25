#ifndef GAME_H
#define GAME_H

#include "object.h"
#include <SDL2/SDL.h>
#include <iostream>
#include "audio.h"
using namespace std;



class Game {
public:
    Game();
    ~Game();
    void loop();
    void update() {};
    void input();
    void render();
    void draw(Object o);
    void draw(const char* msg, int x, int y, int r, int g, int b);
    void mousePress(SDL_MouseButtonEvent& b);
private:
    SDL_Renderer* ren;
    SDL_Window* win;
    TTF_Font* font;
    bool running;
    int count;
    int frameCount, timerFPS, lastFrame, totalFrame;
    Object gojo;
    int mousex, mousey;
    int textx, texty;
    Audio effect;
    Audio peakygear;
    Audio peakygear2;
    int hasclicked;
};


#endif /* game_hpp */