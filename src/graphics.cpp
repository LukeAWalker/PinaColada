/*******************************************************************************

Title:      graphic.cpp
Author:     Luke
Date:       23/04/2016

Description:

    This file contains the methods for the graphics object that every drawable
object will contain.

*******************************************************************************/

/*INCLUDES*********************************************************************/

#include <graphics.hpp>
#include <debug.hpp>
#include <utils.hpp>
#include <SDL_image.h>

/*DEFINES**********************************************************************/

/*GLOBAL VARIABLES*************************************************************/

/*MAIN CODE BODY***************************************************************/

/**
 * Texture::Texture
 *
 * See texture.hpp
 */
Graphics_Object::Graphics_Object(SDL_Renderer *renderer)
{
    rnd = renderer;
    texture = NULL;

    //Set screen_area and clip_area, position to top left, width and height to 0
    screen_area = {0,0,0,0};
    clip_area = {0,0,0,0};
}

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
game_errno_type Graphics_Object::Create_texture_from_file(std::string path,
                                                          Colour     *colour_key) {
    game_errno_type rc = GAME_ERRNO_SUCCESS;



    return rc;
}

/**
* render
*
* Render the texture to a location on the screen.
* Renders using the currently set position, size and clip
*
* Return: int @@@JH make this some error code.
*   Error code indicating success or the reason for failure.
*/
game_errno_type Graphics_Object::Render() {
    game_errno_type rc = GAME_ERRNO_SUCCESS;

    //render a copy of a portion (clip) of the texture to the screen
    int error = SDL_RenderCopy(rnd, texture, &clip_area, &screen_area);

    if(error < 0) rc = GAME_ERRNO_SDL_ERROR;

    return rc;
}

//Set *SCREEN* location (i.e. location on window, not level
//location)
game_errno_type Graphics_Object::Set_screen_location(SDL_Point xy_location) {
    screen_area.x = xy_location.x;
    screen_area.y = xy_location.y;

    return GAME_ERRNO_SUCCESS;
}

//Set/Reset texture associated with this graphics object
//Set_texture(Texture texture);

//Set/Reset Extents of this graphics object (i.e. size of object)
//Measured in pixels of texture
game_errno_type Graphics_Object::Set_extents(SDL_Point xy_size) {
    screen_area.w = xy_size.x;
    screen_area.h = xy_size.y;

    return GAME_ERRNO_SUCCESS;
}

//Set clipping area for textures with multiple sprites on
game_errno_type Graphics_Object::Set_clip(SDL_Rect clip_area_in) {
    clip_area = clip_area_in;

    return GAME_ERRNO_SUCCESS;
}
