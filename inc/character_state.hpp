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
 * TODO: I think this could be implemented better:
 *  - Create a state machine object to attach to the character, with a
 *    state_change() method.
 *  - Use an enum for the states to call into this method.
 *  - Store the states themselves on this machine
 *  - Machine handles all the switching.
 */

/**
 * character_state_type
 *
 * Enum representing the possible character states.
 */
enum character_state_type {
    CHARACTER_STATE_AERIAL,
    CHARACTER_STATE_GROUNDED,
};

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
     * Return: character_state_type
     *   The new state to transition to.
     */
    virtual character_state_type handle_input(
                                      Character               *character,
                                      std::vector<SDL_Event>&  events) = 0;

    /**
     * enter
     *
     * Perform any actions required on entering this state.
     *
     * Argument: character
     *   IN - The character who's entering this state.
     */
    virtual void enter(Character *character) = 0;
};


class AerialState: public CharState {
public:
    AerialState() {};
    ~AerialState() {};
    character_state_type handle_input(Character               *character,
                                      std::vector<SDL_Event>&  events);

    void enter(Character *character);
};

class GroundedState: public CharState {
public:
    GroundedState() {};
    ~GroundedState() {};
    character_state_type handle_input(Character               *character,
                                      std::vector<SDL_Event>&  events);

    void enter(Character *character);
};

#endif //CHARACTER_STATE_H_
