//Linking the standard IO and SDL2 headers
#include <stdio.h>
#include </usr/include/SDL2/SDL.h>

//Screen dimensions 
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main( int argc, char* args[] ){
    
    //The window
    SDL_Window* window = NULL;

    //The surface of the screen
    SDL_Surface* screenSurface = NULL;

    //Init SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0){
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    }else{
        
        //Create the window
        window = SDL_CreateWindow("Mulle x Figge", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( window == NULL ){
            printf("Window is are belong to us");
        }
        
        //Get window surface
        screenSurface = SDL_GetWindowSurface( window );

        //Fill the surface with a color
        SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF) );

        //Get window to stay
        SDL_Event e; bool quit = false; while( quit == false ) { while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } }
    }

    //Destroy window
    SDL_DestroyWindow( window );

    //Quit SDL subsystems
    SDL_Quit();

    return 0;
}