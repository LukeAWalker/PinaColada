/*******************************************************************************

Title:      block.hpp
Author:     Luke
Date:       01/05/2016

Description:

  The header file for a block object. All types of blocks will be covered by
this class. Some blocks will be solid, unmoveable and unchanging. Some may
change state to dispense an Item

*******************************************************************************/

/*HEADER GUARDS****************************************************************/
#ifndef BLOCK_H_
#define BLOCK_H_

/*DEFINES**********************************************************************/

/*INCLUDES*********************************************************************/

#include <SDL.h>
#include <string>

/*GLOBAL VARIABLES*************************************************************/

/*MAIN CODE BODY***************************************************************/

class block_t {

public:
    //Constructor
    block_t(std::string texture_path, SDL_Rect level_coords);

    //Destructor
    ~block_t();

    //sprite
    Graphics_Object* sprite;

};

#endif //BLOCK_H_
