/**
 * character_state
 *
 * States for the character.
 */

#ifndef CHARACTER_STATE_H_
#define CHARACTER_STATE_H_

#include <vector>
#include <SDL.h>
#include "character.hpp"

class Character; //Need this forward declaration to break a cycle

/**
 * CharState
 *
 * The base character state. This is the interface that all character states
 * must implement.
 */
class CharState {
public:
    virtual ~CharState() {};

    /**
     * handle_event
     *
     * Handle a single event.
     *
     * Argument: character
     *   IN - The character to handle events for.
     *
     * Argument: events
     *   IN - List of events that occurred this frame.
     *
     * Return: CharState*
     *   Pointer to the state to transition to, or NULL if no state transition
     *   is required.
     */
    virtual CharState* handle_input(Character              *character,
                                    std::vector<SDL_Event>  events) = 0;
};


class AerialState: public CharState {
public:
    AerialState() {};
    ~AerialState() {};
    CharState* handle_input(Character              *character,
                            std::vector<SDL_Event>  events);
};

class GroundedState: public CharState {
public:
    GroundedState() {};
    ~GroundedState() {};
    CharState* handle_input(Character              *character,
                            std::vector<SDL_Event>  events);
};

#endif //CHARACTER_STATE_H_
