#include <SDL2/SDL.h>
#include <level.hpp>
#include <iostream>


void Level::draw(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    SDL_RenderClear(renderer); // fill the scene with white

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // the rect color (solid red)
    SDL_RenderFillRect(renderer, &r);
}

Level::Level() {
    r.x = 50;
    r.y = 50;
    r.w = 50;
    r.h = 50;
}
