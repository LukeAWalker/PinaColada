#include <SDL.h>
#include <level.hpp>
#include <iostream>


void Level::draw(SDL_Renderer* renderer) {
    int rc = 0;

    rc= SDL_RenderFillRects(renderer, rects, 5);

    if(rc!=0) {

        std::cout<<"GAH"<<SDL_GetError()<<"\n";
    }
}

Level::Level() {
    rects[0].x = 50;
    rects[0].y = 400;
    rects[0].w = 200;
    rects[0].h = 20;

    rects[1].x = 260;
    rects[1].y = 350;
    rects[1].w = 180;
    rects[1].h = 20;

    rects[2].x = 0;
    rects[2].y = 430;
    rects[2].w = 600;
    rects[2].h = 50;

    rects[3].x = 500;
    rects[3].y = 400;
    rects[3].w = 80;
    rects[3].h = 20;

    rects[4].x = 100;
    rects[4].y = 4;
    rects[4].w = 80;
    rects[4].h = 20;


}
