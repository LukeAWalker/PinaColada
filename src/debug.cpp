/**
 * debug.cpp
 *
 * Definitions for debug functions.
 */
#include <assert.h>
#include <string>
#include <SDL2/SDL.h>
#include <debug.hpp>

/**
 * game_errno_strerror
 *
 * See debug.hpp
 */
std::string
game_errno_strerror (game_errno_type rc)
{
    std::string return_string;

    switch (rc) {
    case GAME_ERRNO_SUCCESS:
        return_string = "Success";
        break;

    case GAME_ERRNO_INVALID_ARG:
        return_string = "Invalid argument passed";
        break;

    case GAME_ERRNO_SDL_ERROR:
        return_string = (char *)SDL_GetError();
        break;

    case GAME_ERRNO_BAD_PATH:
        return_string = "Invalid path to texture image supplied";
        break;

    default:
        /*
         * We should never hit this.
         */
        assert(false);
        return_string = "Unknown error occurred";
        break;
    }

    return (return_string);
}
