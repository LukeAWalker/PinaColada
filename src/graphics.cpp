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

/*DEFINES**********************************************************************/

/*GLOBAL VARIABLES*************************************************************/

/*MAIN CODE BODY***************************************************************/

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
int Graphics_Object::Create_texture_from_file(const char *path,
                             Colour     *colour_key) {

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
int Graphics_Object::Render() {
    //TODO:: add render code
}

//Set *SCREEN* location (i.e. location on window, not level
//location)
int Graphics_Object::Set_screen_location(SDL_Point xy_location) {
    screen_area.x = xy_location.x;
    screen_area.y = xy_location.y;

    return 0;
}

//Set/Reset texture associated with this graphics object
//Set_texture(Texture texture);

//Set/Reset Extents of this graphics object (i.e. size of object)
//Measured in pixels of texture
int Graphics_Object::Set_extents(SDL_Point xy_size) {
    screen_area.w = xy_size.x;
    screen_area.h = xy_size.y;

    return 0;
}

//Set clipping area for textures with multiple sprites on
int Graphics_Object::Set_clip(SDL_Rect clip_area_in) {
    clip_area = clip_area_in;

    return 0;
}
