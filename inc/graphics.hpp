/*******************************************************************************

Title:      graphics.hpp
Author:     Luke
Date:       23/04/2016

Description:

    This file contains the class definition for the graphics object that every
drawable class will contain

*******************************************************************************/

/*INCLUDES*********************************************************************/

#include <SDL2/SDL.h>

/*DEFINES**********************************************************************/

/*GLOBAL VARIABLES*************************************************************/

/*MAIN CODE BODY***************************************************************/

#ifndef GRAPHICS_H_
#define GRAPHICS_H_

class Graphics_Object {
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
        Graphics_Object(SDL_Renderer *renderer);

        //Default constructor/destructor - does bare minimum (i.e. nothing)
        Graphics_Object();
        ~Graphics_Object();

        /**
         * create_texture_from_file
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
        int Create_texture_from_file(const char *path,
                                     Colour     *colour_key);

        /**
        * render
        *
        * Render the texture to a location on the screen.
        * Renders using the currently set position, size and clip
        *
        * Return: int @@@JH make this some error code.
        *   Error code indicating success or the reason for failure.
        */
        int Render();

        //Set *SCREEN* location (i.e. location on window, not level
        //location)
        int Set_screen_location(SDL_Point xy_location);

        //Set/Reset texture associated with this graphics object
        //Set_texture(Texture texture);

        //Set/Reset Extents of this graphics object (i.e. size of object)
        //Measured in pixels of texture
        int Set_extents(SDL_Point xy_size);

        //Set clipping area for textures with multiple sprites on
        int Set_clip(SDL_Rect clip_area_in);
    private:
        //variable for screen location
        SDL_Rect screen_area;

        //variable for clip area
        SDL_Rect clip_area;

        //SDL texture object
        SDL_Texture texture;

        //Renderer pointer
        SDL_Renderer *renderer;
};

#endif //GRAPHICS_H_
