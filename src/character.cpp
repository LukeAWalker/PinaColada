/*******************************************************************************

Title:      character.cpp
Author:     Luke
Date:       23/04/2016

Description:

  Contains method definitions for the Character class.

*******************************************************************************/

/*INCLUDES*********************************************************************/

#include "character.hpp"
#include <character_state.hpp>
#include <SDL.h>
#include <graphics.hpp>
#include <utils.hpp>
#include <render.hpp>
#include <iostream>
#include <vector>

#define GRAVITY 1

/*DEFINES**********************************************************************/

/*GLOBAL VARIABLES*************************************************************/

/*MAIN CODE BODY***************************************************************/

Character::Character() {
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
    GLOBAL_RENDERER->Create_Graphics_Object(&sprite, "../../resources/masterchief.png", &temp_col);

    sprite->Set_screen_location(position);
    sprite->Set_extents(size);
    SDL_Rect clip_area = {0,0,224,326};
    sprite->Set_clip(clip_area);
    state = new AerialState();
}

Character::Character(SDL_Renderer* renderer) {
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
    GLOBAL_RENDERER->Create_Graphics_Object(&sprite, "../../resources/masterchief.png", &temp_col);

    sprite->Set_screen_location(position);
    sprite->Set_extents(size);
    SDL_Rect clip_area = {0,0,224,326};
    sprite->Set_clip(clip_area);
    state = new AerialState();
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
Character::handle_event(std::vector<SDL_Event> events)
{
    CharState *new_state = NULL;

    new_state = state->handle_input(this, events);

    if (new_state != NULL) {
        delete state;
        state = new_state;
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
        delete state;
        state = new GroundedState();
    }

    sprite->Set_screen_location(position);
}


void
Character::change_velocity(SDL_Point vel)
{
    speed.x += vel.x;
    speed.y += vel.y;
}
