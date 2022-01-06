/* sprite.hpp
   =========

   interface definition for the Sprite class. Defines the behavior
   of a single asciimation sprite

 */

#ifndef SPRITE_HPP_INCLUDED
#define SPRITE_HPP_INCLUDED

#include <fstream>
#include <iostream>
#include <string>

/**
 * \class Sprite
 * \brief Holds the contents of a single ASCIImation sprite
 *
 * \details
 * Stores an array of characters that will be displayed to the screen
 *
 * \remarks
 *    The sprite *must* be the size specified by the static constants below.
 *
 */
class Sprite {
 public:
    // Size of the sprite, in characters
    static const int SPRITE_WIDTH = 40;
    static const int SPRITE_HEIGHT = 10;
    /**
     * \brief Reads a text file containing the characters for a sprite.
     * \post Should populate the sprite's character array, but doesn't yet.
     */
    Sprite(std::string fname);
    Sprite() = delete;

    char getCharAt(size_t row, size_t col) const;

 private:
    // Characters to display on the screen for this sprite
    char contents_[SPRITE_WIDTH * SPRITE_HEIGHT];
};

#endif  // ifndef SPRITE_HPP_INCLUDED
