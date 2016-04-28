/**
 * character_state.cpp
 *
 * Implementation of the various character states.
 */
#include <vector>
#include <SDL.h>
#include <character.hpp>
#include <character_state.hpp>

#define KEY_PRESSED(key, key_states) ((key_states)[(key)] != 0)
#define MAX_SPEED 10

/**
 * AerialState::handle_event
 *
 * See character_state.hpp
 */
character_state_type
AerialState::handle_input(Character              *character,
                          std::vector<SDL_Event>&  events)
{
    SDL_Point      new_velocity;
    const uint8_t *keyboard_states = NULL;

    keyboard_states = SDL_GetKeyboardState(NULL);

    new_velocity = character->get_velocity();

    if (KEY_PRESSED(SDL_SCANCODE_LEFT, keyboard_states)) {
        new_velocity.x -= 2;
    }

    if (KEY_PRESSED(SDL_SCANCODE_RIGHT, keyboard_states)) {
        new_velocity.x += 2;
    }

    if (new_velocity.x > MAX_SPEED) {
        new_velocity.x = MAX_SPEED;
    }

    if (new_velocity.x < -MAX_SPEED) {
        new_velocity.x = -MAX_SPEED;
    }

    character->set_velocity(new_velocity);

    return (CHARACTER_STATE_AERIAL); //Don't change state.
}


/**
 * AerialState::enter
 *
 * See character_states.hpp
 */
void
AerialState::enter(Character *character)
{
    // Nothing to do here.
}


/**
 * handle_input
 *
 * See character_states.hpp
 */
character_state_type
GroundedState::handle_input(Character              *character,
                           std::vector<SDL_Event>&  events)
{
    uint32_t             i;
    SDL_Event            e;
    SDL_Point            new_velocity;
    character_state_type new_state = CHARACTER_STATE_GROUNDED;

    new_velocity = character->get_velocity();

    // Handle any key events that come in.
    for (i = 0; i < events.size(); i++) {
        e = events[i];
        if (e.type == SDL_KEYDOWN && e.key.repeat == 0) {
            switch (e.key.keysym.sym) {
            case SDLK_LEFT:
                if (new_velocity.x > -MAX_SPEED) {
                    new_velocity.x -= 10;
                } else {
                    new_velocity.x = -MAX_SPEED;
                }
                break;

            case SDLK_RIGHT:
                if (new_velocity.x < MAX_SPEED) {
                    new_velocity.x += 10;
                } else {
                    new_velocity.x = MAX_SPEED;
                }
                break;

            case SDLK_UP:
                new_velocity.y = -30;
                new_state = CHARACTER_STATE_AERIAL;
                break;

            default:
                // Don't do anything.
                break;
            }
        } else if (e.type == SDL_KEYUP && e.key.repeat == 0) {
            switch (e.key.keysym.sym) {
            case SDLK_LEFT:
                new_velocity.x += 10;
                break;

            case SDLK_RIGHT:
                new_velocity.x -= 10;
                break;

            default:
                break;
            }
        }
    }

    character->set_velocity(new_velocity);

    return (new_state);
}


/**
 * GroundedState::enter
 *
 * See character_state.hpp
 */
void
GroundedState::enter(Character *character)
{
    const uint8_t *keyboard_states = NULL;
    SDL_Point      velocity;

    velocity = character->get_velocity();
    velocity.x = 0;

    //Get the current key states, and set the horizontal velocity accordingly.
    keyboard_states = SDL_GetKeyboardState(NULL);

    if (KEY_PRESSED(SDL_SCANCODE_LEFT, keyboard_states) &&
        !KEY_PRESSED(SDL_SCANCODE_RIGHT, keyboard_states)) {
            velocity.x = -10;
    }

    if (KEY_PRESSED(SDL_SCANCODE_RIGHT, keyboard_states) &&
        !KEY_PRESSED(SDL_SCANCODE_LEFT, keyboard_states)) {
            velocity.x = 10;
    }

    character->set_velocity(velocity);
}
