/**
 * asciimation.cpp
 * Author(s):
 *
 * Part of CS70 Homework 3. This file may NOT be
 * shared with anyone other than the author(s) and
 * the current semester's CS70 staff without
 * explicit written permission from one of the
 * CS70 instructors.
 *
 */

#include <iostream>
#include <unistd.h>
#include <opencv2/opencv.hpp>

#include "asciimation.hpp"
#include "sprite.hpp"

using namespace std;
using namespace cv;


// declare new Asciimation with row, col stats and spriteFilename
Asciimation::Asciimation(int numRows, int numCols, int rowHeight, int colWidth,
                         string spriteFilename) :
    numRows_{numRows},
    numCols_{numCols},
    rowHeight_{rowHeight},
    colWidth_{colWidth},
    sprite_{spriteFilename},
    spriteCurrentRow_{(numRows_*rowHeight_ -
                                Sprite::SPRITE_HEIGHT*rowHeight_)/2},
    spriteCurrentCol_{-1 * Sprite::SPRITE_WIDTH*colWidth_} {
}

// function to addFrame to our current VideoWriter
void Asciimation::addFrame(VideoWriter& vw, int tc, int bc) {
    // background and text color arrays
    // colors switch every 1/3 of the movie
    const Scalar BACKGROUND_COLOR[3] = {Scalar(0, 0, 0),
                                    Scalar(255, 0, 0), Scalar(0, 0, 0)};
    const Scalar TEXT_COLOR[3] = {Scalar(255, 255, 255),
                                Scalar(0, 0, 255), Scalar(255, 0, 0)};
    const float TEXT_SCALING = 1.0;

    Mat blankImage(numRows_*rowHeight_, numCols_*colWidth_,
    COLORTYPE, BACKGROUND_COLOR[bc]);

    for (int i = 0; i < Sprite::SPRITE_HEIGHT; i ++) {
        for (int j = 0; j < Sprite::SPRITE_WIDTH; j++) {
            // get character to display
            char c = sprite_.getCharAt(i, j);

            // find position to put character
            int yPosition = spriteCurrentRow_ + i*rowHeight_;
            int xPosition = spriteCurrentCol_ + j*colWidth_;

            // put character at that position
            Point position(xPosition, yPosition);
            putText(blankImage, string(1, c), position, FONT,
             TEXT_SCALING, TEXT_COLOR[tc]);
        }
    }
    vw.write(blankImage);
}

// generate a movie from a ascii art file, and a given framerate
void Asciimation::generateMovie(const string& fname, int frameRate) {
    // declare moviesize, codec and initialize videoWriter
    Size movieSize(numCols_*colWidth_, numRows_*rowHeight_);
    int codec = VideoWriter::fourcc('m', 'p', '4', 'v');
    VideoWriter vw;
    vw.open(fname, codec, frameRate, movieSize);

    // track frames to change color every third
    int frameNumber = 0;
    int changeLength = (colWidth_*numCols_ + Sprite::SPRITE_WIDTH*colWidth_)/3;
    while (true) {
        // if completely off screen, stop adding frames
        if (spriteCurrentCol_ > colWidth_*numCols_) {
            break;
        }

        // add framce, with color changing every 3rd still
        addFrame(vw, frameNumber/changeLength, frameNumber/changeLength);
        spriteCurrentCol_ += 1;
        frameNumber += 1;
    }
    vw.release();
}
