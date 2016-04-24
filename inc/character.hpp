/*******************************************************************************

Title:      character.h
Author:     Luke
Date:       23/04/2016

Description:

    Contains the character class. The character class contains all data
relevant to the central character, currently:
    -Position & Extents
    -Graphics
    -Inventory

*******************************************************************************/

/*HEADER GUARDS****************************************************************/
#ifndef CHARACTER_H_
#define CHARACTER_H_

/*INCLUDES*********************************************************************/

#include <SDL.h>
#include <graphics.hpp>

/*DEFINES**********************************************************************/

/*GLOBAL VARIABLES*************************************************************/

/*MAIN CODE BODY***************************************************************/

class Character {
    public:
        //Default constructor and destructor
        Character(SDL_Renderer* renderer);
        ~Character();

        //Level position, size
        SDL_Point   position;
        SDL_Point   size;

        //Character current speed (2D)
        SDL_Point   speed;

        //Graphics object
        Graphics_Object* sprite;
};

#endif //CHARACTER_H_
