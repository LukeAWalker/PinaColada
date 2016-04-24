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
#include <vector>

/*GLOBAL VARIABLES*************************************************************/

Renderer_t* GLOBAL_RENDERER;

/*MAIN CODE BODY***************************************************************/

//Constructor: creates list of graphics objects
Renderer_t::Renderer_t() {
    sprite_list.reserve(30);
}

//Constructor: creates list of graphics objects AND initiates global
//renderer (see intiiate global renderer below)
Renderer_t::Renderer_t(SDL_Window* window) {
    Initiate_Global_Renderer(window);
}

//Destructor: Deletes list of graphics objects, and also frees global
//renderer
Renderer_t::~Renderer_t(){
    //Clear all the graphics objects from memory
    for(unsigned int i=0;i<sprite_list.size();i++) {
        delete &sprite_list[i];
    }

    //Free the renderer
    SDL_DestroyRenderer(rnd);
}

game_errno_type Renderer_t::Initiate_Global_Renderer(SDL_Window* window) {
    game_errno_type rc = GAME_ERRNO_SUCCESS;

    rnd = SDL_CreateRenderer(window,
                             -1,    //Use first available driver
                             SDL_RENDERER_ACCELERATED);

    if (rnd == NULL) {
        rc = GAME_ERRNO_SDL_ERROR;
    }

    return rc;
}

//Creates a graphics object and gives a pointer to the graphics object
//returns an error code. arguments
game_errno_type Renderer_t::Create_Graphics_Object(Graphics_Object** go,
                                       std::string texture_path,
                                       Colour* col){
    game_errno_type rc = GAME_ERRNO_SUCCESS;

    //Create temporary graphics object to add to vector. Set go to point to that
    //location
    if(GAME_ERR_OK(rc)) sprite_list.push_back(Graphics_Object(rnd));
    *go = &sprite_list[sprite_list.size() - 1];
    if(*go == NULL) rc = GAME_ERRNO_ERROR;

    if(GAME_ERR_OK(rc)) rc = (*go)->Create_texture_from_file(texture_path, col);

    return rc;
}

//Draws all the graphics objects in the graphics object list
//Returns an error code
game_errno_type Renderer_t::Draw() {
    game_errno_type rc = GAME_ERRNO_SUCCESS;

    Colour col = {0xFF,0xFF,0xFF,0xFF};
    if(GAME_ERR_OK(rc)) {
        int sdl_error = SDL_SetRenderDrawColor(rnd,col.r,col.g,col.b,col.a);
        if (sdl_error < 0) rc = GAME_ERRNO_SDL_ERROR;
    }
    if(GAME_ERR_OK(rc)) {
        int sdl_error = SDL_RenderClear(rnd);
        if (sdl_error < 0) rc = GAME_ERRNO_SDL_ERROR;
    }
    if(GAME_ERR_OK(rc)) {
        col = {0xFF,0x00,0x00,0x00};
        int sdl_error = SDL_SetRenderDrawColor(rnd,col.r,col.g,col.b,col.a);
        if (sdl_error < 0) rc = GAME_ERRNO_SDL_ERROR;
    }

    for(unsigned int i=0;i<sprite_list.size();i++) {
        if(GAME_ERR_OK(rc)) rc = sprite_list[i].Render();
    }

    if(GAME_ERR_OK(rc)) SDL_RenderPresent(rnd);

    return rc;
}
