/*******************************************************************************

Title:      utils.cpp
Author:     James
Date:       15/05/2016

Description:

Utility function definitions for use throughout the code.

*******************************************************************************/
#include <SDL.h>
#include "utils.hpp"


/**
 * check_rectangle_overlap
 *
 * See utils.hpp
 */
bool
check_rectangle_overlap(SDL_Rect            *rect_a,
                        SDL_Rect            *rect_b,
                        rectangle_overlap_t *a_overlap,
                        rectangle_overlap_t *b_overlap)
{
    bool                rects_intersect = false;
    SDL_Rect            intersection = {0, 0, 0, 0};

    if (a_overlap != NULL) {
        *a_overlap = RECTANGLE_OVERLAP_NONE;
    }

    if (b_overlap != NULL) {
        *b_overlap = RECTANGLE_OVERLAP_NONE;
    }

    rects_intersect = SDL_IntersectRect(rect_a, rect_b, &result);

    if (rects_intersect) {

    }
}
