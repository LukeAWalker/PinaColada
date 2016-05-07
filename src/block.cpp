/*******************************************************************************

Title:      block.cpp
Author:     Luke
Date:       01/05/2016

Description:

  The c++ file for a block object. See block.hpp

*******************************************************************************/

/*DEFINES**********************************************************************/

/*INCLUDES*********************************************************************/

#include <SDL.h>
#include <string>
#include "render.hpp"
#include "block.hpp"

/*GLOBAL VARIABLES*************************************************************/

/*MAIN CODE BODY***************************************************************/

//Constructor
block_t::block_t(std::string texture_path, SDL_Rect level_coords) {

    //Create graphics object
    Colour temp_col = {0x00,0xFF,0xFF,0xFF};
    GLOBAL_RENDERER->Create_Graphics_Object(&sprite, texture_path, &temp_col);
    sprite->Set_position_size(level_coords);

    //Set clip area: TODO: make this user changeable
    SDL_Rect clip_temp = {0,0,100,100};
    sprite->Set_clip(clip_temp);
}

//Destructor
block_t::~block_t() {
    delete sprite;
}
