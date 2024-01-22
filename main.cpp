//Linking the standard IO and SDL2 headers
#include <iostream>
#include <stdio.h>
#include <SDL2/SDL.h>

//Screen dimensions 
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(){
    
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow("Mulle x Figge", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    SDL_RenderPresent(renderer);

    SDL_Delay(3000);

}