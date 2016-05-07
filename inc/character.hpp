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
#include <string>

/*DEFINES**********************************************************************/

/*GLOBAL VARIABLES*************************************************************/

/*MAIN CODE BODY***************************************************************/

class Character {
    public:
        //Default constructor and destructor
        Character(SDL_Renderer* renderer);
        Character(std::string texture_path, SDL_Rect level_coords);
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
        void handle_event(std::vector<SDL_Event>& events);

        /**
         * handle_logic
         *
         * Perform any updates of the character class.
         */
        void handle_logic();

        /**
         * set_velocity
         *
         * Set the current velocity
         *
         * Argument: vel
         *   IN - The velocity to add to the current velocity.
         */
        void set_velocity(SDL_Point vel);

        /**
         * get_velocity
         *
         * Get the current velocity
         *
         * Return: SDL_Point
         *   The current character velocity
         */
        SDL_Point get_velocity();

        /**
         * change_state
         *
         * Change the current character state
         *
         * Argument: new_state
         *   IN - The state to change to.
         */
        void change_state(character_state_type new_state);

        //Graphics object
        Graphics_Object* sprite;
    private:
        //Level position, size
        SDL_Point   position;
        SDL_Point   size;

        //Character current speed (2D)
        SDL_Point       speed;
        CharState            *state;
        character_state_type  current_state;

};

#endif //CHARACTER_H_
