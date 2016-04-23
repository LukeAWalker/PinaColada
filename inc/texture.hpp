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
     * Texture
     *
     * Constructor for a texture. Note that this doesn't load anything from file
     * - call create_from_file before using any other methods of this class.
     *
     * Argument: renderer
     *   IN - The renderer to use to render this texture.
     *
     * @@@JH might need to wrap the renderer, if so use that instead here.
     */
    Texture(SDL_Renderer *renderer);

    /**
     * create_from_file
     *
     * Create a texture from a file.
     *
     * Argument: path
     *   IN - The path to the file to be loaded.
     *
     * Argument: colour_key
     *   IN - The colour key to use for this texture. Pixels of the chosen
     *        colour will be rendered as transparent.
     *
     * Return: int @@@JH return an error code.
     *   Error code indicating success or reason for failure.
     */
    int create_from_file(const char *path,
                         Colour      *colour_key);


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
