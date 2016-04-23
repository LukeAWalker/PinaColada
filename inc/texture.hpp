/**
 * texture.hpp
 *
 * Class defining a wrapper around SDL textures.
 */

#ifndef TEXTURE_H_
#define TEXTURE_H_

#include <SDL2/SDL.h>

/**
 * texture
 *
 * This is a wrapper class around SDL textures.
 */
class Texture {
public:



    /**
     * render
     *
     * Render the texture to a location on the screen.
     *
     * Argument: destination
     *   IN - The destination rectangle. The x and y cooridnates are the
     *        top left corner of where the texture will be rendered. The width
     *        and height can be 0, in which case the texture width and height
     *        will be used. Otherwise this will stretch to fill the desired
     *        space.
     *
     * Argument: clip
     *   IN - The clip of the texture to render. This argument can be NULL, in
     *        which case the whole texture will be rendered.
     *
     * Return: int @@@JH make this some error code.
     *   Error code indicating success or the reason for failure.
     */
    int render(SDL_Rect *destination,
               SDL_Rect *clip);

private:
    /**
     * Private member variables.
     */
    SDL_Renderer *renderer;
    SDL_Texture  *tex;
    uint32_t      width;
    uint32_t      height;
};

#endif //TEXTURE_H_
