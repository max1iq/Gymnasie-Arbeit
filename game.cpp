#include "game.h"

Game::Game() {
    SDL_Init(0);
    SDL_CreateWindowAndRenderer(1280, 720, 0, &win, &ren);
    SDL_SetWindowTitle(win, "Mulle x Figge!!!!");
    TTF_Init();
    running = true;
    count = 0;
    gojo.setDest(0, 0, 1280, 720);
    gojo.setSource(0, 0, 2560, 1440);
    gojo.setImage("image.png", ren);
    loop();
}

Game::~Game() {
    TTF_Quit();
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
}

void Game::loop() {
    while(running){
    
    lastFrame = SDL_GetTicks();
    static int lastTime;
    if(lastFrame >= (lastTime+1000)) {
        lastTime = lastFrame;
        frameCount = 0;
        count++;
    }

    render();
    input();
    update();

    if(count > 3) running = false;
    }
}

void Game::render() {
    SDL_SetRenderDrawColor(ren, 255, 0, 0, 255);
    SDL_Rect rect;
    rect.x=rect.y=0;
    rect.w=1280;
    rect.h=720;
    SDL_RenderFillRect(ren, &rect);

    draw(gojo);
    draw("I'd Win", 20, 30, 0, 0, 0, 60);

    frameCount++;
    int timerFPS = SDL_GetTicks()-lastFrame;
    if(timerFPS<(1000/60)) {
        SDL_Delay((1000/60)-timerFPS);
    }

    SDL_RenderPresent(ren);
}


void Game::draw(Object o) {
    SDL_Rect dest = o.getDest();
    SDL_Rect src = o.getSource();
    SDL_RenderCopyEx(ren, o.getTex(), &src, &dest, 0, NULL, SDL_FLIP_NONE);
}

void Game::draw(const char* msg, int x, int y, int r, int g, int b, int size) {
    SDL_Surface* surf;
    SDL_Texture* tex;
    TTF_Font *font = TTF_OpenFont("Sans.ttf", size);
    SDL_Color color;
    color.r=r;
    color.g=g;
    color.b=b;
    color.a=255;
    SDL_Rect rect;
    surf = TTF_RenderText_Solid(font, msg, color);
    tex = SDL_CreateTextureFromSurface(ren, surf);
    rect.x=x;
    rect.y=y;
    rect.w=surf->w;
    rect.h=surf->h;
    SDL_FreeSurface(surf);
    SDL_RenderCopy(ren, tex, NULL, &rect);
    SDL_DestroyTexture(tex);
}