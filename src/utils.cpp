/*******************************************************************************

Title:      utils.cpp
Author:     James
Date:       15/05/2016

Description:

Utility function definitions for use throughout the code.

*******************************************************************************/
#include <SDL.h>
#include "utils.hpp"


static rectangle_overlap_t
get_overlap_edges(SDL_Rect *rect,
                  SDL_Rect *overlap_rect)
{
    rectangle_overlap_t overlap = RECTANGLE_OVERLAP_NONE;

    if (rect->y == overlap_rect->y) {
        overlap |= RECTANGLE_OVERLAP_TOP;
    }

    if (rect->x == overlap_rect->x) {
        overlap |= RECTANGLE_OVERLAP_LEFT;
    }

    if ((rect->x + rect->w) == (overlap_rect->x + overlap_rect->w)) {
        overlap |= RECTANGLE_OVERLAP_RIGHT;
    }

    if ((rect->y + rect->h) == (overlap_rect->y + overlap_rect->h)) {
        overlap |= RECTANGLE_OVERLAP_BOTTOM;
    }

    return (overlap);
}


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

    rects_intersect = SDL_IntersectRect(rect_a, rect_b, &intersection);

    if (rects_intersect) {
        if (a_overlap != NULL) {
            *a_overlap = get_overlap_edges(rect_a, &intersection);
        }

        if (b_overlap != NULL) {
            *b_overlap = get_overlap_edges(rect_b, &intersection);
        }
    }

    return (rects_intersect);
}
