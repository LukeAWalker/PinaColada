#ifndef _LEVEL_H_
    #define _LEVEL_H_

#include <SDL.h>

class Level {

    // Create a rectangle
    SDL_Rect rects[5];

public:
Level();
void draw (SDL_Renderer* renderer);

    //Renderer
 //  SDL_Renderer* renderer = SDL_CreateRenderer(MainWindow, -1, 0);


   //SDL_RenderPresent(renderer); // copy to screen

};

#endif
