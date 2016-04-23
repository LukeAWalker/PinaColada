/*******************************************************************************

Title:      main.cpp
Author:     Luke
Date:       23/04/2016

Description:

  Main file for JPL's new game; this file might contain the splash screen and
main menu, for instance.

*******************************************************************************/

/*INCLUDES*********************************************************************/
#include <iostream>
#include <SDL.h>
#include <stdio.h>
#include <debug.hpp>
#include <graphics.hpp>
#include <SDL_image.h>


/*DEFINES**********************************************************************/

/*GLOBAL VARIABLES*************************************************************/

/*MAIN CODE BODY***************************************************************/

int
main (int argc,
      char* argv[])
{
    game_errno_type  rc = GAME_ERRNO_SUCCESS;
    int              sdl_rc;
    SDL_Window      *window;
    bool             quit = false;
    SDL_Event        event;
    SDL_Renderer    *renderer = NULL;
//    Graphics_Object *go;
    int              img_flags = IMG_INIT_PNG;

    /*
     * Initialise SDL and create a window.
     */
    if (GAME_ERR_OK(rc)) {
        sdl_rc = SDL_Init(SDL_INIT_VIDEO);
        if (sdl_rc < 0) {
            rc = GAME_ERRNO_SDL_ERROR;
        }
        sdl_rc = IMG_Init(img_flags);
        if ((sdl_rc & img_flags) != img_flags) {
            rc = GAME_ERRNO_SDL_ERROR;
        }
    }

    if (GAME_ERR_OK(rc)) {
        window = SDL_CreateWindow("Test",
                                  SDL_WINDOWPOS_UNDEFINED,
                                  SDL_WINDOWPOS_UNDEFINED,
                                  600,
                                  480,
                                  SDL_WINDOW_SHOWN);
        if (window == NULL) {
            rc = GAME_ERRNO_SDL_ERROR;
        }
    }

    /*if(GAME_ERR_OK(rc)) {
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    }
    go = new Graphics_Object(renderer);
    Colour newcol = {0,0,0,0};
    rc = go->Create_texture_from_file("main_char.png", &newcol);
    SDL_Point point = {100,100}, extents = {100,50};
    go->Set_screen_location(point);
    go->Set_extents(extents);
    SDL_Rect rect = {0,0,504,600};
    go->Set_clip(rect);*/

    /*
     * Run an event loop so you can quit.
     */
    if (GAME_ERR_OK(rc)) {
        while (!quit) {
            while (SDL_PollEvent(&event) != 0) {
                if (event.type == SDL_QUIT) {
                    quit = true;
                }
            }

/*            SDL_SetRenderDrawColor(renderer, 0xFF,0xFF,0xFF,0xFF);
            SDL_RenderClear(renderer);
            SDL_SetRenderDrawColor(renderer, 0x00,0x00,0x00,0xFF);

            go->Render();

            SDL_RenderPresent(renderer);*/
        }
    }

//    delete go;

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    window = NULL;
    IMG_Quit();
    SDL_Quit();

    if (GAME_ERR_NOTOK(rc)) {
        std::cout << "Something didn't work: " << game_errno_strerror(rc) << "\n";
    }

    return (rc);
}
