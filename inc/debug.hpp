/**
 * debug.hpp
 *
 * Debug macros and error utilities.
 */

#ifndef DEBUG_H_
#define DEBUG_H_

#include <string>

/**
 * game_errno
 *
 * Enumeration of error codes.
 */
enum game_errno_type {
    GAME_ERRNO_SUCCESS,
    GAME_ERRNO_INVALID_ARG,
    GAME_ERRNO_SDL_ERROR,
    GAME_ERRNO_BAD_PATH,
    GAME_ERRNO_IMG_ERROR,
};


/**
 * GAME_ERR_OK
 * GAME_ERR_NOTOK
 *
 * Macros for checking if an errno represents success or failure.
 */
#define GAME_ERR_OK(rc) ((rc) == GAME_ERRNO_SUCCESS)
#define GAME_ERR_NOTOK(rc) !GAME_ERR_OK(rc)


/**
 * game_errno_strerror
 *
 * Provide a string representation of an error code.
 *
 * Argument: rc
 *   IN - The error code to provide a string for.
 *
 * Return: std::string
 *   String representation of the error.
 */
std::string game_errno_strerror(game_errno_type rc);

#endif //DEBUG_H_
