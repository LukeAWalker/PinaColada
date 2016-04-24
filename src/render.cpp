/*******************************************************************************

Title:      render.cpp
Author:     Luke
Date:       24/04/2016

Description:

    The render file contains implementations of the rendering functions. See
render.hpp

*******************************************************************************/

/*DEFINES**********************************************************************/

/*INCLUDES*********************************************************************/

#include <render.hpp>
#include <SDL.h>

/*GLOBAL VARIABLES*************************************************************/

//Renderer_t* GLOBAL_RENDERER;

/*MAIN CODE BODY***************************************************************/
#if 0
game_errno_type Rendering_Functions::Initiate_Global_Renderer(SDL_Window* window) {
    game_errno_type rc = GAME_ERRNO_SUCCESS;

    rnd = SDL_CreateRenderer(window,
                             -1,    //Use first available driver
                             SDL_RENDERER_ACCELERATED);

    if (rnd == NULL) {
        rc = GAME_ERRNO_SDL_ERROR;
    }

    return rc;
}
#endif
