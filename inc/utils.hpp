/*******************************************************************************

Title:      utils.hpp
Author:     James
Date:       23/04/2016

Description:

  Extra utility types and functions for use throughout the code.

*******************************************************************************/

/*HEADER GUARDS****************************************************************/
#ifndef UTILS_H_
#define UTILS_H_

#include <SDL.h>

/*DEFINES**********************************************************************/

/*INCLUDES*********************************************************************/

/*GLOBAL VARIABLES*************************************************************/

/*MAIN CODE BODY***************************************************************/

/**
 * Colour
 *
 * Struct representing a colour in RGBA format.
 */
struct Colour {
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
};


/**
 * RECTANGLE_OVERLAP_*
 *
 * Set of flags which describe which edges of a rectangle are overlapping.
 */
#define RECTANGLE_OVERLAP_NONE   0x0
#define RECTANGLE_OVERLAP_TOP    0x1
#define RECTANGLE_OVERLAP_RIGHT  0x2
#define RECTANGLE_OVERLAP_BOTTOM 0x4
#define RECTANGLE_OVERLAP_LEFT   0x8 //Next flag is 0x10 if anyone adds to this...

/**
 * rectangle_overlap_t
 *
 * Type defining the type of overlap between two rectangles. Note this can be
 * any combination of the above flags.
 */
typedef uint8_t rectangle_overlap_t;


/**
 * check_rectangles_overlap
 *
 * Utility function to check if two rectangles overlap.
 *
 * Argument: rect_a
 *   IN - The first rectangle to consider.
 *
 * Argument: rect_b
 *   IN - The second rectangle to consider.
 *
 * Argument: a_overlap
 *   OUT - The edges of A that are overlapped by B. Can be NULL if this
 *         information isn't required.
 *
 * Argument: b_overlap
 *   OUT - The edges of B that are overlapped by A. Can be NULL if this
 *         information isn't required.
 *
 * Return: bool
 *   true if the rectangles overlap, false otherwise.
 */
bool
check_rectangle_overlap(SDL_Rect            *rect_a,
                        SDL_Rect            *rect_b,
                        rectangle_overlap_t *a_overlap,
                        rectangle_overlap_t *b_overlap);


/**
 * object_t
 *
 * Enumeration of possible object types
 */
enum object_t {
    OBJECT_LEVEL_BLOCK,
    OBJECT_CHARACTER,
};

#endif //UTILS_H_
