/*******************************************************************************

Title:      render.hpp
Author:     Luke
Date:       24/04/2016

Description:

    The header file containing the global render object, and other functions
related to rendering.

*******************************************************************************/

/*HEADER GUARDS****************************************************************/
#ifndef RENDER_H_
#define RENDER_H_

/*DEFINES**********************************************************************/

/*INCLUDES*********************************************************************/

#include <SDL.h>
#include <debug.hpp>

/*CLASS DECLARATIONS***********************************************************/

class Rendering_t {
    public:
        //Constructor: creates list of graphics objects
        Rendering_t();

        //Constructor: creates list of graphics objects AND initiates global
        //renderer (see intiiate global renderer below)
        Rendering_t(SDL_Window* window);

        //Destructor: Deletes list of graphics objects, and also frees global
        //renderer
        ~Rendering_t();

        //Initiates global renderer. Must be called before rendering.
        //Takes: SDL window - pointer to window object representing screen.
        game_errno_type Initiate_Global_Renderer(SDL_Window* window);
    private:
        SDL_Renderer* rnd;
};

/*GLOBAL VARIABLES*************************************************************/

extern Renderer_t* GLOBAL_RENDERER;

/*MAIN CODE BODY***************************************************************/

#endif //RENDER_H_
