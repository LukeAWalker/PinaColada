/**
 * texture.cpp
 *
 * Implementation of the texture class
 */
#include <SDL2/SDL.h>
#include <debug.hpp>
#include <texture.hpp>
#include <utils.hpp>


/**
 * Texture::Texture
 *
 * See texture.hpp
 */
Texture::Texture(SDL_Renderer *renderer)
{
    rnd = renderer;
    tex = NULL;
    width = 0;
    height = 0;
}


/**
 * Texture::create_from_file
 *
 * See texture.hpp
 */
game_errno_type
Texture::create_from_file(const char *path,
                          Colour     *colour_key)
{
    game_errno_type rc = GAME_ERRNO_SUCCESS;

    return (rc);
}


/**
 * Texture::render
 *
 * See texture.hpp
 */
game_errno_type
Texture::render(SDL_Rect *destination,
                SDL_Rect *clip)
{
    game_errno_type rc = GAME_ERRNO_SUCCESS;

    return (rc);
}
