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
#include <level.hpp>
#include <character.hpp>
#include <utils.hpp>
#include <render.hpp>

/*DEFINES**********************************************************************/

/*GLOBAL VARIABLES*************************************************************/

/**
 * clear_colour
 *
 * The colour to clear the renderer with.
 */
static Colour clear_colour = {0xFF, 0xFF, 0xFF, 0xFF};


/**
 * Set of static colours
 */
//static Colour BLACK = {0x00, 0x00, 0x00, 0xFF};
static Colour RED   = {0xFF, 0x00, 0x00, 0xFF};

/*MAIN CODE BODY***************************************************************/

game_errno_type SDL_Libraries_Initiation(int img_flags) {
    game_errno_type rc = GAME_ERRNO_SUCCESS;
    int sdl_return;

    //Initiate SDL library
    if (GAME_ERR_OK(rc)) {
        sdl_return = SDL_Init(SDL_INIT_VIDEO);
        if (sdl_return < 0) {
            rc = GAME_ERRNO_SDL_ERROR;
        }
    }

    //Initiate IMG library
    if (GAME_ERR_OK(rc)) {
        sdl_return = IMG_Init(img_flags);
        if ((sdl_return & img_flags) != img_flags) {
            rc = GAME_ERRNO_IMG_ERROR;
        }
    }

    return rc;
}

game_errno_type SDL_Libraries_Quit() {
    //Quit the various libraries
    //Currently quit in reverse order to loaded.

    IMG_Quit();
    SDL_Quit();

    return GAME_ERRNO_SUCCESS;
}

static void
main_set_render_colour(SDL_Renderer *renderer,
                       Colour       *colour) {
    SDL_SetRenderDrawColor(renderer,
                           colour->r,
                           colour->g,
                           colour->b,
                           colour->a);
}

int
main (int   argc,
      char* argv[])
{
    game_errno_type  rc = GAME_ERRNO_SUCCESS;
    SDL_Window      *window = NULL;
    bool             quit = false;
    SDL_Event        event;
    SDL_Renderer    *renderer = NULL;
    Graphics_Object *go;
    Character       *main_char;
    int              img_flags = IMG_INIT_PNG;
    Level            level;

    /*
     * Initialise SDL, SDL_image and create a window.
     */
    if (GAME_ERR_OK(rc)) {
        rc = SDL_Libraries_Initiation(img_flags);
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

    if (GAME_ERR_OK(rc)) {
        renderer = SDL_CreateRenderer(window,
                                      -1,    //Use first available driver
                                      SDL_RENDERER_ACCELERATED);

        if (renderer == NULL) {
            rc = GAME_ERRNO_SDL_ERROR;
        }
    }

    /**
     * Create a graphics object.
     */
    if (GAME_ERR_OK(rc)) {
        main_char = new Character(renderer);
        go = main_char->sprite;
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

                main_char->handle_event(&event);
            }
            main_char->handle_logic();
            main_set_render_colour(renderer, &clear_colour);
            SDL_RenderClear(renderer);
            main_set_render_colour(renderer, &RED);
            go->Render();
            level.draw(renderer);
            SDL_RenderPresent(renderer);
        }
    }

    delete go;

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    window = NULL;
    SDL_Libraries_Quit();

    if (GAME_ERR_NOTOK(rc)) {
        std::cout << "Something didn't work: " << game_errno_strerror(rc) << "\n";
    }

    return (rc);
}
