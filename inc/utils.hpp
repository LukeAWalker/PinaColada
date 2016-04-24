/*******************************************************************************

Title:      utils.hpp
Author:     James
Date:       23/04/2016

Description:

  Currently contains definition of "colour" structure.

*******************************************************************************/

/*HEADER GUARDS****************************************************************/
#ifndef UTILS_H_
#define UTILS_H_

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

#endif //UTILS_H_
