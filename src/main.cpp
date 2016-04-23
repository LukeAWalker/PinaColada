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
#include <SDL2/SDL.h>
#include <stdio.h>
#include <debug.hpp>


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

    /*
     * Initialise SDL and create a window.
     */
    if (GAME_ERR_OK(rc)) {
        sdl_rc = SDL_Init(SDL_INIT_VIDEO);
        if (sdl_rc < 0) {
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
        }
    }

    SDL_DestroyWindow(window);
    window = NULL;
    SDL_Quit();

    if (GAME_ERR_NOTOK(rc)) {
        std::cout << "Something didn't work: " << game_errno_strerror(rc) << "\n";
    }

    return (rc);
}
