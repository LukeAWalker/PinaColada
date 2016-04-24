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
#include <character_state.hpp>
#include <graphics.hpp>
#include <vector>

/*DEFINES**********************************************************************/

/*GLOBAL VARIABLES*************************************************************/

/*MAIN CODE BODY***************************************************************/

enum CharacterState {
    CHARACTER_STATE_GROUNDED,
    CHARACTER_STATE_AERIAL,
};

class Character {
    public:
        //Default constructor and destructor
        Character(SDL_Renderer* renderer);
        Character();
        ~Character();

        /**
         * handle_event
         *
         * Handle all SDL_Events for a frame
         *
         * Argument: events
         *   IN - The events to handle
         */
        void handle_event(std::vector<SDL_Event> events);

        /**
         * handle_logic
         *
         * Perform any updates of the character class.
         */
        void handle_logic();

        /**
         * change_velocity
         *
         * Change the current velocity by adding some value to it.
         *
         * Argument: vel
         *   IN - The velocity to add to the current velocity.
         */
        void change_velocity(SDL_Point vel);

        //Graphics object
        Graphics_Object* sprite;
    private:
        //Level position, size
        SDL_Point   position;
        SDL_Point   size;

        //Character current speed (2D)
        SDL_Point       speed;
        CharState *state;

};

#endif //CHARACTER_H_
