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
CharState*
AerialState::handle_input(Character              *character,
                          std::vector<SDL_Event>&  events)
{
    uint32_t       i;
    SDL_Event      e;
    SDL_Point      new_velocity;

    new_velocity = character->get_velocity();
    /**
     * TODO: Might be better done with key states
     */
    // Handle any key events that come in.
    for (i = 0; i < events.size(); i++) {
        e = events[i];
        if (e.type == SDL_KEYDOWN && e.key.repeat == 0) {
            switch (e.key.keysym.sym) {
            case SDLK_LEFT:
                if (new_velocity.x > -MAX_SPEED) {
                    new_velocity.x -= 2;
                } else {
                    new_velocity.x = -MAX_SPEED;
                }
                break;

            case SDLK_RIGHT:
                if (new_velocity.x < MAX_SPEED) {
                    new_velocity.x += 2;
                } else {
                    new_velocity.x = MAX_SPEED;
                }
                break;

            default:
                // Don't do anything.
                break;
            }
        }
    }
    character->set_velocity(new_velocity);

    return (NULL); //Don't change state.
}

/**
 * handle_input
 *
 * See character_states.hpp
 */
CharState*
GroundedState::handle_input(Character              *character,
                           std::vector<SDL_Event>&  events)
{
    uint32_t       i;
    SDL_Event      e;
    SDL_Point      new_velocity;
    CharState     *new_state = NULL;

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
                new_state = new AerialState();
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
