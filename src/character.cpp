/*******************************************************************************

Title:      character.cpp
Author:     Luke
Date:       23/04/2016

Description:

  Contains method definitions for the Character class.

*******************************************************************************/

/*INCLUDES*********************************************************************/

#include "character.hpp"
#include <SDL.h>
#include <graphics.hpp>
#include <utils.hpp>

/*DEFINES**********************************************************************/

/*GLOBAL VARIABLES*************************************************************/

/*MAIN CODE BODY***************************************************************/

Character::Character(SDL_Renderer* renderer) {
    //Create graphics object
    sprite = new Graphics_Object(renderer);

    //Set character position, extents and speed
    position.x = 0;
    position.y = 0;
    size.x = 50;
    size.y = 100;
    speed.x = 0;
    speed.y = 0;

    //At this point, we know the graphics object has these parameters
    //TODO: may want to change these later to actual setup code
    Colour temp_col = {0x00,0xFF,0xFF,0xFF};
    sprite->Create_texture_from_file("main_char.png",&temp_col);
    sprite->Set_screen_location(position);
    sprite->Set_extents(size);
    SDL_Rect clip_area = {0,0,100,100};
    sprite->Set_clip(clip_area);
}
