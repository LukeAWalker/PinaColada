/*******************************************************************************

Title:      main.cpp
Author:     Luke
Date:       23/04/2016

Description:

  Main file for JPL's new game; this file might contain the splash screen and
main menu, for instance.

*******************************************************************************/

/*INCLUDES*********************************************************************/
#include <SDL2/SDL.h>
#include <stdio.h>


/*DEFINES**********************************************************************/

/*GLOBAL VARIABLES*************************************************************/

/*MAIN CODE BODY***************************************************************/

int
main (int argc,
      char* argv[])
{
    int         rc = 0;
    SDL_Window *window;
    int         i;

    if (rc == 0) {
        rc = SDL_Init(SDL_INIT_VIDEO);
    }

    if (rc == 0) {
        window = SDL_CreateWindow("Test",
                                  SDL_WINDOWPOS_UNDEFINED,
                                  SDL_WINDOWPOS_UNDEFINED,
                                  600,
                                  480,
                                  SDL_WINDOW_SHOWN);
        if (window == NULL) {
            rc = -1;
        }
    }

    if (rc == 0) {
        for (i = 0; i < 1000000; i++) {
            // Don't do anything here, this is just so we can see the window
        }
    }

    SDL_DestroyWindow(window);
    window = NULL;
    SDL_Quit();

    if (rc != 0) {
        printf("SDL didn't work: %s\n", SDL_GetError());
    }

    return (rc);
}
