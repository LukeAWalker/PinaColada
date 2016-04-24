/*******************************************************************************

Title:      template
Author:     Luke
Date:       23/04/2016

Description:

  A template containing the header for each file. This should help organise the
project and give uniform code. Use the same header for .h files and .cpp
files.

*******************************************************************************/

/*HEADER GUARDS****************************************************************/
#ifndef _LEVEL_H_
#define _LEVEL_H_

/*INCLUDES*********************************************************************/

#include <SDL.h>
#include <graphics.hpp>

#define rectslength     11

/*DEFINES**********************************************************************/

/*GLOBAL VARIABLES*************************************************************/

/*MAIN CODE BODY***************************************************************/

class Level {

public:

    // Create a rectangle
    Graphics_Object* rects[rectslength];

Level();
//void draw (SDL_Renderer* renderer);
void draw();
    //Renderer
 //  SDL_Renderer* renderer = SDL_CreateRenderer(MainWindow, -1, 0);


   //SDL_RenderPresent(renderer); // copy to screen

};

#endif //_LEVEL_H_
