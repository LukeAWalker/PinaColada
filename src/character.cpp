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

#define GRAVITY 1

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
    state = CHARACTER_STATE_AERIAL;
}

Character::~Character() {
    delete sprite;
}


/**
 * Character::handle_event
 *
 * See character.hpp
 */
void
Character::handle_event(SDL_Event *e)
{
    if (e->type == SDL_KEYDOWN) {
        switch (e->key.keysym.sym) {

        case SDLK_UP:
            if (state == CHARACTER_STATE_GROUNDED) {
                speed.y = -25;
                state = CHARACTER_STATE_AERIAL;
            }
            break;

        case SDLK_LEFT:
            speed.x = -10;
            break;

        case SDLK_RIGHT:
            speed.x = 10;
            break;

        default:
            /**
            * Don't do anything.
            */
            break;
        }
    } else if (e->type == SDL_KEYUP) {
        switch (e->key.keysym.sym) {

        case SDLK_LEFT:
        case SDLK_RIGHT:
            speed.x = 0;
            break;

        default:
            break;
        }
    }
}


/**
 * Character::handle_updates
 *
 * See character.hpp
 */
void
Character::handle_logic()
{
    // Handle gravity!
    speed.y += GRAVITY;

    //Move
    position.x += speed.x;
    position.y += speed.y;

    if (position.x < 0) {
        position.x = 0;
    }

    if (position.x > 600 - size.x) {
        position.x = 600 - size.x;
    }

    if (position.y < 0) {
        position.y = 0;
    }

    if (position.y > 480 - size.y) {
        position.y = 480 - size.y;
        speed.y = 0;
        state = CHARACTER_STATE_GROUNDED;
    }

    sprite->Set_screen_location(position);
}
