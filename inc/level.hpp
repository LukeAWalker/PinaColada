/*******************************************************************************

Title:      template
Author:     Luke
Date:       23/04/2016

Description:

  A template containing the header for each file. This should help organise the
project and give uniform code. Use the same header for .h files and .cpp
files.

*******************************************************************************/

/*HEADER GUARDS****************************************************************/
#ifndef _LEVEL_H_
#define _LEVEL_H_

/*INCLUDES*********************************************************************/

#include <SDL.h>
#include <graphics.hpp>
#include <vector>
#include <string>
#include "debug.hpp"
#include "block.hpp"
#include "character.hpp"

#define rectslength     11

/*DEFINES**********************************************************************/

/*GLOBAL VARIABLES*************************************************************/

/*MAIN CODE BODY***************************************************************/

class Level {

public:

// Create a rectangle array: Blocks
Graphics_Object* rects[rectslength];
std::vector<block_t*>    Blocks;
std::vector<Character*>  Characters;
//std::vector<item_t>     Items;
//std::vector<enemy_t>    Enemies;

//Constructor and destructor
Level();
~Level();

game_errno_type Load_from_file(std::string path);

/**
 * handle_collisions
 *
 * Handle any collisions between the objects that are a part of this level.
 *
 * This should be called once per game loop as part of the logic handling case.
 */
void handle_collisions();

};

#endif //_LEVEL_H_
