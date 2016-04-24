#include <SDL.h>
#include <level.hpp>
#include <utils.hpp>
#include <iostream>


void Level::draw(SDL_Renderer* renderer) {

<<<<<<< Updated upstream
    rc= SDL_RenderFillRects(renderer, rects, 5);
=======

    for(int i = 0;i<rectslength;i++) {
        rects[i]->Render();
    }
}

Level::Level(SDL_Renderer* renderer) {
    SDL_Rect clipBase = {0,0,354,312};
    SDL_Rect clipPlatform = {0,0,600,300};
    Colour colour = {0,255,255,255};
    for(int i = 0; i<1;i++) {
        rects[i] = new Graphics_Object(renderer);
>>>>>>> Stashed changes

        rects[i]->Set_clip(clipBase);
        rects[i]->Create_texture_from_file("../../resources/base.png", &colour);

    }

    for(int i = 1; i<rectslength;i++) {
        rects[i] = new Graphics_Object(renderer);

        rects[i]->Set_clip(clipPlatform);
        rects[i]->Create_texture_from_file("../../resources/platform.png", &colour);

    }

    SDL_Point   positionBase = {0,430};
    SDL_Point   positionPlatform1 = {50,400};
    SDL_Point   positionPlatform2 = {260,350};
    SDL_Point   positionPlatform3 = {500,400};
    SDL_Point   positionPlatform4 = {100,4};
    SDL_Point   positionLeg1 = {80,420};
    SDL_Point   positionLeg2 = {210,420};
    SDL_Point   positionLeg3 = {290,370};
    SDL_Point   positionLeg4 = {400,370};
    SDL_Point   positionLeg5 = {510,420};
    SDL_Point   positionLeg6 = {570,420};

    SDL_Point   extentsBase = {600, 50};
    SDL_Point   extentsPlatform1 = {200, 20};
    SDL_Point   extentsPlatform2 = {180, 20};
    SDL_Point   extentsPlatform3 = {80, 20};
    SDL_Point   extentsPlatform4 = {80, 20};
    SDL_Point   extentsLeg1 = {10, 10};
    SDL_Point   extentsLeg2 = {10, 10};
    SDL_Point   extentsLeg3 = {10, 60};
    SDL_Point   extentsLeg4 = {10, 60};
    SDL_Point   extentsLeg5 = {5, 10};
    SDL_Point   extentsLeg6 = {5, 10};

    rects[0]->Set_screen_location(positionBase);
    rects[0]->Set_extents(extentsBase);

    rects[1]->Set_screen_location(positionPlatform1);
    rects[1]->Set_extents(extentsPlatform1);

    rects[2]->Set_screen_location(positionPlatform2);
    rects[2]->Set_extents(extentsPlatform2);

    rects[3]->Set_screen_location(positionPlatform3);
    rects[3]->Set_extents(extentsPlatform3);

    rects[4]->Set_screen_location(positionPlatform4);
    rects[4]->Set_extents(extentsPlatform4);

    rects[5]->Set_screen_location(positionLeg1);
    rects[5]->Set_extents(extentsLeg1);

    rects[6]->Set_screen_location(positionLeg2);
    rects[6]->Set_extents(extentsLeg2);

    rects[7]->Set_screen_location(positionLeg3);
    rects[7]->Set_extents(extentsLeg3);

    rects[8]->Set_screen_location(positionLeg4);
    rects[8]->Set_extents(extentsLeg4);

    rects[9]->Set_screen_location(positionLeg5);
    rects[9]->Set_extents(extentsLeg5);

    rects[10]->Set_screen_location(positionLeg6);
    rects[10]->Set_extents(extentsLeg6);


}
