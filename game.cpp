#include "game.h"

Game::Game() {
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_CreateWindowAndRenderer(1280, 720, 0, &win, &ren);
    SDL_SetWindowTitle(win, "Gymnasie-Arbeit");
    TTF_Init();
    running = true;
    count = 0;
    gojo.setDest(0, 0, 1280, 720);
    gojo.setSource(0, 0, 1280, 720);
    gojo.setImage("image2.png", ren);
    font = TTF_OpenFont("CC_Roman_Worlds.ttf", 50);
    peakygear.load("peakygear.wav");
    peakygear2.load("perfection.wav");
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

    }

    //cout << mousex << ", " << mousey << "\n";

    render();
    input();
    update();
    }
}

void Game::render() {
    SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
    SDL_Rect rect;
    rect.x=rect.y=0;
    rect.w=1280;
    rect.h=720;
    SDL_RenderFillRect(ren, &rect);
    if(hasclicked >= 1 && totalFrame >= 5) {
        draw(gojo);
    }
    draw("Ship", textx, texty, 0, 0, 0);
    frameCount++;
    totalFrame++;
    if(totalFrame < 5) {
        hasclicked = 0;
        std::cout << totalFrame << "\n";
    }
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

void Game::draw(const char* msg, int x, int y, int r, int g, int b) {
    SDL_Surface* surf;
    SDL_Texture* tex;
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

void Game::mousePress(SDL_MouseButtonEvent& b) {
    std::cout << hasclicked << "\n";
    if(b.button == SDL_BUTTON_LEFT){
        if(mousex > 640) {
        peakygear.play();
        std::cout << "mousedown left\n";
        hasclicked++;
        }
        if(mousex < 640) {
        peakygear2.play();
        std::cout << "lol mousedown left\n";
        hasclicked++;
        }
    }    
}


void Game::input() {
    SDL_Event e;
    while(SDL_PollEvent(&e)) {
        switch(e.type){
            case SDL_QUIT:
                running = false;
                break;
            case SDL_MOUSEBUTTONDOWN:
                //do whatever you want to do after a mouse button was pressed,
                // e.g.:
                mousePress(e.button);
                break;
                

        }            
        if(e.type == SDL_QUIT) {running = false; cout << "Quitting\n";}
        if(e.type == SDL_KEYDOWN) {
            if(e.key.keysym.sym == SDLK_ESCAPE) {running = false;}
            if(e.key.keysym.sym == SDLK_w) {cout << "w down\n"; peakygear2.play();}
            if(e.key.keysym.sym == SDLK_s) {cout << "s down\n"; peakygear.play();}
            if(e.key.keysym.sym == SDLK_DOWN) {cout << "arrow down\n"; texty = texty + 8;}
            if(e.key.keysym.sym == SDLK_UP) {cout << "arrow up\n"; texty = texty - 8;}
            if(e.key.keysym.sym == SDLK_LEFT) {cout << "arrow left\n"; textx = textx - 8;}
            if(e.key.keysym.sym == SDLK_RIGHT) {cout << "arrow right\n"; textx = textx + 8;}
            
        }
        if(e.type == SDL_KEYUP) {
            if(e.key.keysym.sym == SDLK_w) {cout << "w up\n";}
            if(e.key.keysym.sym == SDLK_s) {cout << "s up\n";}
        }
        SDL_GetMouseState(&mousex, &mousey);
    }
    
}
