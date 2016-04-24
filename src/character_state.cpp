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

/**
 * AerialState::handle_event
 *
 * See character_state.hpp
 */
CharState*
AerialState::handle_input(Character              *character,
                          std::vector<SDL_Event>  events)
{
    uint32_t       i;
    SDL_Event      e;
    const uint8_t *keyboard_states = NULL;
    SDL_Point      new_velocity;

    keyboard_states = SDL_GetKeyboardState(NULL);

    // Handle any key events that come in.
    for (i = 0; i < events.size(); i++) {
        e = events[i];
        if (e.type == SDL_KEYDOWN) {
            switch (e.key.keysym.sym) {
            case SDLK_LEFT:
                if (!KEY_PRESSED(SDLK_RIGHT, keyboard_states)) {
                    new_velocity.x = -10;
                }
                break;

            case SDLK_RIGHT:
                if (!KEY_PRESSED(SDLK_LEFT, keyboard_states)) {
                    new_velocity.x = 10;
                }
                break;

            default:
                // Don't do anything.
                break;
            }
        } else if (e.type == SDL_KEYUP) {
            switch (e.key.keysym.sym) {
            case SDLK_LEFT:
            case SDLK_RIGHT:
                if (!KEY_PRESSED(SDLK_LEFT, keyboard_states) &&
                    !KEY_PRESSED(SDLK_RIGHT, keyboard_states)) {
                        new_velocity.x = 0;
                }
                break;

            default:
                break;
            }
        }
    }
    character->change_velocity(new_velocity);

    return (NULL); //Don't change state.
}

/**
 * handle_input
 *
 * See character_states.hpp
 */
CharState*
GroundedState::handle_input(Character              *character,
                           std::vector<SDL_Event>  events)
{
    uint32_t       i;
    SDL_Event      e;
    const uint8_t *keyboard_states = NULL;
    SDL_Point      new_velocity;
    CharState     *new_state = NULL;

    keyboard_states = SDL_GetKeyboardState(NULL);

    // Handle any key events that come in.
    for (i = 0; i < events.size(); i++) {
        e = events[i];
        if (e.type == SDL_KEYDOWN) {
            switch (e.key.keysym.sym) {
            case SDLK_LEFT:
                if (!KEY_PRESSED(SDLK_RIGHT, keyboard_states)) {
                    new_velocity.x = -10;
                }
                break;

            case SDLK_RIGHT:
                if (!KEY_PRESSED(SDLK_LEFT, keyboard_states)) {
                    new_velocity.x = 10;
                }
                break;

            case SDLK_UP:
                new_velocity.y = -30;
                new_state = new AerialState();
                break;

            default:
                // Don't do anything.
                break;
            }
        } else if (e.type == SDL_KEYUP) {
            switch (e.key.keysym.sym) {
            case SDLK_LEFT:
            case SDLK_RIGHT:
                if (!KEY_PRESSED(SDLK_LEFT, keyboard_states) &&
                    !KEY_PRESSED(SDLK_RIGHT, keyboard_states)) {
                        new_velocity.x = 0;
                }
                break;

            default:
                break;
            }
        }
    }

    character->change_velocity(new_velocity);

    return (new_state);
}
