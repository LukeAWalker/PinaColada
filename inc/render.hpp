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
#include <vector>
#include <graphics.hpp>

/*CLASS DECLARATIONS***********************************************************/

class Renderer_t {
    public:
        //Constructor: creates list of graphics objects
        Renderer_t();

        //Constructor: creates list of graphics objects AND initiates global
        //renderer (see intiiate global renderer below)
        Renderer_t(SDL_Window* window);

        //Destructor: Deletes list of graphics objects, and also frees global
        //renderer
        ~Renderer_t();

        //Initiates global renderer. Must be called before rendering.
        //Takes: SDL window - pointer to window object representing screen.
        game_errno_type Initiate_Global_Renderer(SDL_Window* window);

        //Creates a graphics object and gives a pointer to the graphics object
        //returns an error code. arguments
        game_errno_type Create_Graphics_Object(Graphics_Object** go,
                                               std::string texture_path,
                                               Colour* col);

        //Draws all the graphics objects in the graphics object list
        //Returns an error code
        game_errno_type Draw();
    private:
        //Global renderer pointer
        SDL_Renderer* rnd;

        //List of graphics objects to renderer
        std::vector<Graphics_Object> sprite_list;
};

/*GLOBAL VARIABLES*************************************************************/

extern Renderer_t* GLOBAL_RENDERER;

/*MAIN CODE BODY***************************************************************/

#endif //RENDER_H_
