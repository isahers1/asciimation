/**
 * \file sprite.cpp
 * \author CS70 Provided Code -- do not copy or share
 *
 * \brief Implements the Sprite class
 *
 * \details
 *
 * \remarks
 *
 */

#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <string>
#include "sprite.hpp"

using namespace std;

// declare new sprite from file called fname
Sprite::Sprite(string fname) {
    // Read in char's from file called fname
    ifstream inputFile;
    inputFile.open(fname);
    for (int i = 0; i < SPRITE_WIDTH * SPRITE_HEIGHT; i++) {
        inputFile.get(contents_[i]);
    }
}

// get the Character at position row, col in the Sprite
char Sprite::getCharAt(size_t row, size_t col) const {
    // catch out of bounds errors
    if (row >= SPRITE_HEIGHT || col >= SPRITE_WIDTH) {
        cerr << row << " " << col << endl;
        throw invalid_argument("Out of bounds!");
    } else {
        return contents_[row*SPRITE_WIDTH+col];
    }
}
